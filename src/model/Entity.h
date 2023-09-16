#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>

class Entity
{
public:
    unsigned int id_;

    Entity(unsigned int id);

    virtual std::string toString(bool detailed = false);
    virtual std::string serialize();
};

#endif
