#include "Request.h"

Request::Request(unsigned int id, Member *sender, Motorbike *motorbike, RequestState state) : Entity(id), sender(sender), motorbike(motorbike), state(state) {}

Motorbike *Request::getMotorbike()
{
    return motorbike;
}

Member *Request::getSender()
{
    return sender;
}

RequestState Request::getState()
{
    return state;
}

bool Request::setState(RequestState state)
{
    // enum checks
    if (state == PENDING || state == ACCEPTED || state == REJECTED || state == COMPLETED)
    {
        this->state = state;
        return true;
    }

    return false;
}

std::string Request::toString()
{
    std::string state_string;
    switch (state)
    {
    case PENDING:
        state_string = "PENDING";
        break;
    case ACCEPTED:
        state_string = "ACCEPTED";
        break;
    case REJECTED:
        state_string = "REJECTED";
        break;
    case COMPLETED:
        state_string = "COMPLETED";
        break;
    }

    return std::to_string(id_) + ". Rent request from " + sender->getFullName() + " for motorbike " + std::to_string(motorbike->id_) + " (" + state_string + ")";
}

std::string Request::serialize()
{
    std::string state_string;
    switch (state)
    {
    case PENDING:
        state_string = "PENDING";
        break;
    case ACCEPTED:
        state_string = "ACCEPTED";
        break;
    case REJECTED:
        state_string = "REJECTED";
        break;
    case COMPLETED:
        state_string = "COMPLETED";
        break;
    }

    return std::to_string(id_) + "," + std::to_string(sender->id_) + "," + std::to_string(motorbike->id_) + "," + state_string;
}
