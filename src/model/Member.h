#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>

#include "Account.h"
#include "Motorbike.h"

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

    Motorbike *owned_motorbike_ = nullptr;
    Motorbike *rented_motorbike_ = nullptr;

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
           Motorbike *owned_motorbike,
           Motorbike *rented_motorbike);

    bool setOwnedMotorbike(Motorbike *motorbike);

    std::string getFullName();
    unsigned int getCreditPoint();
    Motorbike *getOwnedMotorbike();
    Motorbike *getRentedMotorbike();

    bool topUp(unsigned int amount);

    std::string toString(bool detailed = false) override;
    std::string serialize() override;

    friend class MemberManager;
};

#endif
