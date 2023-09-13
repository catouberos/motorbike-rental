#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>

#include "Entity.h"

class Account : public Entity
{
protected:
    std::string username_;
    std::string password_;

public:
    Account(unsigned int id, std::string username, std::string password);

    virtual std::string toString();
    virtual std::string serialize();

    friend class System;
};

#endif