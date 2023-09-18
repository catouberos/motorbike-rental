#include <ostream>
#include <string>
#include <vector>
#include <fstream>

#include "./utils/Utils.h"

#include "./model/Date.h"
#include "./model/Motorbike.h"
#include "./model/Account.h"

#include "./manager/MotorbikeManager.h"
#include "./manager/MemberManager.h"
#include "./manager/MotorbikeRatingManager.h"
#include "./manager/MemberRatingManager.h"
#include "./manager/RequestManager.h"

#include "./prompt/Prompt.h"

int main()
{
    MotorbikeManager motorbikeManager;
    MemberManager memberManager;

    MotorbikeRatingManager motorbikeRatingManager;
    MemberRatingManager memberRatingManager;

    RequestManager requestManager;

    // load the member and motorbike managers
    motorbikeManager.init();
    memberManager.init(motorbikeManager);

    // load the rating managers
    motorbikeRatingManager.init(motorbikeManager, memberManager);
    memberRatingManager.init(memberManager);

    // load the request manager
    requestManager.init(memberManager, motorbikeManager);

    unsigned int mainChoice;

    do
    {

        // clear the console
        Utils::clrscr();

        Prompt::welcomeScreen();

        // prompt the user to login
        std::cout << "Use the app as: [1] Guest, [2] Member, [3] Admin" << std::endl
                  << std::endl
                  << "Otherwise, use [0] to exit" << std::endl
                  << std::endl
                  << "Enter your choice: ";
        std::cin >> mainChoice;
        std::cin.ignore();

        switch (mainChoice)
        {
        case 0:
            break;

        // guest application
        case 1:
            unsigned int guestChoice;

            do
            {
                Utils::clrscr();

                std::cout << "EEET2482 ASSIGNMENT" << std::endl
                          << "MOTORBIKE RENTAL APPLICATION" << std::endl
                          << std::endl
                          << "Welcome, guest." << std::endl
                          << "[1] Register" << std::endl
                          << "[2] View all motorbikes" << std::endl
                          << std::endl
                          << "[0] Exit" << std::endl
                          << std::endl
                          << "Enter your choice: ";
                std::cin >> guestChoice;
                std::cin.ignore();

                switch (guestChoice)
                {
                case 0:
                {
                    break;
                }
                case 1:
                {
                    Prompt::registerMember(memberManager);
                    guestChoice = 0;
                    break;
                }
                case 2:
                {
                    Prompt::guestViewMotorbikes(motorbikeManager, motorbikeRatingManager);
                    break;
                }
                default:
                {
                    std::cout << "***Invalid choice!***\n";
                    break;
                    ;
                }
                }
            } while (guestChoice != 0);
            break;

        // member application
        case 2:
            Utils::clrscr();

            if (Prompt::loginMember(memberManager) == true)
            {
                int userChoice;

                do
                {
                    Utils::clrscr();

                    Member *current_member = memberManager.getMemberFromId(memberManager.current_member_id_);

                    std::cout << "EEET2482 ASSIGNMENT" << std::endl
                              << "MOTORBIKE RENTAL APPLICATION" << std::endl
                              << std::endl
                              << "Welcome, " << current_member->getFullName() << std::endl;

                    if (current_member->getRentedMotorbike() != nullptr)
                    {
                        std::cout << "You are currently renting a bike from "
                                  << current_member->getRentedMotorbike()->getStartDate().toString()
                                  << " to "
                                  << current_member->getRentedMotorbike()->getEndDate().toString() << std::endl
                                  << std::endl;
                    }

                    if (current_member->getOwnedMotorbike() == nullptr)
                    {
                        std::cout << "You currently are not owning any motorbike, press [9] to register one." << std::endl;
                    }
                    else
                    {
                        if (current_member->getOwnedMotorbike()->getStartDate().getDay() == 0)
                        {
                            std::cout << "Your motorbike is currently unlisted, press [10] to list it." << std::endl;
                        }
                        else
                        {
                            std::cout << "Your motorbike is currently listed, press [10] to unlist it." << std::endl;
                        }
                    }

                    std::cout << std::endl;

                    std::cout << "[1] View your information" << std::endl
                              << "[2] Topup credits" << std::endl
                              << std::endl;

                    if (current_member->getOwnedMotorbike() != nullptr)
                    {
                    std::cout << "[3] View renters of your bike" << std::endl
                              << "[4] Rate current renter" << std::endl
                              << std::endl
                              << "[5] View requests to rent your bike" << std::endl
                              << "[6] Accept a request" << std::endl
                              << std::endl;
                    }

                    if (current_member->getRentedMotorbike() == nullptr)
                    {
                        std::cout << "[7] Find available motorbikes for rent" << std::endl
                                  << "[8] Request to rent" << std::endl
                                  << std::endl;
                    }
                    else
                    {
                        std::cout << "[7] Rate your rented motorbike" << std::endl
                                  << "[8] Return your rented motorbike" << std::endl
                                  << std::endl;
                    }

                    std::cout << "[0] Exit" << std::endl
                              << std::endl
                              << "Enter your choice: ";
                    std::cin >> userChoice;
                    std::cin.ignore();

                    switch (userChoice)
                    {
                    case 0:
                        break;

                    case 1:
                        Prompt::memberViewDetails(*current_member);
                        break;

                    case 2:
                        Prompt::memberTopup(*current_member);
                        break;

                    case 3:
                        if (current_member->getOwnedMotorbike() != nullptr)
                        {
                            Prompt::memberViewRenters(*current_member, requestManager);
                        }

                        break;

                    case 4:
                        if (current_member->getOwnedMotorbike() != nullptr)
                        {
                            Prompt::memberRateRenter(*current_member, memberManager, memberRatingManager);
                        }

                        break;

                    case 5:
                        if (current_member->getOwnedMotorbike() != nullptr)
                        {
                            Prompt::memberViewRequests(*current_member, requestManager);
                        }

                        break;

                    case 6:
                        if (current_member->getOwnedMotorbike() != nullptr)
                        {
                            Prompt::memberAcceptRequest(*current_member, requestManager);
                        }

                        break;

                    case 7:
                        if (current_member->getRentedMotorbike() == nullptr)
                        {
                            Prompt::memberViewAvailableMotorbikes(*current_member, motorbikeManager, memberRatingManager);
                            break;
                        }
                        else
                        {
                            Prompt::memberRateMotorbike(*current_member, motorbikeRatingManager);
                            break;
                        }

                    case 8:
                        if (current_member->getRentedMotorbike() == nullptr)
                        {
                            Prompt::memberRequest(*current_member, motorbikeManager, memberRatingManager, requestManager);
                            break;
                        }
                        else
                        {
                            Prompt::memberReturnMotorbike(*current_member);
                            break;
                        }

                    case 9:
                        if (current_member->getOwnedMotorbike() == nullptr)
                        {
                            Prompt::memberRegisterMotorbike(*current_member, motorbikeManager);
                        }
                        break;

                    case 10:
                        if (current_member->getOwnedMotorbike() != nullptr && current_member->getOwnedMotorbike()->getStartDate().getDay() == 0)
                        {
                            Prompt::memberListMotorbike(*current_member);
                            break;
                        }

                        if (current_member->getOwnedMotorbike() != nullptr)
                        {
                            Prompt::memberUnlistMotorbike(*current_member);
                            break;
                        }

                        break;
                    }
                } while (userChoice != 0);
            }
            break;

        // admin application
        case 3:
            Utils::clrscr();

            if (Prompt::loginAdmin() == true)
            {
                int adminChoice;

                do
                {
                    Utils::clrscr();

                    std::cout << "EEET2482 ASSIGNMENT" << std::endl
                              << "MOTORBIKE RENTAL APPLICATION" << std::endl
                              << std::endl
                              << "Welcome, admin." << std::endl
                              << "[1] View all members" << std::endl
                              << "[2] View all motorbikes" << std::endl
                              << std::endl
                              << "[0] Exit" << std::endl
                              << std::endl
                              << "Enter your choice: ";
                    std::cin >> adminChoice;
                    std::cin.ignore();

                    switch (adminChoice)
                    {
                    case 0:
                        break;

                    case 1:
                        Prompt::adminViewMembers(memberManager, memberRatingManager);
                        break;

                    case 2:
                        Prompt::adminViewMotorbikes(motorbikeManager, motorbikeRatingManager);
                        break;
                    }
                } while (adminChoice != 0);
            }
            break;

        default:
            break;
        }
    } while (mainChoice != 0);

    memberManager.save();
    motorbikeManager.save();

    memberRatingManager.save();
    motorbikeRatingManager.save();

    requestManager.save();

    return 0;
}
