#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Date.h"
#ifndef MOTORBIKE_H
#define MOTORBIKE_H
class Motorbike
{
    std::string m_model{""};
    std::string m_color{""};
    int m_engineSize{};
    std::string m_transmissionMode{""};
    int m_yearMade{};
    std::string m_description{""};
    double m_motorbikeRating{5};
    double m_requiredRating{0};
    int m_consumingPoint{};
    std::string m_location{""};
    Date m_startDate{};
    Date m_endDate{};
    int m_motorbikeID{0};
    int m_ownerID{0};
    int m_renterID{0};

public: 
    Motorbike() = default;
    Motorbike
    (
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
        int renterID
    )
    :m_model{model}, m_color{color}
        , m_engineSize{engineSize}, m_transmissionMode{transmissionMode}
        , m_yearMade{yearMade}, m_description{description}
        , m_requiredRating{requiredRating}, m_consumingPoint{consumingPoint}
        , m_location{location}, m_startDate{startdate}
        , m_endDate{enddate}, m_motorbikeID{motorbikeID}
        , m_ownerID{ownerID}, m_motorbikeRating{motorbikeRating}, m_renterID{renterID}{}

    friend class Member;
    friend class System;

    void printMotorbike();
    
    std::string toFile();
};
#endif