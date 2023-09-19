#include "Request.h"

//Class constructor
Request::Request(unsigned int id, Member *sender, Motorbike *motorbike, RequestState state) : Entity(id), sender(sender), motorbike(motorbike), state(state) {}

//returns a pointer to the Motorbike object associated with the request, which represents the motorbike being requested for rent.
Motorbike *Request::getMotorbike()
{
    return motorbike;
}

//returns a pointer to the Member object who sent the request, representing the member requesting to rent the motorbike
Member *Request::getSender()
{
    return sender;
}

//returns the current state of the request, represented by the RequestState enum.
RequestState Request::getState()
{
    return state;
}

//set the state of the request to a new value.
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

//returns a human-readable string representation.
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

//returns a string representation suitable for storage.
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
