#include <iostream>
#include <fstream>

#include "MemberManager.h"

//Class constructor
MemberManager::MemberManager() : current_member_id_(0){};

//Class destructor
MemberManager::~MemberManager()
{
    for (Member *member : members_)
    {
        delete member;
    }
}

//add a Member object to the members_ vector.
bool MemberManager::add(Member *member)
{
    members_.push_back(member);

    return true;
}

//returns a vector containing pointers to all the Member objects managed by the MemberManager.
std::vector<Member *> MemberManager::getMembers()
{
    return members_;
}

//retrieves a Member object based on its ID
Member *MemberManager::getMemberFromId(unsigned int id)
{
    for (Member *member : members_)
    {
        if (id == member->id_)
        {
            return member;
        }
    }

    throw 404;
}

//return an unused member ID.
unsigned int MemberManager::getUnusedId()
{
    return members_.size() + 1;
}

//Log in a member
//Return ‘true’ if the operation is successful.
bool MemberManager::loginMember(std::string username, std::string password)
{
    bool match = false;

    for (Member *member : members_)
    {
        if (username == member->username_)
        {
            if (password == member->password_)
            {
                current_member_id_ = member->id_;
                return true;
            }
            else
            {
                throw 401;
            }
        }
    }

    throw 404;
}

//Register new Member
//Return ‘true’ if the registration is successful.
bool MemberManager::registerMember(std::string username, std::string password,
                                   std::string full_name,
                                   std::string phone_number,
                                   std::string id_type,
                                   std::string id_number,
                                   std::string license_number,
                                   std::string expiry_date)
{
    for (Member *member : members_)
    {
        if (username == member->username_)
        {
            throw 409;
        }
    }

    Member *member = new Member(getUnusedId(), username, password, full_name, phone_number, id_type, id_number, license_number, expiry_date, 20, 0, 0);

    members_.push_back(member);

    return true;
}

//Log out a member
//Return ‘true’ if the operation is successful.
bool MemberManager::logoutMember()
{
    current_member_id_ = 0;

    return true;
}

//initialize the MemberManager by loading member data from a file.
//Return ‘true’ if the operation is successful.
// very likely to break if is not serialize properly
bool MemberManager::init(MotorbikeManager &motorbikeManager)
{
    // check: only allow loading when initialize, where member list is empty
    if (members_.size() > 0)
    {
        return false;
    }

    std::fstream file;
    file.open("customer.dat", std::ios::in);

    // check: file not exist, likely first run
    if (!file)
    {
        return false;
    }

    // parse format:
    // id,username,password,full_name,phone_number,id_type,id_number,license_number,expiry_date,credit_point,renter_rating,owned_motorbike_id,rented_motorbike_id
    while (file.peek() != EOF)
    {
        std::string id;
        std::string username;
        std::string password;

        std::string full_name;
        std::string phone_number;
        std::string id_type;
        std::string id_number;
        std::string license_number;
        std::string expiry_date;

        std::string credit_point;
        std::string renter_rating;

        std::string owned_motorbike_id;
        std::string rented_motorbike_id;

        std::getline(file, id, ',');
        std::getline(file, username, ',');
        std::getline(file, password, ',');
        std::getline(file, full_name, ',');
        std::getline(file, phone_number, ',');
        std::getline(file, id_type, ',');
        std::getline(file, id_number, ',');
        std::getline(file, license_number, ',');
        std::getline(file, expiry_date, ',');
        std::getline(file, credit_point, ',');
        std::getline(file, owned_motorbike_id, ',');
        std::getline(file, rented_motorbike_id, '\n');

        Motorbike *owned_motorbike = motorbikeManager.getMotorbikeFromId(std::stoi(owned_motorbike_id));
        Motorbike *rented_motorbike = motorbikeManager.getMotorbikeFromId(std::stoi(rented_motorbike_id));

        Member *member = new Member(std::stoi(id), username, password, full_name, phone_number, id_type, id_number, license_number, expiry_date, std::stoi(credit_point), owned_motorbike, rented_motorbike);

        add(member);
    }

    file.close();

    return true;
}

//Save current state of the member data to a file.
bool MemberManager::save()
{
    std::ofstream file;

    file.open("customer.dat", std::ios::out);

    if (!file)
    {
        return false;
    }

    for (Member *member : members_)
    {
        file << member->serialize() << std::endl;
    }

    file.close();

    return true;
}
