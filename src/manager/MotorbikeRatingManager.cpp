#include <fstream>
#include <vector>

#include "MotorbikeRatingManager.h"

//Class constructor
MotorbikeRatingManager::MotorbikeRatingManager() {}

//Class destructor
MotorbikeRatingManager::~MotorbikeRatingManager()
{
    for (MotorbikeRating *rating : ratings_)
    {
        delete rating;
    }
}

//add a MotorbikeRating object to the ratings_ vector.
bool MotorbikeRatingManager::add(MotorbikeRating *rating)
{
    ratings_.push_back(rating);

    return true;
}

//returns a vector containing pointers to all the MotorbikeRating objects managed by the MotorbikeRatingManager
std::vector<MotorbikeRating *> MotorbikeRatingManager::getRatings()
{
    return ratings_;
}

//calculates and returns the average rating for a motorbike with the specified motorbike_id
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

//returns a vector containing pointers to MotorbikeRating objects associated with a motorbike specified by its id.
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

//returns a vector containing pointers to MotorbikeRating objects associated with a renter specified by their id.
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

//initialize the MotorbikeRatingManager by loading motorbike rating data from a file.
//Return ‘true’ if the operation is successful
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

//save the current state of the motorbike rating data to a file.
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
