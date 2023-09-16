#ifndef REQUEST_MANAGER_H_
#define REQUEST_MANAGER_H_

#include <vector>

#include "../manager/MemberManager.h"
#include "../manager/MotorbikeManager.h"
#include "../model/Request.h"

class RequestManager
{
    std::vector<Request*> requests_;

public:
    RequestManager();

    bool add(Request *request);

    unsigned int getUnusedId();

    Request *getRequestFromId(unsigned int id);

    std::vector<Request *> getRequestsFromMotorbike(Motorbike &motorbike);

    bool init(MemberManager &memberManager, MotorbikeManager &motorbikeManager);

    bool save();
};

#endif
