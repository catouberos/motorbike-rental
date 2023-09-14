#ifndef PROMPT_H_
#define PROMPT_H_

#include "../manager/MemberManager.h"
#include "../manager/MotorbikeManager.h"

class Prompt
{
public:
    static void registerMember(MemberManager &memberManager);
    static void guestViewMotorbikes(MotorbikeManager &motorbikeManager);
};

#endif
