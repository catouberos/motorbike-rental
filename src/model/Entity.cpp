#include <string>

#include "Entity.h"

Entity::Entity(unsigned int id) : id_(id) {}

std::string Entity::toString(bool detailed)
{
    return "Entity ID: " + std::to_string(id_);
}

std::string Entity::serialize()
{
    return std::to_string(id_);
}
