#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>

#include "Account.h"
#include "Motorbike.h"

class Member : public Account
{
protected:
    std::string full_name_;
    std::string phone_number_;
    std::string id_type_;
    std::string id_number_;
    std::string license_number_;
    std::string expiry_date_;

    unsigned int credit_point_;
    double renter_rating_;

    Motorbike *owned_motorbike_;
    Motorbike *rented_motorbike_;

public:
    Member(unsigned int id, std::string username, std::string password);
    Member(unsigned int id,
           std::string username,
           std::string password,
           std::string full_name,
           std::string phone_number,
           std::string id_type,
           std::string id_number,
           std::string license_number,
           std::string expiry_date);

    std::string toString() override;
    std::string serialize() override;

    friend class System;
};

#endif