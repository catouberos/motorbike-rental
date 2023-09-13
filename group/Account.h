#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account
{
    std::string m_username{""};
    std::string m_password{""};

public:
    Account() = default;
    Account(std::string username, std::string password) 
        :m_username{username}, m_password{password}{}
    
    void printAccount();
    friend class System;
    friend class Member;

};

class Member: public Account
{   
    int m_memberID{};
    std::string m_fullName{""};
    std::string m_idType{""};
    int m_idNumber{};
    int m_licenseNumber{};
    int m_creditPoint{};
    int m_ownMotorbikeID{};
    int m_rentMotorbikeID{};
    double m_renterRating{};

public:
    Member() = default;
    Member
    (
        std::string username,
        std::string password,
        std::string fullName,
        std::string idType,
        int idNumber,
        int licenseNumber,
        int creditPoint,
        double renterRating,
        int ownMotorbikeID,
        int rentMotorbikeID,
        int memberID 
    )
    : Account{username, password}
        , m_fullName{fullName}, m_idType{idType}
        , m_idNumber{idNumber}, m_licenseNumber{licenseNumber}
        , m_creditPoint{creditPoint}, m_ownMotorbikeID{ownMotorbikeID}
        , m_renterRating{renterRating}, m_rentMotorbikeID{rentMotorbikeID}, m_memberID{memberID}{}

    friend class System;
 

    void printMember();

    void printMemberAdmin();

    std::string toFile();

};
#endif