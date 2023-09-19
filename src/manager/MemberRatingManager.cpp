#include "MemberRatingManager.h"

#include <fstream>

//Class constructor
MemberRatingManager::MemberRatingManager() {}

//Class destructor
MemberRatingManager::~MemberRatingManager()
{
    for (MemberRating *rating : ratings_)
    {
        delete rating;
    }
}

//add a MemberRating object to the ratings_ vector.
bool MemberRatingManager::add(MemberRating *rating)
{
    ratings_.push_back(rating);

    return true;
}

//returns a vector containing pointers to all the MemberRating objects managed by the MemberRatingManager. 
std::vector<MemberRating *> MemberRatingManager::getRatings()
{
    return ratings_;
}

//calculates and returns the average rating for a member with the specified member_id.
double MemberRatingManager::getAverageRating(unsigned int member_id)
{
    double total_rating = 0;
    int count = 0;

    for (MemberRating *rating : ratings_)
    {
        if (rating->member->id_ == member_id)
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

//returns a vector containing pointers to MemberRating objects associated with a member specified by their id 
std::vector<MemberRating *> MemberRatingManager::getRatingsByOwnerId(unsigned int id)
{
    std::vector<MemberRating *> ratings;

    for (MemberRating *rating : ratings_)
    {
        if (rating->owner->id_ == id)
        {
            ratings.push_back(rating);
        }
    }

    return ratings;
}

//returns a vector containing pointers to MemberRating objects associated with a member specified by their id 
std::vector<MemberRating *> MemberRatingManager::getRatingsByMemberId(unsigned int id)
{
    std::vector<MemberRating *> ratings;

    for (MemberRating *rating : ratings_)
    {
        if (rating->member->id_ == id)
        {
            ratings.push_back(rating);
        }
    }

    return ratings;
}

//initialize the MemberRatingManager by loading member rating data from a file.
//Return ‘true’ if the operation is successful.
bool MemberRatingManager::init(MemberManager &memberManager)
{
    if (ratings_.size() > 0)
    {
        return false;
    }

    std::ifstream file;
    file.open("customer_rating.dat", std::ios::in);

    if (!file)
    {
        return false;
    }

    while (file.peek() != EOF)
    {
        std::string ownerId;
        std::string renterId;
        std::string rating;
        std::string review;

        std::getline(file, ownerId, ',');
        std::getline(file, renterId, ',');
        std::getline(file, rating, ',');
        std::getline(file, review, '\n');

        Member *owner = memberManager.getMemberFromId(std::stoi(ownerId));
        Member *member = memberManager.getMemberFromId(std::stoi(renterId));

        if (owner == nullptr || member == nullptr)
        {
            // member does not exist
            break;
        }

        MemberRating *memberRating = new MemberRating(
            owner,
            member,
            std::stod(rating),
            review);

        add(memberRating);
    }

    file.close();

    return true;
}

//Save current state of the member rating data to a file.
bool MemberRatingManager::save()
{
    std::ofstream file;

    file.open("customer_rating.dat", std::ios::out);

    if (!file)
    {
        return false;
    }

    for (MemberRating *rating : ratings_)
    {
        file << rating->serialize() << std::endl;
    }

    file.close();

    return true;
}
