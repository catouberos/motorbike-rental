#include <string>
#include <sstream>

#include "Motorbike.h"

Motorbike::Motorbike(
        unsigned int id,
        std::string model,
        std::string color,
        std::string engine_size,
        std::string transmission_mode,
        unsigned int year_made,
        std::string description,
        double required_rating,
        unsigned int point_consume,
        std::string location,
        Date start_date,
        Date end_date,
        unsigned int owner_id,
        unsigned int renter_id): Entity(id), model_(model),
        color_(color), engine_size_(engine_size),
        transmission_mode_(transmission_mode), 
        year_made_(year_made),
        description_(description),
        required_rating_(required_rating),
        point_consume_(point_consume),
        location_(location),
        start_date_(start_date),
        end_date_(end_date), 
        owner_id_(owner_id),
        renter_id_(renter_id){};

std::string Motorbike::toString()
{
    std::ostringstream oss;

    oss << "Motorbike ID: " << id_ << std::endl
        << "Owner ID: " << owner_id_ << std::endl
        << "Renter ID: " << renter_id_ << std::endl
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
        << "Available from: " << start_date_.toString() << std::endl
        << "Available to: " << end_date_.toString() << std::endl;

    return oss.str();
}

std::string Motorbike::serialize()
{
    return std::to_string(id_) + ',' +
           model_ + ',' +
           color_ + ',' +
           engine_size_ + ',' +
           transmission_mode_ + ',' +
           std::to_string(year_made_) + ',' +
           description_ + ',' +
           std::to_string(required_rating_) + ',' +
           std::to_string(point_consume_) + ',' +
           location_ + ',' +
           start_date_.toString() + ',' +
           end_date_.toString() + ',' +
           std::to_string(owner_id_) + ',' +
           std::to_string(renter_id_);
}

