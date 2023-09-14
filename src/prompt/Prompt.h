#ifndef PROMPT_H_
#define PROMPT_H_

#include "../manager/MemberManager.h"
#include "../manager/MotorbikeManager.h"

class Prompt
{
public:
    static void welcomeScreen();
    static bool loginMember(MemberManager &memberManager);
    static bool registerMember(MemberManager &memberManager);
    static void guestViewMotorbikes(MotorbikeManager &motorbikeManager);
};

#endif
