#ifndef MEMBER_MANAGER_H_
#define MEMBER_MANAGER_H_

#include <vector>

#include "../model/Member.h"

class MemberManager
{
    std::vector<Member> members_;

public:
    MemberManager();

    bool add(Member member);

    std::vector<Member> getMembers();

    unsigned int getUnusedId();

    Member registerMember(std::string username, std::string password);

    // load from file
    bool init();

    // populate the pointers
    bool load();

    // save to file
    bool save();
};

#endif
