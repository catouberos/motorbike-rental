#include <sstream>
#include <string>

#include "Member.h"

//Class constructor
Member::Member(unsigned int id,
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
               Motorbike *rented_motorbike)
    : Account(id, username, password), full_name_(full_name),
      phone_number_(phone_number), id_type_(id_type), id_number_(id_number),
      license_number_(license_number), expiry_date_(expiry_date),
      credit_point_(credit_point), owned_motorbike_(owned_motorbike),
      rented_motorbike_(rented_motorbike){};

//set the owned motorbike for a member
bool Member::setOwnedMotorbike(Motorbike *motorbike)
{
    owned_motorbike_ = motorbike;
    return true;
}

//set the rented motorbike for a member
bool Member::setRentedMotorbike(Motorbike *motorbike)
{
    rented_motorbike_ = motorbike;
    return true;
}

//returns the full name of the member as a string
std::string Member::getFullName()
{
    return full_name_;
}

//returns the credit points of the member
unsigned int Member::getCreditPoint()
{
    return credit_point_;
}

//returns a pointer to the owned motorbike by the member
Motorbike *Member::getOwnedMotorbike()
{
    return owned_motorbike_;
}

//returns a pointer to the rented motorbike by the member
Motorbike *Member::getRentedMotorbike()
{
    return rented_motorbike_;
}

//add credit points to the member's account
bool Member::topUp(unsigned int amount)
{
    if (amount < 0)
    {
        return false;
    }

    credit_point_ += amount;
    return true;
}

//returns a human-readable string representation.
std::string Member::toString(bool detailed)
{
    std::ostringstream oss;

    if (detailed)
    {
        oss << "ID: " << id_ << std::endl
            << "Username: " << username_ << std::endl
            << "Full name: " << full_name_ << std::endl
            << "Phone number: " << phone_number_ << std::endl
            << "ID type: " << id_type_ << std::endl
            << "ID number: " << id_number_ << std::endl
            << "License number: " << license_number_ << std::endl
            << "Expiry date: " << expiry_date_ << std::endl
            << "Credit point: " << credit_point_ << std::endl;

        if (owned_motorbike_ != nullptr)
        {
            oss << "Owned motorbike: " << std::endl
                << owned_motorbike_->toString(detailed) << std::endl;
        }
        else
        {
            oss << "Currently not owning any motorbike" << std::endl;
        }

        if (rented_motorbike_ != nullptr)
        {
            oss << "Rented motorbike: " << std::endl
                << rented_motorbike_->toString(detailed) << std::endl;
        }
        else
        {
            oss << "Currently not renting any motorbike" << std::endl;
        }
    }
    else
    {
        oss << "ID: " << id_ << std::endl
            << "Username: " << username_ << std::endl
            << "Full name: " << full_name_ << std::endl
            << "Phone number: " << phone_number_ << std::endl;
    }

    return oss.str();
}

//returns a string representation suitable for storage.
std::string Member::serialize()
{
    return std::to_string(id_) + ',' +
           username_ + ',' +
           password_ + ',' +
           full_name_ + ',' +
           phone_number_ + ',' +
           id_type_ + ',' +
           id_number_ + ',' +
           license_number_ + ',' +
           expiry_date_ + ',' +
           std::to_string(credit_point_) + ',' +
           (owned_motorbike_ != nullptr ? std::to_string(owned_motorbike_->id_) : "0") + ',' +
           (rented_motorbike_ != nullptr ? std::to_string(rented_motorbike_->id_) : "0");
}
