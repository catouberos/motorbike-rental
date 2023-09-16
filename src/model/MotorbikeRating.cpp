#include <sstream>

#include "MotorbikeRating.h"

MotorbikeRating::MotorbikeRating(Member *renter, Motorbike *motorbike, double rating, std::string review)
    : renter{renter}, motorbike{motorbike}, rating_{rating}, review_{review} {}

std::string MotorbikeRating::toString() {
    std:std::ostringstream oss;

    oss << "Rating from " << renter->getFullName() << std::endl
        << "Rating: " << rating_ << std::endl
        << "Review: " << review_ << std::endl;

    return oss.str();
}

std::string MotorbikeRating::serialize() {
    std::ostringstream oss;

    oss << renter->id_ << ","
        << motorbike->id_ << ","
        << rating_ << ","
        << review_;

    return oss.str();
}
