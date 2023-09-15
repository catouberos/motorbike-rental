#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>

#include "Account.h"

class Member : public Account
{
    std::string full_name_;
    std::string phone_number_;
    std::string id_type_;
    std::string id_number_;
    std::string license_number_;
    std::string expiry_date_;

    double rating_;

    unsigned int credit_point_;

    unsigned int owned_motorbike_id_;
    unsigned int rented_motorbike_id_;

public:
    Member(unsigned int id,
           std::string username,
           std::string password,
           std::string full_name,
           std::string phone_number,
           std::string id_type,
           std::string id_number,
           std::string license_number,
           std::string expiry_date,
           unsigned int credit_point,
           unsigned int owned_motorbike_id,
           unsigned int rented_motorbike_id);

    std::string getFullName();

    std::string toString() override;
    std::string serialize() override;

    friend class MemberManager;
};

#endif
