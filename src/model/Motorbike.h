#ifndef MOTORBIKE_H_
#define MOTORBIKE_H_

#include <string>

#include "Date.h"
#include "Member.h"

class Motorbike : public Entity
{

protected:
    std::string model_;
    std::string color_;
    std::string engine_size_;
    std::string transmission_mode_;
    unsigned int year_made_;
    std::string description_;

    double rating_;
    double required_rating_;
    unsigned int point_consume_;
    std::string location_;
    Date start_date_;
    Date end_date_;

    Member *owner_;
    Member *renter_;

public:
    Motorbike(
        std::string model,
        std::string color,
        int engineSize,
        std::string transmissionMode,
        int yearMade,
        std::string description,
        double requiredRating,
        int consumingPoint,
        std::string location,
        Date startdate,
        Date enddate,
        int ownerID,
        int motorbikeID,
        double motorbikeRating,
        int renterID);

    std::string toString() override;

    std::string serialize() override;
};

#endif