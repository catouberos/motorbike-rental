#include <iostream>

#include "Prompt.h"
#include "../utils/Utils.h"

const std::string Prompt::admin_username_ = "admin";
const std::string Prompt::admin_password_ = "admin";

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
        std::getline(std::cin, username);

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
            std::cin.ignore();

            if (prompt == 'n')
            {
                break;
            }
        }
    } while (true);

    return false;
}

bool Prompt::memberRegisterMotorbike(Member &member, MotorbikeManager &motorbikeManager)
{
    do
    {
        Utils::clrscr();

        std::string model;
        std::cout << "Enter model: ";
        std::getline(std::cin, model);

        std::string color;
        std::cout << "Enter color: ";
        std::getline(std::cin, color);

        std::string engine_size;
        std::cout << "Enter engine size: ";
        std::getline(std::cin, engine_size);

        std::string transmission_mode;
        std::cout << "Enter transmission mode: ";
        std::getline(std::cin, transmission_mode);

        std::string year_made;
        std::cout << "Enter year made: ";
        std::getline(std::cin, year_made);

        std::string description;
        std::cout << "Enter description: ";
        std::getline(std::cin, description);

        std::string location;
        std::cout << "Enter location: ";
        std::getline(std::cin, location);
      
        Motorbike *motorbike = motorbikeManager.registerMotorbike(member.id_, model, color, engine_size, transmission_mode, std::stoi(year_made), description, 0, 0, location);

        member.setOwnedMotorbike(motorbike);

        return true;
    } while (true);

    return false;
}

void Prompt::memberViewDetails(Member &member)
{
    Utils::clrscr();

    std::cout << member.toString(true) << std::endl
              << std::endl
              << "Press any key to exit" << std::endl;
    std::cin.ignore();
}

bool Prompt::memberTopup(Member &member)
{
    do
    {
        Utils::clrscr();

        std::string amount;
        std::cout << "Enter amount: ";
        std::getline(std::cin, amount);

        try
        {
            member.topUp(std::stoi(amount));
            std::cout << std::endl
                      << "Press any key to exit"
                      << std::endl;
            std::cin.ignore();

            return true;
        }
        catch (int error)
        {
            char prompt;

            if (error == 400)
            {
                std::cout << "Amount must be positive" << std::endl;
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

void Prompt::memberListMotorbike(Member &currentMember)
{
        Utils::clrscr();

        std::string start_date;
        std::cout << "Enter start date (yyyy/mm/dd): ";
        std::getline(std::cin, start_date);

        std::string end_date;
        std::cout << "Enter end date (yyyy/mm/dd): ";
        std::getline(std::cin, end_date);

        std::string consume_point;
        std::cout << "Enter consume point (per day): ";
        std::getline(std::cin, consume_point);

        std::string renter_rating;
        std::cout << "Enter required renter rating: ";
        std::getline(std::cin, renter_rating);

        currentMember.getOwnedMotorbike()->setList(Date(start_date), Date(end_date), std::stoi(consume_point), std::stod(renter_rating));

    std::cout << "Listed successfully" << std::endl
              << "Press any key to exit" << std::endl;
    std::cin.ignore();
}

void Prompt::memberUnlistMotorbike(Member &currentMember) {
    Utils::clrscr();

    try {
        currentMember.getOwnedMotorbike()->setUnlist();

        std::cout << "Unlist successfully" << std::endl;
    } catch (int error) {
        if (error == 400) {
            std::cout << "Motorbike is being rented" << std::endl;
        } else {
            std::cout << "Something went wrong" << std::endl;
        }
    }

    std::cout << "Press any key to exit" << std::endl;
    std::cin.ignore();
}

void Prompt::memberViewAvailableMotorbikes(Member &member, MotorbikeManager &motorbikeManager, MemberRatingManager &memberRatingManager)
{
    Utils::clrscr();

    std::string city;
    std::cout << "Enter city: ";
    std::getline(std::cin, city);

    for (Motorbike *motorbike : motorbikeManager.getMotorbikes())
    {
        if (motorbike->getStartDate().getDay() != 0 && // if listed
            motorbike->getRenterId() == 0 && // if unrented
            motorbike->id_ != member.getOwnedMotorbike()->id_ && // if not owned by member
            motorbike->getPointConsumed() <= member.getCreditPoint() && // if member has enough point
            memberRatingManager.getAverageRating(member.id_) >= motorbike->getRequiredRating() && // if member rating is enough
            motorbike->getLocation() == city) // if in the search city
        {
            std::cout << motorbike->toString() << std::endl;
        }
    }

    std::cout << "Press any key to exit" << std::endl;
    std::cin.ignore();
}

void Prompt::memberRequest(Member &currentMember, MotorbikeManager &motorbikeManager, MemberRatingManager &memberRatingManager, RequestManager &requestManager)
{
    Utils::clrscr();

    std::string motorbike_id;
    std::cout << "Enter motorbike id: ";
    std::getline(std::cin, motorbike_id);

    Motorbike *motorbike = motorbikeManager.getMotorbikeFromId(std::stoi(motorbike_id));

    if (motorbike == nullptr)
    {
        std::cout << "Motorbike not found" << std::endl
                  << "Press any key to exit" << std::endl;
        std::cin.ignore();
        return;
    }

    if (currentMember.getRentedMotorbike() != nullptr)
    {
        std::cout << "You cannot rent more than one motorbike" << std::endl
                  << "Press any key to exit" << std::endl;
        std::cin.ignore();
        return;
    }

    if (motorbike->id_ == currentMember.getOwnedMotorbike()->id_)
    {
        std::cout << "You cannot rent your own motorbike" << std::endl
                  << "Press any key to exit" << std::endl;
        std::cin.ignore();
        return;
    }

    if (motorbike->getStartDate().getDay() == 0)
    {
        std::cout << "Motorbike is not listed" << std::endl
                  << "Press any key to exit" << std::endl;
        std::cin.ignore();
        return;
    }

    if (motorbike->getRenterId() != 0)
    {
        std::cout << "Motorbike is being rented" << std::endl
                  << "Press any key to exit" << std::endl;
        std::cin.ignore();
        return;
    }

    if (motorbike->getPointConsumed() > currentMember.getCreditPoint())
    {
        std::cout << "You do not have enough credit point" << std::endl
                  << "Press any key to exit" << std::endl;
        std::cin.ignore();
        return;
    }

    if (motorbike->getRequiredRating() > memberRatingManager.getAverageRating(currentMember.id_))
    {
        std::cout << "Your rating is not enough" << std::endl
                  << "Press any key to exit" << std::endl;
        std::cin.ignore();
        return;
    }

    Request *request = new Request(requestManager.getUnusedId(), &currentMember, motorbike, RequestState::PENDING);
    requestManager.add(request);
}

void Prompt::memberViewRequests(Member &currentMember, RequestManager &requestManager)
{
    Utils::clrscr();

    for (Request *request : requestManager.getRequestsFromMotorbike(*currentMember.getOwnedMotorbike()))
    {
        std::cout << request->toString() << std::endl;
    }

    std::cout << "Press any key to exit" << std::endl;
    std::cin.ignore();
}

void Prompt::memberAcceptRequest(Member &currentMember, RequestManager &requestManager)
{
    Utils::clrscr();

    std::string request_id;
    std::cout << "Enter request id: ";
    std::getline(std::cin, request_id);

    Request *request = requestManager.getRequestFromId(std::stoi(request_id));

    if (request == nullptr)
    {
        std::cout << "Request not found" << std::endl
                  << "Press any key to exit" << std::endl;
        std::cin.ignore();
        return;
    }

    if (request->getMotorbike()->id_ != currentMember.getOwnedMotorbike()->id_)
    {
        std::cout << "You cannot accept this request" << std::endl
                  << "Press any key to exit" << std::endl;
        std::cin.ignore();
        return;
    }

    if (request->getState() != RequestState::PENDING)
    {
        std::cout << "Request is not pending" << std::endl
                  << "Press any key to exit" << std::endl;
        std::cin.ignore();
        return;
    }

    request->setState(RequestState::ACCEPTED);
    request->getSender()->setRentedMotorbike(request->getMotorbike());
    request->getMotorbike()->setRenterId(request->getSender()->id_);

    // set all other requests to rejected
    for (Request *request : requestManager.getRequestsFromMotorbike(*currentMember.getOwnedMotorbike()))
    {
        if (request->getState() == RequestState::PENDING)
        {
            request->setState(RequestState::REJECTED);
        }
    }
}

bool Prompt::registerMember(MemberManager &memberManager)
{
    do
    {
        Utils::clrscr();

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

void Prompt::guestViewMotorbikes(MotorbikeManager &motorbikeManager, MotorbikeRatingManager &motorbikeRatingManager)
{
    Utils::clrscr();

    for (Motorbike *motorbike : motorbikeManager.getMotorbikes())
    {
        std::cout << motorbike->toString() << std::endl
                  << "Average rating: " << motorbikeRatingManager.getAverageRating(motorbike->id_) << std::endl;
    }

    std::cout << "Press any key to exit" << std::endl;
    std::cin.ignore();
}

bool Prompt::loginAdmin()
{
    do
    {
        Utils::clrscr();

        std::string username;
        std::cout << "Enter your username: ";
        std::getline(std::cin, username);

        std::string password;
        std::cout << "Enter your password: ";
        std::getline(std::cin, password);

        if (username == admin_username_ && password == admin_password_)
        {
            std::cout << "Login successful" << std::endl;
            return true;
        }
        else
        {
            char prompt;

            std::cout << "Wrong username or password" << std::endl;

            std::cout << "Try again? (Y/n) ";
            std::cin >> prompt;

            if (prompt == 'n')
            {
                return false;
            }
        }
    } while (true);
}

void Prompt::adminViewMembers(MemberManager &memberManager, MemberRatingManager &memberRatingManager)
{
    Utils::clrscr();

    for (Member *member : memberManager.getMembers())
    {
        std::cout << member->toString(true) << std::endl
                  << "Average rating: " << memberRatingManager.getAverageRating(member->id_) << std::endl
                  << std::endl
                  << std::endl;
    }

    std::cout << "Press any key to exit" << std::endl;
    std::cin.ignore();
}

void Prompt::adminViewMotorbikes(MotorbikeManager &motorbikeManager, MotorbikeRatingManager &motorbikeRatingManager)
{
    Utils::clrscr();

    for (Motorbike *motorbike : motorbikeManager.getMotorbikes())
    {
        std::cout << motorbike->toString(true) << std::endl
                  << "Average rating: " << motorbikeRatingManager.getAverageRating(motorbike->id_) << std::endl
                  << std::endl
                  << std::endl;
    }

    std::cout << "Press any key to exit" << std::endl;
    std::cin.ignore();
}
