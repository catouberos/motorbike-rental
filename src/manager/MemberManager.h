#ifndef MEMBER_MANAGER_H_
#define MEMBER_MANAGER_H_

#include <vector>

#include "../model/Member.h"

class MemberManager
{
    std::vector<Member> members_;

public:
    MemberManager();

    unsigned int current_member_id_;

    bool add(Member member);

    std::vector<Member> getMembers();

    Member getMemberFromId(unsigned int id);

    unsigned int getUnusedId();

    bool registerMember(std::string username, std::string password,
                        std::string full_name,
                        std::string phone_number,
                        std::string id_type,
                        std::string id_number,
                        std::string license_number,
                        std::string expiry_date);

    bool loginMember(std::string username, std::string password);

    bool logoutMember();

    // load from file
    bool init();

    // save to file
    bool save();
};

#endif
