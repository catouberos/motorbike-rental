#include <ostream>
#include <string>
#include <sstream>

#include "Motorbike.h"

//Class constructor
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
    unsigned int renter_id) : Entity(id), model_(model),
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

//returns the start date of when the motorbike is rented as a Date object.
Date Motorbike::getStartDate()
{
    return start_date_;
}

//returns the end date of when the motorbike is rented as a Date object.
Date Motorbike::getEndDate()
{
    return end_date_;
}

//returns the ID of the member who is renting the motorbike.
unsigned int Motorbike::getRenterId()
{
    return renter_id_;
}

//set the motorbike as available for rent.
bool Motorbike::setList(Date start_date, Date end_date, unsigned int point_consume, double required_rating)
{
    start_date_ = start_date;
    end_date_ = end_date;
    point_consume_ = point_consume;
    required_rating_ = required_rating;

    return true;
}

//mark the motorbike as unavailable for rent
bool Motorbike::setUnlist()
{
    if (renter_id_ == 0)
    {
        throw 400;
    }

    start_date_ = Date(0, 0, 0);
    end_date_ = Date(0, 0, 0);
    point_consume_ = 0;
    required_rating_ = 0;

    return true;
}

//set the ID of the member who is renting the motorbike.
bool Motorbike::setRenterId(unsigned int renter_id)
{
    renter_id_ = renter_id;

    return true;
}

//returns the number of points consumed for renting the motorbike
unsigned int Motorbike::getPointConsumed()
{
    return point_consume_;
}

//returns the required rating for renting the motorbike.
double Motorbike::getRequiredRating()
{
    return required_rating_;
}

//returns the location of the motorbike as a string.
std::string Motorbike::getLocation()
{
    return location_;
}

//returns a human-readable string representation.
std::string Motorbike::toString(bool detailed)
{
    std::ostringstream oss;

    if (detailed)
    {
        oss << "ID: " << id_ << std::endl
            << "Owner ID: " << owner_id_ << std::endl
            << "Model: " << model_ << std::endl
            << "Color: " << color_ << std::endl
            << "Engine size: " << engine_size_ << std::endl
            << "Transmission mode: " << transmission_mode_ << std::endl
            << "Year made: " << year_made_ << std::endl
            << "Description: " << description_ << std::endl
            << "Motorbike Rating: " << rating_ << std::endl
            << "Required renter rating: " << required_rating_ << std::endl
            << "Consuming point: " << point_consume_ << std::endl
            << "Location: " << location_ << std::endl;
        if (renter_id_ != 0)
        {
            oss << "Renter ID: " << renter_id_ << std::endl
                << "Rented from: " << start_date_.toString() << std::endl
                << "Rented to: " << end_date_.toString() << std::endl;
        }
    }
    else
    {
        oss << "ID: " << id_ << std::endl
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
            << std::endl;

        if (renter_id_ != 0)
        {
            oss << "Currently being rented by " << renter_id_ << std::endl;
        }
        else if (start_date_.getDay() != 0)
        {
            oss << "Available for rent" << std::endl;
        }
    }

    return oss.str();
}

//returns a string representation suitable for storage.
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
           start_date_.serialize() + ',' +
           end_date_.serialize() + ',' +
           std::to_string(owner_id_) + ',' +
           std::to_string(renter_id_);
}
