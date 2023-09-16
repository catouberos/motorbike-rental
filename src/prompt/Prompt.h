#ifndef PROMPT_H_
#define PROMPT_H_

#include "../manager/MemberManager.h"
#include "../manager/MotorbikeManager.h"
#include "../manager/MemberRatingManager.h"
#include "../manager/MotorbikeRatingManager.h"

class Prompt
{
    static const std::string admin_username_;
    static const std::string admin_password_;

public:
    static void welcomeScreen();
    static bool loginMember(MemberManager &memberManager);
    static bool registerMember(MemberManager &memberManager);

    static void guestViewMotorbikes(MotorbikeManager &motorbikeManager, MotorbikeRatingManager &motorbikeRatingManager);

    static bool loginAdmin();
    static void adminViewMembers(MemberManager &memberManager, MemberRatingManager &memberRatingManager);
    static void adminViewMotorbikes(MotorbikeManager &motorbikeManager, MotorbikeRatingManager &motorbikeRatingManager);
};

#endif
