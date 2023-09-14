#include <iostream>

#include "Prompt.h"

void Prompt::registerMember(MemberManager &memberManager)
{
    std::string username;
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    std::string password;
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    std::string full_name;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, full_name);

    std::string phone_number;
    std::cout << "Enter your phone number: ";
    std::getline(std::cin, phone_number);

    std::string id_type;
    std::cout << "Enter your ID type: ";
    std::getline(std::cin, id_type);

    std::string id_number;
    std::cout << "Enter your ID number: ";
    std::getline(std::cin, id_number);

    std::string license_number;
    std::cout << "Enter your licnese number: ";
    std::getline(std::cin, license_number);

    std::string expiry_date;
    std::cout << "Enter your license expiry date: ";
    std::getline(std::cin, expiry_date);

    std::string password_confirm;
    std::cout << "The initial entry fee is $20, which will earn your account 20 credit point" << std::endl
              << "Type your password to confirm transaction: ";
    std::getline(std::cin, password_confirm);

    if (password_confirm == password)
    {
        std::cout << "***Transaction confirmed!***\n";
        memberManager.registerMember(username, password, full_name, phone_number, id_type, id_number, license_number, expiry_date);
    }
    else
    {
        std::cout << "***Wrong password***\n";
        return;
    }

    std::cout << "***Registered sucessfully***\n";
}

void Prompt::guestViewMotorbikes(MotorbikeManager &motorbikeManager)
{
    for (Motorbike motorbike : motorbikeManager.getMotorbikes())
    {
        std::cout << motorbike.toString() << std::endl;
    }

    std::cout << "Press any key to exit" << std::endl;
    std::cin.ignore();
}
