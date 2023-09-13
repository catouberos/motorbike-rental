#ifndef MEMBER_MANAGER_H_
#define MEMBER_MANAGER_H_

#include <vector>

#include "../model/Member.h"

class MemberManager
{
    std::vector<Member> members_;

public:
    MemberManager(std::vector<Member> members);

    std::vector<Member> getMembers();

    bool registerMember();
};

#endif
