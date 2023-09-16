#ifndef MOTORBIKE_MANAGER_H_
#define MOTORBIKE_MANAGER_H_

#include <vector>

#include "../model/Motorbike.h"

class MotorbikeManager
{
    std::vector<Motorbike *> motorbikes_;

public:
    MotorbikeManager();

    ~MotorbikeManager();

    bool add(Motorbike *motorbike);

    std::vector<Motorbike *> getMotorbikes();

    unsigned int getUnusedId();

    Motorbike *getMotorbikeFromId(unsigned int id);

    Motorbike *registerMotorbike(
        unsigned int owner_id,
        std::string model,
        std::string color,
        std::string engine_size,
        std::string transmission_mode,
        unsigned int year_made,
        std::string description,
        double required_rating,
        unsigned int point_consume,
        std::string location);

    // load from file
    bool init();

    // save to file
    bool save();
};

#endif
