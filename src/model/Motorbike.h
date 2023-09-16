#ifndef MOTORBIKE_H_
#define MOTORBIKE_H_

#include <string>

#include "Date.h"
#include "Entity.h"

class Motorbike : public Entity
{
    std::string model_;
    std::string color_;
    std::string engine_size_;
    std::string transmission_mode_;
    unsigned int year_made_;
    std::string description_;

    double rating_{0.0};
    double required_rating_;
    unsigned int point_consume_;
    std::string location_;
    Date start_date_;
    Date end_date_;

    unsigned int owner_id_;
    unsigned int renter_id_;

public:
    Motorbike(
        unsigned int id,
        std::string model,
        std::string color,
        std::string engine_size,
        std::string transmission_mode,
        unsigned int year_made_,
        std::string description,
        double required_rating,
        unsigned int point_consume,
        std::string location,
        Date start_date,
        Date end_date,
        unsigned int owner_id,
        unsigned int renter_id);
    
    Date getStartDate();
    Date getEndDate();
    unsigned int getRenterId();
    unsigned int getPointConsumed();
    double getRequiredRating();
    std::string getLocation();

    bool setList(Date start_date, Date end_date, unsigned int point_consume, double required_rating);
    bool setUnlist();
    bool setRenterId(unsigned int renter_id);

    std::string toString(bool detailed = false) override;

    std::string serialize() override;

    friend class MotorbikeManager;
};

#endif
