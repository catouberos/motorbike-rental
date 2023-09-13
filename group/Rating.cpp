#include "Rating.h"

void RenterRating::printRenterRating()
{
    std::cout << "From member ID: " << m_ownerID << '\n';
    std::cout << "Rate: " << m_rating << '\n';
    std::cout << "Review: " << m_review << '\n';
}

std::string RenterRating::toFile()
{
    return m_review + ',' + std::to_string(m_rating) + ',' + std::to_string(m_ownerID) + ',' + std::to_string(m_renterID) + '\n';
}

void MotorbikeRating::printMotorRating()
{
    std::cout << "From member ID:" << m_renterID << '\n';
    std::cout << "Rate: " << m_rating << "\n";
    std::cout << "Review: " << m_review << '\n';
}

std::string MotorbikeRating::toFile()
{
    return m_review + ',' + std::to_string(m_rating) + ',' + std::to_string(m_motorbikeID) + ',' + std::to_string(m_renterID) + '\n';
}