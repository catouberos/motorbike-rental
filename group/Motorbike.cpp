#include "Motorbike.h"
void Motorbike::printMotorbike()
{
    std::cout << "Motorbike ID: " << m_motorbikeID << '\n';
    std::cout << "Owner ID: " << m_ownerID << '\n';
    std::cout << "Renter ID: " << m_renterID << '\n';
    std::cout << "Model: " << m_model << '\n';
    std::cout << "Color: " << m_color << '\n';
    std::cout << "Engine size: " << m_engineSize << '\n';
    std::cout << "Transmission mode: " << m_transmissionMode << '\n';
    std::cout << "Year made: " << m_yearMade << '\n';
    std::cout << "Description: " << m_description << '\n';
    std::cout << "Motorbike Rating: " << m_motorbikeRating << '\n';
    std::cout << "Required renter rating: " << m_requiredRating << '\n';
    std::cout << "Consuming point: " << m_consumingPoint << '\n';
    std::cout << "Location: " << m_location << "\n";
    std::cout << "Available from:\n";
    m_startDate.printDate();
    std::cout << " to " << "\n";
    m_endDate.printDate();
    std::cout << "\n";
}

std::string Motorbike::toFile()
{
    return m_model + ',' + m_color + ',' + m_transmissionMode + ',' + m_description + ',' + m_location + ',' + std::to_string(m_engineSize) + ','
        + std::to_string(m_yearMade) + ',' + std::to_string(m_motorbikeRating) + ',' + std::to_string(m_requiredRating) + ',' + std::to_string(m_consumingPoint) + ','
        + std::to_string(m_startDate.m_day) + ',' + std::to_string(m_startDate.m_month) + ',' + std::to_string(m_startDate.m_year) + ','
        + std::to_string(m_endDate.m_day) + ',' + std::to_string(m_endDate.m_month) + ',' + std::to_string(m_endDate.m_year) + ','
        + std::to_string(m_motorbikeID) + ',' + std::to_string(m_ownerID) + ',' + std::to_string(m_renterID) + '\n';
}