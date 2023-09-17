#include <fstream>

#include "RequestManager.h"

RequestManager::RequestManager() {}

bool RequestManager::add(Request *request)
{
    requests_.push_back(request);
    return true;
}

unsigned int RequestManager::getUnusedId()
{
    return requests_.size() + 1;
}

std::vector<Request *> RequestManager::getRequests()
{
    return requests_;
}

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
