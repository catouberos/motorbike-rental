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

#include "./prompt/Prompt.h"

int main()
{
    MotorbikeManager motorbikeManager;
    MemberManager memberManager;

    MotorbikeRatingManager motorbikeRatingManager;
    MemberRatingManager memberRatingManager;

    // load the member and motorbike managers
    motorbikeManager.init();
    memberManager.init(motorbikeManager);

    // load the rating managers
    motorbikeRatingManager.init(motorbikeManager, memberManager);
    memberRatingManager.init(memberManager);

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
                    } else {
                        if (current_member->getOwnedMotorbike()->getStartDate().getDay() == 0) {
                            std::cout << "Your motorbike is currently unlisted, press [10] to list it." << std::endl;
                        } else {
                            std::cout << "Your motorbike is currently listed, press [10] to unlist it." << std::endl;
                        }
                    }
                    
                    std::cout << std::endl;

                    std::cout << "[1] View your information" << std::endl
                              << "[2] Topup credits" << std::endl
                              << std::endl
                              << "[8] Get available motorbikes to rent" << std::endl
                              << std::endl
                              << "[0] Exit" << std::endl
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

                    case 8:
                        Prompt::memberViewAvailableMotorbikes(*current_member, motorbikeManager, memberRatingManager);
                        break;

                    case 9:
                        if (current_member->getOwnedMotorbike() == nullptr) {
                            Prompt::memberRegisterMotorbike(*current_member, motorbikeManager);
                        }
                        break;

                    case 10:
                        if (current_member->getOwnedMotorbike() != nullptr && current_member->getOwnedMotorbike()->getStartDate().getDay() == 0) {
                            Prompt::memberListMotorbike(*current_member);
                            break;
                        }

                        if (current_member->getOwnedMotorbike() != nullptr) {
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

    return 0;
}

/*        case 2:
        {
            int userID{rentalShop.signIn()};
            if (userID == -1)
            {
                break;
            }

            int menuChoice{};
            do
            {
                std::cout << "This is your menu:\n";
                std::cout << "2. Rate the motorbike you are renting\n";
                std::cout << "3. Rate current renter\n";
                std::cout << "5. Request motorbike\n";
                std::cout << "6. View request list\n";
                std::cout << "7. Accept request\n";
                std::cout << "9. List motorbike\n";
                std::cout << "10. Unlist motorbike\n";
                std::cout << "11. Return motorbike\n";
                std::cout << "Enter your choice: ";

                std::cin >> menuChoice;
                std::cin.ignore();

                switch (menuChoice)
                {
                case 0:
                {
                    break;
                }

                case 1:
                {
                    std::cout << "\n===YOUR INFORMATION===\n";
                    rentalShop.viewMember(userID);
                    std::cout << "===END SESSION===\n";
                    break;
                }
                case 2:
                {
                    std::cout << "\n===RATE MOTORBIKE===\n";
                    rentalShop.rateMotorbike(userID);
                    std::cout << "===END SESSION===\n";
                    break;
                }
                case 3:
                {
                    std::cout << "\n===RATE RENTER===\n";
                    rentalShop.rateRenter(userID);
                    std::cout << "===END SESSION===\n";
                    break;
                }
                case 4:
                {
                    std::cout << "\n===SEARCH AVAILABLE MOTOTRBIKES===\n";
                    rentalShop.AvailableList(userID);
                    std::cout << "===END SESSION===\n";
                    break;
                }
                case 5:
                {
                    std::cout << "\n===REQUEST MOTORBIKE===\n";
                    rentalShop.sendRequest(userID);
                    std::cout << "===END SESSION===\n";
                    break;
                }
                case 6:
                {
                    std::cout << "\n===VIEW REQUEST===\n";
                    rentalShop.viewRequest(userID);
                    std::cout << "===END SESSION===\n";
                    break;
                }
                case 7:
                {
                    std::cout << "\n===ACCEPT REQUEST===\n";
                    rentalShop.acceptRequest(userID);
                    std::cout << "===END SESSION===\n";
                    break;
                }
                case 8:
                {
                    std::cout << "\n===TOP UP===\n";
                    rentalShop.topUp(userID);
                    std::cout << "===END SESSION===\n";
                    break;
                }
                case 9:
                {
                    std::cout << "\n===LIST NEW MOTORBIKE===\n";
                    rentalShop.listMotorbike(userID);
                    std::cout << "===END SESSION===\n";
                    break;
                }
                case 10:
                {
                    std::cout << "\n===UNLIST NEW MOTORBIKE===\n";
                    rentalShop.unlistMotorbike(userID);
                    std::cout << "===END SESSION===\n";
                    break;
                }
                case 11:
                {
                    std::cout << "\n===RETURN  MOTORBIKE===\n";
                    rentalShop.returnMotorBike(userID);
                    std::cout << "===END SESSION===\n";
                    break;
                }
                default:
                {
                    std::cout << "***Invalid choice!***\n";
                    break;
                }
                }
            } while (menuChoice != 0);
            break;
        }

// int main()
// {
//     System rentalShop{};

//     rentalShop.reloadDataMember();
//     rentalShop.reloadDataMotorbike();
//     rentalShop.reloadDataRenterRating();
//     rentalShop.reloadDataMotorRating();
//     rentalShop.reloadDataRequest();

//     MOTORBIKEID = rentalShop.getCurrentMotorID();
//     MEMMBERID = rentalShop.getCurrentMemID();
//     // rentalShop.listMotorbike(3);
//     // rentalShop.viewMotorbikeList();

//     // std::cout << "Current customer ID: " << MEMMBERID << '\n';
//     // std::cout << "Current motorbike ID: " << MOTORBIKEID;
//     // rentalShop.registerMember();
//     // rentalShop.topUp(2);
//     rentalShop.viewRequest(2);
//     // rentalShop.viewRequest(1);

//     // rentalShop.sendRequest(3);
//     // rentalShop.viewRequest(2);
//     // rentalShop.acceptRequest(2);
//     // rentalShop.viewRequest(2);
//     // rentalShop.viewMember(3);
//     // rentalShop.unlistMotorbike(3);
//     // rentalShop.viewMember(3);

//     // rentalShop.viewMotor(7);

//     // rentalShop.rateMotorbike(2);
//     // rentalShop.viewMember(1);

//     // Date d1{1, 1, 2003}, d2{1,1,2003};
//     // if(d2<d1)
//     // {
//     //     std::cout << "true\n";
//     // }
//     // else
//     // {
//     //     std::cout << "false\n";
//     // }

//     // rentalShop.AvailableList(1);

//     // std::cout << rentalShop.signIn();
// }
*/
