#include <string>
#include <iostream>
#ifndef RATING_H
#define RATING_H
class MotorbikeRating
{
    int m_renterID{};
    int m_motorbikeID{};
    double m_rating{};
    std::string m_review{""};

public:
    MotorbikeRating(int renterID, int motorbikeID, double rating, std::string review)
        :m_renterID{renterID}, m_motorbikeID{motorbikeID}, m_rating{rating}, m_review{review}{} 

    void printMotorRating();

    std::string toFile();

    friend class System;
};

class RenterRating
{
    int m_ownerID{};
    int m_renterID{};
    double m_rating{};
    std::string m_review{""};

public:
    RenterRating(int ownerID, int renterID, double rating, std::string review)
        :m_ownerID{ownerID}, m_renterID{renterID}, m_rating{rating}, m_review{review}{} 

    void printRenterRating();
    
    std::string toFile();

    friend class System;

};
#endif