#ifndef MOTORBIKE_MANAGER_H_
#define MOTORBIKE_MANAGER_H_

#include <vector>

#include "../model/Motorbike.h"

class MotorbikeManager
{
    std::vector<Motorbike> motorbikes_;

public:
    MotorbikeManager();

    bool add(Motorbike motorbike);

    std::vector<Motorbike> getMotorbikes();

    unsigned int getUnusedId();

    Motorbike registerMotorbike(
        std::string model,
        std::string color,
        std::string engine_size,
        std::string transmission_mode,
        unsigned int year_made_,
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
