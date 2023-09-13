#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Date.h"
#include "Motorbike.h"
#include "Account.h"
#include "Rating.h"
#include "Request.h"
#ifndef SYSTEM_H
#define SYSTEM_H
class System
{
    std::vector<Member> m_listMembers{};
    std::vector<Motorbike> m_listMotorbikes{};
    int m_currentMotorID{0};
    int m_currentMemID{0};
    std::vector<RenterRating> m_listRenterRating{};
    std::vector<MotorbikeRating> m_listMotorRating{};
    std::vector<Request> m_listRequest{};
    std::string m_adminUsername{"admin"};
    std::string m_adminPassword{"admin"};

public:
    void viewMotorbikeListGuest();

    friend class Member;

    int getCurrentMotorID();

    int getCurrentMemID();

    bool reloadDataMember();
    
    bool reloadDataMotorbike();


    void registerMember();

    int MemberIDtoIndex(int memberID);

    int MotorbikeIDtoIndex(int motorbikeID);

    void topUp(int memberID);

    void viewMember(int memberID);

    void viewMemberAdmin(int memberID);

    void listMotorbike(int memberID);

    void unlistMotorbike(int memberID);

    bool reloadDataRenterRating();

    bool reloadDataMotorRating();

    bool reloadDataRequest();

    void viewMotor(int motorID);

    void rateMotorbike(int memberID);

    void rateRenter(int memberID);

    void AvailableList(int memberID);

    void viewRequest(int memberID);

    void sendRequest(int memberID);

    void acceptRequest(int memberID);

    void returnMotorBike(int memberID);

    int signIn();

    bool adminSignIn();

    void saveMember();

    void saveMotorbike();

    void saveRenterRating();

    void saveMotorRating();

    void saveRequest();

    void viewMotorListAdmin();

    void viewMemberListAdmin();
};
#endif