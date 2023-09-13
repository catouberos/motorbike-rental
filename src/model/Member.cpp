#include <sstream>

#include "Member.h"

Member::Member(unsigned int id, std::string username, std::string password)
    : Account(id, username, password) {}

Member::Member(unsigned int id,
               std::string username,
               std::string password,
               std::string full_name,
               std::string phone_number,
               std::string id_type,
               std::string id_number,
               std::string license_number,
               std::string expiry_date)
    : Account(id, username, password), full_name_(full_name),
      phone_number_(phone_number), id_type_(id_type), id_number_(id_number),
      license_number_(license_number), expiry_date_(expiry_date){};

std::string Member::toString()
{
    std::ostringstream oss;

    oss << "Member ID: " << id_ << std::endl
        << "fullname: " << full_name_ << std::endl
        << "ID type: " << id_type_ << std::endl
        << "ID number: " << id_number_ << std::endl
        << "License number: " << license_number_ << std::endl
        << "Credit point: " << credit_point_ << std::endl
        << "Renter rating: " << renter_rating_ << std::endl;

    return oss.str();
}

std::string Member::serialize()
{
    return username_ + ',' +
           password_ + ',' +
           full_name_ + ',' +
           id_type_ + ',' +
           id_number_ + ',' +
           license_number_ + ',' +
           std::to_string(credit_point_) + ',' +
           std::to_string(renter_rating_) + ',' +
           std::to_string(owned_motorbike_->id_) + ',' +
           std::to_string(rented_motorbike_->id_) + ',' +
           std::to_string(id_) + '\n';
}