#include <ostream>
#include <string>
#include <vector>
#include <fstream>

#include "./utils/Utils.h"

#include "./prompt/Prompt.h"

#include "./manager/MemberManager.h"
#include "./manager/MotorbikeManager.h"

#include "./model/Date.h"
#include "./model/Motorbike.h"
#include "./model/Account.h"
#include "./model/System.h"
#include "./model/Rating.h"

int main()
{
    MotorbikeManager motorbikeManager;
    MemberManager memberManager;

    // load the member
    motorbikeManager.init();
    memberManager.init(motorbikeManager);

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

        switch (mainChoice)
        {
        case (0):
            break;
            // guest application

        case (1):
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
                    Prompt::guestViewMotorbikes(motorbikeManager);
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
        case (2):
            Utils::clrscr();

            if (Prompt::loginMember(memberManager) == true)
            {
                int userChoice;

                do
                {
                    Utils::clrscr();

                    Member *current_member = memberManager.getMemberFromId(memberManager.current_member_id_);
                    Motorbike *current_rent = current_member->getRentedMotorbike();

                    std::cout << "EEET2482 ASSIGNMENT" << std::endl
                              << "MOTORBIKE RENTAL APPLICATION" << std::endl
                              << std::endl
                              << "Welcome, " << current_member->getFullName() << std::endl;

                    if (current_rent != nullptr)
                    {
                        std::cout << "You are currently renting a bike from " << current_rent->getStartDate().toString() << " to " << current_rent->getEndDate().toString() << std::endl
                                  << std::endl;
                    }

                    std::cout << "[1] View your information" << std::endl
                              << std::endl
                              << "[0] Exit" << std::endl
                              << std::endl
                              << "Enter your choice: ";
                    std::cin >> userChoice;
                    std::cin.ignore();
                } while (userChoice != 0);
            }
            break;

        // admin application
        case (3):
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
                } while (adminChoice != 0);
            }
            break;

        default:
            break;
        }
    } while (mainChoice != 0);

    memberManager.save();
    motorbikeManager.save();

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
                    std::cout << "0. Exit\n";
                    std::cout << "1. View information\n";
                    std::cout << "2. Rate the motorbike you are renting\n";
                    std::cout << "3. Rate current renter\n";
                    std::cout << "4. Search available motorbike\n";
                    std::cout << "5. Request motorbike\n";
                    std::cout << "6. View request list\n";
                    std::cout << "7. Accept request\n";
                    std::cout << "8. Top up credit point\n";
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
