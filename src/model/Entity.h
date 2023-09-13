#ifndef ENTITY_H_
#define ENTITY_H_

class Entity
{
public:
    unsigned int id_;

    Entity(unsigned int id);

    virtual std::string toString();
    virtual std::string serialize();
};

#endif
