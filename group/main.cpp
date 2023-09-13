#include <string>
#include <vector>
#include <fstream>
#include "Date.h"
#include "Motorbike.h"
#include "Account.h"
#include "System.h"
#include "Rating.h"


int main()
{
    System rentalShop{};
    if
    (
        rentalShop.reloadDataMember() == false ||
        rentalShop.reloadDataMotorbike() == false ||
        rentalShop.reloadDataRenterRating() == false ||
        rentalShop.reloadDataMotorRating() == false ||
        rentalShop.reloadDataRequest() == false
    )
    {
        std::cout << "***There is no data to be load!\n***";
        return 0;
    }
    // rentalShop.reloadDataMember();
    // rentalShop.reloadDataMotorbike();
    // rentalShop.reloadDataRenterRating();
    // rentalShop.reloadDataMotorRating();
    // rentalShop.reloadDataRequest();

    std::cout << rentalShop.getCurrentMotorID() << ' ' << rentalShop.getCurrentMemID() << '\n';

    std::cout << "Use the app as    1. Guest     2. Member   3. Admin\n\n";
    std::cout << "Enter your choice: ";
    int choice{};
    std::cin >> choice;
    std::cin.ignore();

    switch (choice)
    {
        case 1:
        {
            std::cout << "***USING AS A GUEST USER***\n";
            int menuChoice{};
            do
            {
                std::cout << "This is your menu:\n";
                std::cout << "0. Exit\n";
                std::cout << "1. Register\n";
                std::cout << "2. View all motorbikes\n";
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
                        std::cout << "\n===REGISTRATION===\n";
                        rentalShop.registerMember();
                        std::cout << "===END SESSION===\n";
                        break;
                    }    
                    case 2:
                    {
                        std::cout << "\n===ALL MOTORBIKES' DETAILS===\n";
                        rentalShop.viewMotorbikeListGuest();
                        std::cout << "===END SESSION===\n";
                        break;
                    }  
                    default:
                    {
                        std::cout << "***Invalid choice!***\n";
                        break;;
                    }
                }
            } while (menuChoice !=0);
            break;
            
        }
        case 2:
        {
            int userID{rentalShop.signIn()};
            if(userID == -1)
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

        case 3:
        {
            if (!rentalShop.adminSignIn())
            {
                break;
            }
            int menuChoice{};
            do
            {
                std::cout << "This is your menu:\n";
                std::cout << "0. Exit\n";
                std::cout << "1. View all member\n";
                std::cout << "2. View all motorbikes\n";
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
                        std::cout << "\n===MEMBER ADMIN LIST===\n";
                        rentalShop.viewMemberListAdmin();
                        std::cout << "===END SESSION===\n";
                        break;
                    }    
                    case 2:
                    {
                        std::cout << "\n===MOTORBIKE ADMIN LIST===\n";
                        rentalShop.viewMotorListAdmin();
                        std::cout << "===END SESSION===\n";
                        break;
                    }  
                    default:
                    {
                        std::cout << "***Invalid choice!***\n";
                        break;
                    }
                }
            } while (menuChoice !=0);
            break;
        }

        default:
        {
        std::cout << "***Invalid choice!***\n";
        break;
        }
    }

    std::cout << "\n\n===SAVING===\n\n";
    rentalShop.saveMember();
    rentalShop.saveMotorbike();
    rentalShop.saveRenterRating();
    rentalShop.saveMotorRating();
    rentalShop.saveRequest();
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


// int main()
// {
//     std::cout << "Use the app as 1. Guest   2. Member   3. Admin\n\n";
//     int choice{};
//     std::cout << "Enter your choice: ";
//     std::cin >> choice;
//     std::cin.ignore();

//     switch (choice)
//     {
//     case 1:
//         std::cout << "This is your menu:\n";
//         std::cout << "0. Exit\n";
//         std::cout << "1. Register\n";
//         std::cout << "2. View all motorbike details\n";
//         std::cout << "1. Register\n";

//         break;

//     case 2:
//         std::cout << "This is your menu:\n";
//         std::cout << "0. Exit\n";
//         std::cout << "1. Register\n";
//         std::cout << "2. View all motorbike details\n";
//         std::cout << "1. Register\n";

//         break;
//     default:
//         break;
//     }
// }


