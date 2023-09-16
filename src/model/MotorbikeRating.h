#ifndef MOTORBIKE_RATING_
#define MOTORBIKE_RATING_

#include <string>

#include "Member.h"
#include "Motorbike.h"

class MotorbikeRating {
    Member *renter;
    Motorbike *motorbike;
    double rating_;
    std::string review_;

public:
    MotorbikeRating(Member *renter, Motorbike *motorbike, double rating, std::string review);

    std::string toString();
    std::string serialize();

    friend class MotorbikeRatingManager;
};

#endif
