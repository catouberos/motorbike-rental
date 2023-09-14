#include <iostream>
#include <fstream>

#include "MotorbikeManager.h"

MotorbikeManager::MotorbikeManager() {};

bool MotorbikeManager::add(Motorbike motorbike) {
    motorbikes_.push_back(motorbike);

    return true;
}

std::vector<Motorbike> MotorbikeManager::getMotorbikes() {
    return motorbikes_;
}

unsigned int MotorbikeManager::getUnusedId() {
    return motorbikes_.size() + 1;
}

Motorbike MotorbikeManager::registerMotorbike(
        std::string model,
        std::string color,
        std::string engine_size,
        std::string transmission_mode,
        unsigned int year_made_,
        std::string description,
        double required_rating,
        unsigned int point_consume,
        std::string location) {
    Motorbike motorbike(getUnusedId(), model, color, engine_size, transmission_mode, year_made_, description, required_rating, point_consume, location, Date(), Date(), 0, 0);

    motorbikes_.push_back(motorbike);

    return motorbike;
}

// very likely to break if is not serialize properly
bool MotorbikeManager::init() {
    // check: only allow loading when initialize, where member list is empty
    if (motorbikes_.size() > 0) {
        return false;
    }

    std::fstream file;
    file.open("motorbike.dat", std::ios::in);

    // check: file not exist, likely first run
    if (!file)
    {
        return false;
    }

    // parse format:
    // id,model,color,engine_size,transmission_mode,year_made,description,required_rating,point_consume,location,available_from,available_to,owner_id,renter_id
    while (file.peek() != EOF)
    {
        std::string id;
        std::string model;
        std::string color;
        std::string engine_size;
        std::string transmission_mode;
        std::string year_made;
        std::string description;
        std::string required_rating;
        std::string point_consume;
        std::string location;
        std::string available_from;
        std::string available_to;
        std::string owner_id;
        std::string renter_id;

        std::getline(file, id, ',');
        std::getline(file, model, ',');
        std::getline(file, color, ',');
        std::getline(file, engine_size, ',');
        std::getline(file, transmission_mode, ',');
        std::getline(file, year_made, ',');
        std::getline(file, description, ',');
        std::getline(file, required_rating, ',');
        std::getline(file, point_consume, ',');
        std::getline(file, location, ',');
        std::getline(file, available_from, ',');
        std::getline(file, available_to, ',');
        std::getline(file, owner_id, ',');
        std::getline(file, renter_id, '\n');

        Motorbike motorbike(std::stoi(id), model, color, engine_size, transmission_mode, std::stoi(year_made), description, std::stod(required_rating), std::stoi(point_consume), location, Date(available_from), Date(available_to), std::stoi(owner_id), std::stoi(renter_id));

        add(motorbike);
    }

    file.close();

    return true;
}

bool MotorbikeManager::save() {
    std::ofstream file;

    file.open("motorbike.dat", std::ios::out);
    
    if (!file)
    {
        return false;
    }

    for (Motorbike motorbike : motorbikes_) 
    {
        file << motorbike.serialize() << std::endl;
    }

    file.close();

    return true;
}
