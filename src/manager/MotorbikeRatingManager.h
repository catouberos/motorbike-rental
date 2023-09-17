#ifndef MOTORBIKE_RATING_MANAGER_H_
#define MOTORBIKE_RATING_MANAGER_H_

#include <vector>
#include <string>

#include "../model/MotorbikeRating.h"
#include "MotorbikeManager.h"
#include "MemberManager.h"

class MotorbikeRatingManager
{
    std::vector<MotorbikeRating *> ratings_;

public:
    MotorbikeRatingManager();
    ~MotorbikeRatingManager();

    bool add(MotorbikeRating *rating);

    double getAverageRating(unsigned int motorbike_id);

    std::vector<MotorbikeRating *> getRatings();

    std::vector<MotorbikeRating *> getRatingsByMotorbikeId(unsigned int id);

    std::vector<MotorbikeRating *> getRatingsByRenterId(unsigned int id);

    bool init(MotorbikeManager &motorbikeManager, MemberManager &memberManager);

    bool save();
};

#endif
