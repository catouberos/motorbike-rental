#pragma once
#ifndef MOTORBIKE_H_
#define MOTORBIKE_H_

#include <string>
#include "Entity.h"

class Motorbike: public Entity {
    private:
        std::string model;
        std::string color;
        std::string engine_size;
        std::string transmission_mode;
        unsigned int year_made;
        std::string description;

    public:
        Motorbike(int id);

        Motorbike(std::string model = "", 
                std::string color = "",
                std::string engine_size = "",
                std::string transmission_mode = "",
                unsigned int year_made = 2023,
                std::string description = "");
};

#endif
