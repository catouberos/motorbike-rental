#include "Account.h"
void Account::printAccount()
{
    std::cout << "Username: " << m_username << '\n';
    std::cout << "password: " << m_password << '\n';
}

void Member::printMember()
{
    std::cout << "Member ID: " << m_memberID << '\n';
    std::cout << "fullname: " << m_fullName << '\n';
    std::cout << "ID type: " << m_idType << '\n';
    std::cout << "ID number: " << m_idNumber << '\n';
    std::cout << "License number: " << m_licenseNumber << '\n';
    std::cout << "Credit point: " << m_creditPoint << '\n';
    std::cout << "Renter rating: " << m_renterRating << '\n';
}

void Member::printMemberAdmin()
{
    Account::printAccount();
    std::cout << "Member ID: " << m_memberID << '\n';
    std::cout << "fullname: " << m_fullName << '\n';
    std::cout << "ID type: " << m_idType << '\n';
    std::cout << "ID number: " << m_idNumber << '\n';
    std::cout << "License number: " << m_licenseNumber << '\n';
    std::cout << "Credit point: " << m_creditPoint << '\n';
    std::cout << "Renter rating: " << m_renterRating << '\n';
}

std::string Member::toFile()
{
    return Account::m_username + ',' + Account::m_password + ',' + m_fullName + ',' + m_idType + ',' + std::to_string(m_idNumber) + ','
        + std::to_string(m_licenseNumber) + ',' + std::to_string(m_creditPoint) + ',' + std::to_string(m_renterRating) + ','
        + std::to_string(m_ownMotorbikeID) + ',' + std::to_string(m_rentMotorbikeID) + ',' + std::to_string(m_memberID) + '\n';
}