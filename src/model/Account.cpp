#include <sstream>

#include "Account.h"

Account::Account(unsigned int id, std::string username, std::string password)
    : Entity(id), username_(username), password_(password) {}

std::string Account::toString()
{
    std::ostringstream oss;

    oss << "Username: " << username_ << std::endl
        << "Password: " << password_;

    return oss.str();
}

std::string Account::serialize()
{
    return username_ + "," + password_;
}
