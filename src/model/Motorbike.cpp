#include <string>
#include <sstream>

#include "Motorbike.h"

std::string Motorbike::toString()
{
    std::ostringstream oss;

    oss << "Motorbike ID: " << id_ << std::endl
        << "Owner ID: " << owner_->id_ << std::endl
        << "Renter ID: " << renter_->id_ << std::endl
        << "Model: " << model_ << std::endl
        << "Color: " << color_ << std::endl
        << "Engine size: " << engine_size_ << std::endl
        << "Transmission mode: " << transmission_mode_ << std::endl
        << "Year made: " << year_made_ << std::endl
        << "Description: " << description_ << std::endl
        << "Motorbike Rating: " << rating_ << std::endl
        << "Required renter rating: " << required_rating_ << std::endl
        << "Consuming point: " << point_consume_ << std::endl
        << "Location: " << location_ << std::endl
        << "Available from:";

    return oss.str();
}

std::string Motorbike::serialize()
{
    return model_ + ',' +
           color_ + ',' +
           transmission_mode_ + ',' +
           description_ + ',' +
           location_ + ',' +
           engine_size_ + ',' +
           std::to_string(year_made_) + ',' +
           std::to_string(rating_) + ',' +
           std::to_string(required_rating_) + ',' +
           std::to_string(point_consume_) + ',' +
           start_date_.toString() + ',' +
           end_date_.toString() + ',' +
           std::to_string(id_) + ',' +
           std::to_string(owner_->id_) + ',' +
           std::to_string(renter_->id_);
}