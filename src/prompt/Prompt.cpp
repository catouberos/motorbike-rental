#include <iostream>

#include "Prompt.h"
#include "../utils/Utils.h"

void Prompt::welcomeScreen()
{
    // welcome screen
    std::cout << "EEET2482 ASSIGNMENT" << std::endl
              << "MOTORBIKE RENTAL APPLICATION" << std::endl
              << std::endl
              << "Instructor: Dr. Ling Huo Chong" << std::endl
              << "Group: Group 18" << std::endl
              << "s3978796, Do Khoa Nguyen" << std::endl
              << "s3979562, Tran The Quang Minh" << std::endl
              << "s3958668, Bui Sy Quang" << std::endl
              << "s3854233, Hoang Minh Khoi" << std::endl
              << std::endl;
}

bool Prompt::loginMember(MemberManager &memberManager)
{
    do
    {
        Utils::clrscr();

        std::string username;
        std::cout << "Enter your username: ";
        std::getline(std::cin.ignore(), username);

        std::string password;
        std::cout << "Enter your password: ";
        std::getline(std::cin, password);

        try
        {
            return memberManager.loginMember(username, password);
        }
        catch (int error)
        {
            char prompt;

            switch (error)
            {
            case (401):
                std::cout << "[ERROR] Wrong password" << std::endl;
                break;
            case (404):
                std::cout << "[ERROR] User not found" << std::endl;
                break;
            default:
                std::cout << "[ERROR] Something happened" << std::endl;
            }

            std::cout << "Try again? (Y/n) ";
            std::cin >> prompt;

            if (prompt == 'n')
            {
                break;
            }
        }
    } while (true);

    return false;
}

bool Prompt::registerMember(MemberManager &memberManager)
{
    do
    {
        Utils::clrscr();

        std::string username;
        std::cout << "Enter your username: ";
        std::getline(std::cin.ignore(), username);

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
        std::cout << "Enter your license number: ";
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
            try
            {
                return memberManager.registerMember(username, password, full_name, phone_number, id_type, id_number, license_number, expiry_date);
            }
            catch (int error)
            {
                char prompt;

                if (error == 409)
                {
                    std::cout << "Username has been used" << std::endl;
                }

                std::cout << "Try again? (Y/n) ";
                std::cin >> prompt;

                if (prompt == 'n')
                {
                    break;
                }
            }
        }
        else
        {
            char prompt;

            std::cout << "Wrong password" << std::endl;

            std::cout << "Try again? (Y/n) ";
            std::cin >> prompt;

            if (prompt == 'n')
            {
                break;
            }
        }

    } while (true);

    return false;
}

void Prompt::guestViewMotorbikes(MotorbikeManager &motorbikeManager)
{
    for (Motorbike *motorbike : motorbikeManager.getMotorbikes())
    {
        std::cout << motorbike->toString() << std::endl;
    }

    std::cout << "Press any key to exit" << std::endl;
    std::cin.ignore();
}
