#pragma once
#ifndef MEMBER_H_
#define MEMBER_H_

#include <string>
#include "Entity.h"
#include "IDType.h"

class Member: public Entity {
    private:
        std::string username;
        std::string password;
        
        /* user information */
        std::string full_name;
        std::string phone_number;
        IDType id_type;
        std::string id_number;
        std::string license_number;
        std::string expiry_date;

    public:
        Member(int id, std::string username, std::string password);
};

#endif
