#include <sstream>

#include "Account.h"

//Class constructor
Account::Account(unsigned int id, std::string username, std::string password)
    : Entity(id), username_(username), password_(password) {}

//returns a human-readable string representation.
std::string Account::toString(bool detailed)
{
    std::ostringstream oss;

    oss << "Username: " << username_ << std::endl
        << "Password: " << password_;

    return oss.str();
}

//returns a string representation suitable for storage.
std::string Account::serialize()
{
    return username_ + "," + password_;
}
