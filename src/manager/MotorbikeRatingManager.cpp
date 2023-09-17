#include <fstream>
#include <vector>

#include "MotorbikeRatingManager.h"

MotorbikeRatingManager::MotorbikeRatingManager() {}

MotorbikeRatingManager::~MotorbikeRatingManager()
{
    for (MotorbikeRating *rating : ratings_)
    {
        delete rating;
    }
}

bool MotorbikeRatingManager::add(MotorbikeRating *rating)
{
    ratings_.push_back(rating);

    return true;
}

std::vector<MotorbikeRating *> MotorbikeRatingManager::getRatings()
{
    return ratings_;
}

double MotorbikeRatingManager::getAverageRating(unsigned int motorbike_id)
{
    double total_rating = 0;
    int count = 0;

    for (MotorbikeRating *rating : ratings_)
    {
        if (rating->motorbike->id_ == motorbike_id)
        {
            total_rating += rating->rating_;
            count++;
        }
    }

    if (count == 0)
    {
        return 0;
    }

    return total_rating / count;
}

std::vector<MotorbikeRating *> MotorbikeRatingManager::getRatingsByMotorbikeId(unsigned int id)
{
    std::vector<MotorbikeRating *> ratings;

    for (MotorbikeRating *rating : ratings_)
    {
        if (rating->motorbike->id_ == id)
        {
            ratings.push_back(rating);
        }
    }

    return ratings;
}

std::vector<MotorbikeRating *> MotorbikeRatingManager::getRatingsByRenterId(unsigned int id)
{
    std::vector<MotorbikeRating *> ratings;

    for (MotorbikeRating *rating : ratings_)
    {
        if (rating->renter->id_ == id)
        {
            ratings.push_back(rating);
        }
    }

    return ratings;
}

bool MotorbikeRatingManager::init(MotorbikeManager &motorbikeManager, MemberManager &memberManager)
{
    if (ratings_.size() > 0)
    {
        return false;
    }

    std::ifstream file;
    file.open("motorbike_rating.dat", std::ios::in);

    if (!file)
    {
        return false;
    }

    while (file.peek() != EOF)
    {
        std::string renterId;
        std::string motorbikeId;
        std::string rating;
        std::string review;

        std::getline(file, renterId, ',');
        std::getline(file, motorbikeId, ',');
        std::getline(file, rating, ',');
        std::getline(file, review, '\n');

        Member *renter = memberManager.getMemberFromId(std::stoi(renterId));
        Motorbike *motorbike = motorbikeManager.getMotorbikeFromId(std::stoi(motorbikeId));

        if (renter == nullptr || motorbike == nullptr)
        {
            // renter or motorbike not exist
            break;
        }

        MotorbikeRating *motorbikeRating = new MotorbikeRating(
            renter,
            motorbike,
            std::stod(rating),
            review);

        add(motorbikeRating);
    }

    file.close();

    return true;
}

bool MotorbikeRatingManager::save()
{
    std::ofstream file;
    file.open("motorbike_rating.dat", std::ios::out);

    if (!file)
    {
        return false;
    }

    for (MotorbikeRating *rating : ratings_)
    {
        file << rating->renter->id_ << ","
             << rating->motorbike->id_ << ","
             << rating->rating_ << ","
             << rating->review_ << std::endl;
    }

    file.close();

    return true;
}
