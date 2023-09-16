#ifndef PROMPT_H_
#define PROMPT_H_

#include "../manager/MemberManager.h"
#include "../manager/MotorbikeManager.h"
#include "../manager/MemberRatingManager.h"
#include "../manager/MotorbikeRatingManager.h"
#include "../manager/RequestManager.h"

class Prompt
{
    static const std::string admin_username_;
    static const std::string admin_password_;

public:
    static void welcomeScreen();
    static bool loginMember(MemberManager &memberManager);
    static bool memberRegisterMotorbike(Member &member, MotorbikeManager &motorbikeManager);
    static void memberViewDetails(Member &member);
    static bool memberTopup(Member &currentMember);
    static void memberViewAvailableMotorbikes(Member &member, MotorbikeManager &motorbikeManager, MemberRatingManager &memberRatingManager);
    static void memberListMotorbike(Member &currentMember);
    static void memberUnlistMotorbike(Member &currentMember);
    static void memberRequest(Member &currentMember, MotorbikeManager &motorbikeManager, MemberRatingManager &memberRatingManager, RequestManager &requestManager);
    static void memberViewRequests(Member &currentMember, RequestManager &requestManager);
    static void memberAcceptRequest(Member &currentMember, RequestManager &requestManager);

    static bool registerMember(MemberManager &memberManager);
    static void guestViewMotorbikes(MotorbikeManager &motorbikeManager, MotorbikeRatingManager &motorbikeRatingManager);

    static bool loginAdmin();
    static void adminViewMembers(MemberManager &memberManager, MemberRatingManager &memberRatingManager);
    static void adminViewMotorbikes(MotorbikeManager &motorbikeManager, MotorbikeRatingManager &motorbikeRatingManager);
};

#endif
