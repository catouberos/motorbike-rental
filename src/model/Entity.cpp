#include <string>

#include "Entity.h"

//Class constructor
Entity::Entity(unsigned int id) : id_(id) {}

//returns a human-readable string representation.
std::string Entity::toString(bool detailed)
{
    return "Entity ID: " + std::to_string(id_);
}
//returns a string representation suitable for storage
std::string Entity::serialize()
{
    return std::to_string(id_);
}
