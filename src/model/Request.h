#ifndef REQUEST_H_
#define REQUEST_H_

#include <iostream>

#include "Entity.h"
#include "Member.h"

enum RequestState
{
    PENDING,
    ACCEPTED,
    REJECTED,
    COMPLETED,
};

class Request : public Entity
{
    Member *sender;
    Motorbike *motorbike;
    RequestState state;

public:
    Request(unsigned int id, Member *sender, Motorbike *motorbike, RequestState state = PENDING);

    Motorbike *getMotorbike();
    Member *getSender();
    RequestState getState();

    bool setState(RequestState state);

    std::string toString();

    std::string serialize();
};
#endif
