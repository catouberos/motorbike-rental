#include <fstream>

#include "RequestManager.h"

//Class constructor
RequestManager::RequestManager() {}

bool RequestManager::add(Request *request)
{
    requests_.push_back(request);
    return true;
}

//returns an unused ID for a new request.
unsigned int RequestManager::getUnusedId()
{
    return requests_.size() + 1;
}

//returns a vector containing all the Request objects stored in the requests_ vector.
std::vector<Request *> RequestManager::getRequests()
{
    return requests_;
}

//retrieves a Request object by its unique ID.
Request *RequestManager::getRequestFromId(unsigned int id)
{
    for (Request *request : requests_)
    {
        if (request->id_ == id)
        {
            return request;
        }
    }

    throw 404;
}

//returns a vector containing all the requests related to a specific Motorbike.
std::vector<Request *> RequestManager::getRequestsFromMotorbike(Motorbike &motorbike)
{
    std::vector<Request *> requests;
    for (Request *request : requests_)
    {
        if (request->getMotorbike()->id_ == motorbike.id_)
        {
            requests.push_back(request);
        }
    }

    return requests;
}

//initializes the RequestManager by loading requests from a file 
bool RequestManager::init(MemberManager &memberManager, MotorbikeManager &motorbikeManager)
{
    if (requests_.size() > 0)
    {
        return false;
    }

    std::ifstream file;
    file.open("requests.dat", std::ios::in);

    if (!file)
    {
        return false;
    }

    while (file.peek() != EOF)
    {
        std::string id;
        std::string senderId;
        std::string motorbikeId;
        std::string state;

        std::getline(file, id, ',');
        std::getline(file, senderId, ',');
        std::getline(file, motorbikeId, ',');
        std::getline(file, state, '\n');

        Member *sender = memberManager.getMemberFromId(std::stoi(senderId));
        Motorbike *motorbike = motorbikeManager.getMotorbikeFromId(std::stoi(motorbikeId));

        if (sender == nullptr || motorbike == nullptr)
        {
            // member or motorbike does not exist
            break;
        }

        RequestState request_state;
        if (state == "PENDING")
        {
            request_state = PENDING;
        }
        else if (state == "ACCEPTED")
        {
            request_state = ACCEPTED;
        }
        else if (state == "REJECTED")
        {
            request_state = REJECTED;
        }
        else if (state == "COMPLETED")
        {
            request_state = COMPLETED;
        }
        else
        {
            // invalid state
            break;
        }

        Request *request = new Request(
            std::stoi(id),
            sender,
            motorbike,
            request_state);

        add(request);
    }

    file.close();

    return true;
}

//saves the current state of the RequestManager to a file
bool RequestManager::save()
{
    std::ofstream file;

    file.open("requests.dat", std::ios::out);

    if (!file)
    {
        return false;
    }

    for (Request *request : requests_)
    {
        file << request->serialize() << std::endl;
    }

    file.close();

    return true;
}
