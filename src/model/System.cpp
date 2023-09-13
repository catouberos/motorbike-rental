#include "System.h"
void System::viewMotorbikeListGuest()
{
    for(Motorbike& motorbike : m_listMotorbikes)
    {
        std::cout << "\n";
        motorbike.printMotorbike();
        std::cout << "\n===\n\n";
    }
}

// void System::viewMemberListAdmin()
// {
//     int count{0};
//     for(Member& member : m_listMembers)
//     {
//         count++;
//         std::cout << count << ".\n";
//         member.printMemberAdmin();
//         std::cout << "\nOwner of motorbike:\n";
//         if(member.m_ownMotorbikeID != 0)
//         {
//             for(Motorbike& motorbike : this->m_listMotorbikes)
//             {
//                 if (motorbike.m_motorbikeID == member.m_ownMotorbikeID)
//                 {
//                     motorbike.printMotorbike();
//                 }
//             }
//         }
//         else
//         {
//             std::cout << "none:\n";
//         }
//         std::cout << "\nrenter of motorbike:\n";
//         if(member.m_rentMotorbikeID != 0)
//             for(Motorbike& motorbike : this->m_listMotorbikes)
//             {
//                 if (motorbike.m_motorbikeID == member.m_rentMotorbikeID)
//                 {
//                     motorbike.printMotorbike();
//                 }
//             }
//         else 
//         {
//             std::cout << "none:\n";
//         }
//         std::cout << '\n';
//     }
// }

bool System::reloadDataMember()
{
    std::fstream file;
    file.open("Customer.dat", std::ios::in);
    if (!file)
    {
        std::cout << "no saved list\n";
        return false;
    }

    while(file.peek()!=EOF)
    {
        std::string temp{""};
        std::string username{};
        std::string password{};
        std::string fullName{};
        std::string idType{};
        int idNumber{};
        int licenseNumber{};
        int creditPoint{};
        double renterRating{};
        int ownMotorbikeID{};
        int rentMotorbikeID{};
        int memberID{};

        std::getline(file, username, ',');
        std::getline(file, password, ',');
        std::getline(file, fullName, ',');
        std::getline(file, idType, ',');

        std::getline(file, temp, ',');
        idNumber = std::stoi(temp);

        std::getline(file, temp, ',');
        licenseNumber = std::stoi(temp);

        std::getline(file, temp, ',');
        creditPoint = std::stoi(temp);

        std::getline(file, temp, ',');
        renterRating = std::stod(temp);

        std::getline(file, temp, ',');
        ownMotorbikeID = std::stoi(temp);

        std::getline(file, temp, ',');
        rentMotorbikeID = std::stoi(temp);

        std::getline(file, temp, '\n');
        memberID = std::stoi(temp);

        this->m_listMembers.push_back({username, password, fullName, idType, idNumber, licenseNumber, creditPoint, renterRating, ownMotorbikeID, rentMotorbikeID, memberID});
    }

    file.close();
    int currentMemberID{0};
    for (Member& member : this->m_listMembers)
    {
        if(member.m_memberID > currentMemberID)
        {
            currentMemberID = member.m_memberID;
        }
    }
    this->m_currentMemID = currentMemberID;
    return true;
}

bool System::reloadDataMotorbike()
{
    std::fstream file;
    file.open("Motorbike.dat", std::ios::in);
    if (!file)
    {
        std::cout << "no saved list\n";
        return false;
    }

    while(file.peek()!=EOF)
    {
        std::string temp{""};
        std::string model{""};
        std::string color{""};
        int engineSize{};
        std::string transmissionMode{""};
        std::string description{""};
        std::string location{""};
        int yearMade{};
        double motorbikeRating{};
        double requiredRating{};
        int consumingPoint{};
        int dd{}, mm{}, yyyy{};
        int motorbikeID{};
        int ownerID{};
        int renterID{};

        std::getline(file, model, ',');
        std::getline(file, color, ',');
        std::getline(file, transmissionMode, ',');
        std::getline(file, description, ',');
        std::getline(file, location, ',');

        std::getline(file, temp, ',');
        engineSize = std::stoi(temp);

        std::getline(file, temp, ',');
        yearMade = std::stoi(temp);

        std::getline(file, temp, ',');
        motorbikeRating = std::stod(temp);

        std::getline(file, temp, ',');
        requiredRating = std::stod(temp);

        std::getline(file, temp, ',');
        consumingPoint = std::stoi(temp);

        std::getline(file, temp, ',');
        dd = std::stoi(temp);

        std::getline(file, temp, ',');
        mm = std::stoi(temp);

        std::getline(file, temp, ',');
        yyyy = std::stoi(temp);

        Date startDate{dd, mm, yyyy};

        std::getline(file, temp, ',');
        dd = std::stoi(temp);

        std::getline(file, temp, ',');
        mm = std::stoi(temp);

        std::getline(file, temp, ',');
        yyyy = std::stoi(temp);

        Date endDate{dd, mm, yyyy};

        std::getline(file, temp, ',');
        motorbikeID = std::stoi(temp);

        std::getline(file, temp, ',');
        ownerID = std::stoi(temp);

        std::getline(file, temp, '\n');
        renterID = std::stoi(temp);

        this->m_listMotorbikes.push_back({model, color, engineSize, transmissionMode, yearMade, description, requiredRating, consumingPoint, location, startDate, endDate, ownerID, motorbikeID, motorbikeRating, renterID});
    }

    file.close();
    int currentMotorbikeID{0};
    for (Motorbike& motorbike : this->m_listMotorbikes)
    {
        if(motorbike.m_motorbikeID > currentMotorbikeID)
        {
            currentMotorbikeID = motorbike.m_motorbikeID;
        }
    }
    this->m_currentMotorID = currentMotorbikeID;
    return true;
}

int System::getCurrentMotorID()
{
    // int currentMotorbikeID{0};
    // for (Motorbike& motorbike : this->m_listMotorbikes)
    // {
    //     if(motorbike.m_motorbikeID > currentMotorbikeID)
    //     {
    //         currentMotorbikeID = motorbike.m_motorbikeID;
    //     }
    // }
    // currentMotorbikeID = currentMotorbikeID;
    return this->m_currentMotorID;
}

int System::getCurrentMemID()
{
    // int currentCustomerID{0};
    // for (Member& member : this->m_listMembers)
    // {
    //     if(member.m_customerID > currentCustomerID)
    //     {
    //         currentCustomerID = member.m_customerID;
    //     }
    // }
    // currentCustomerID = currentCustomerID;
    return this->m_currentMemID;
}

void System::registerMember()
{
    std::string username{};
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    std::string password{};
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);

    std::string fullName{};
    std::cout << "Enter your fullName: ";
    std::getline(std::cin, fullName);

    std::string idType{};
    std::cout << "Enter your ID type: ";
    std::getline(std::cin, idType);

    int idNumber{};
    std::cout << "Enter your ID number: ";
    std::cin >> idNumber;
    std::cin.ignore();

    int licenseNum{};
    std::cout << "Enter your licnese number: ";
    std::cin >> licenseNum;
    std::cin.ignore();

    std::string confirmPassword{};
    std::cout << "The initial entry fee is $20, which will earn your account 20 credit point\n";
    std::cout << "Type your password to confirm transaction: ";
    std::getline(std::cin, confirmPassword);

    if(confirmPassword == password)
    {
        std::cout << "***Transaction confirmed!***\n";
        this->m_listMembers.push_back({username, password, fullName, idType, idNumber, licenseNum, 20, 5, 0, 0, ++m_currentMemID});
    }
    else
    {
        std::cout << "***Wrong password***\n";
        return;
    }
    std::cout << "***Registered sucessfully***\n";
}

int System::MemberIDtoIndex(int memberID)
{
    int count{0};
    for(Member& member : m_listMembers)
    {
        if(memberID == member.m_memberID)
        {
            return count;
        }
        count++;
    }
    return -1;
}

int System::MotorbikeIDtoIndex(int motorbikeID)
{
    int count{0};
    for(Motorbike& motorbike : m_listMotorbikes)
    {
        if(motorbikeID == motorbike.m_motorbikeID)
        {
            return count;
        }
        count++;
    }
    return -1;
}

void System::topUp(int memberID)
{
    Member &member = m_listMembers[MemberIDtoIndex(memberID)];
    int top{0};
    std::cout << "Enter the amount of credit point you want to buy ($1 = 1 credit point): ";
    std::cin >> top;
    std::cin.ignore();

    std::string confirmPassword{};
    // std::cout << m_listMembers[memberIndex].m_password <<  " Type your password to confirm transaction: ";
    std::cout << "Type your password to confirm transaction: ";
    std::getline(std::cin, confirmPassword);

    if(confirmPassword == member.m_password)
    {
        std::cout << "Transaction confirmed!\n";
        member.m_creditPoint += top;
    }
    else
    {
        std::cout << "Wrong password\n";
        return;
    }
}

void System::viewMember(int memberID)
{
    if(MemberIDtoIndex(memberID) < 0)
    {
        std::cout << "Cannot find member!";
        return;
    }
    Member member = m_listMembers[MemberIDtoIndex(memberID)];
    member.printMember();
    std::cout << "\nOwner of motorbike:\n";
    if(member.m_ownMotorbikeID != 0)
    {
        for(Motorbike& motorbike : this->m_listMotorbikes)
        {
            if (motorbike.m_motorbikeID == member.m_ownMotorbikeID)
            {
                motorbike.printMotorbike();
            }
        }
    }
    else
    {
        std::cout << "none:\n";
    }
    std::cout << "\nrenter of motorbike:\n";
    if(member.m_rentMotorbikeID != 0)
        for(Motorbike& motorbike : this->m_listMotorbikes)
        {
            if (motorbike.m_motorbikeID == member.m_rentMotorbikeID)
            {
                motorbike.printMotorbike();
            }
        }
    else 
    {
        std::cout << "none:\n";
    }
    std::cout << "\nRating:\n";
    for(RenterRating& rating : m_listRenterRating)
    {
        if (rating.m_renterID == member.m_memberID)
        {
            rating.printRenterRating();
            std::cout << "-\n";
        }
    }
    std::cout << "\n===\n\n";
}

void System::viewMemberAdmin(int memberID)
{
    if(MemberIDtoIndex(memberID) < 0)
    {
        std::cout << "Cannot find member!";
        return;
    }
    Member member = m_listMembers[MemberIDtoIndex(memberID)];
    member.printMemberAdmin();
    std::cout << "\nOwner of motorbike:\n";
    if(member.m_ownMotorbikeID != 0)
    {
        for(Motorbike& motorbike : this->m_listMotorbikes)
        {
            if (motorbike.m_motorbikeID == member.m_ownMotorbikeID)
            {
                motorbike.printMotorbike();
            }
        }
    }
    else
    {
        std::cout << "none:\n";
    }
    std::cout << "\nrenter of motorbike:\n";
    if(member.m_rentMotorbikeID != 0)
        for(Motorbike& motorbike : this->m_listMotorbikes)
        {
            if (motorbike.m_motorbikeID == member.m_rentMotorbikeID)
            {
                motorbike.printMotorbike();
            }
        }
    else 
    {
        std::cout << "none:\n";
    }
    std::cout << "\nRating:\n";
    for(RenterRating& rating : m_listRenterRating)
    {
        if (rating.m_renterID == member.m_memberID)
        {
            rating.printRenterRating();
            std::cout << "-\n";
        }
    }
    std::cout << "\n===\n\n";
}

void System::listMotorbike(int memberID)
{
    Member &member = m_listMembers[MemberIDtoIndex(memberID)];
    if(member.m_ownMotorbikeID != 0)
    {
        std::cout << "Member can only own 1 motorbike\n";
        return;
    }

    std::string model{};
    std::cout << "Enter model: ";
    std::getline(std::cin, model);

    std::string color{};
    std::cout << "Enter color: ";
    std::getline(std::cin, color);

    std::string transmissionMode{};
    std::cout << "Enter transmission mode: ";
    std::getline(std::cin, transmissionMode);

    std::string description{};
    std::cout << "Enter description: ";
    std::getline(std::cin, description);

    std::string location{};
    std::cout << "Enter location: ";
    std::getline(std::cin, location);

    int engineSize{};
    std::cout << "Enter engine size: ";
    std::cin >> engineSize;
    std::cin.ignore();

    int yearMade{};
    std::cout << "Enter year made: ";
    std::cin >> yearMade;
    std::cin.ignore();

    double requiredRating{};
    std::cout << "Enter required rating: ";
    std::cin >> requiredRating;
    std::cin.ignore();

    int consumingPoint{};
    std::cout << "Enter consuming point: ";
    std::cin >> consumingPoint;
    std::cin.ignore();

    int dd{}, mm{}, yyyy{};
    std::cout << "Enter start date (dd mm yyyy): ";
    std::cin >> dd >> mm >> yyyy;
    std::cin.ignore();
    Date startDate(dd, mm, yyyy);

    std::cout << "Enter end date (dd mm yyyy): ";
    std::cin >> dd >> mm >> yyyy;
    std::cin.ignore();
    Date endDate(dd, mm, yyyy);

    m_listMotorbikes.push_back({model, color, engineSize, transmissionMode, yearMade, description, requiredRating, consumingPoint, location, startDate, endDate, memberID, ++m_currentMotorID, 5, 0});
    member.m_ownMotorbikeID = m_currentMotorID;
    std::cout << "New motorbike listed!\n";
}

void System::unlistMotorbike(int memberID)
{
    Member &member = m_listMembers[MemberIDtoIndex(memberID)];
    if(member.m_ownMotorbikeID == 0)
    {
        std::cout << "You do not own any motorbike\n";
        return;
    }
    int motorIndex{MotorbikeIDtoIndex(member.m_ownMotorbikeID)};
    m_listMotorbikes.erase(m_listMotorbikes.begin() + motorIndex);
    member.m_ownMotorbikeID = 0;
    std::cout << "Motorbike unlisted!\n";
}

bool System::reloadDataRenterRating()
{
    std::fstream file;
    file.open("RatingRenter.dat", std::ios::in);
    if (!file)
    {
        std::cout << "no saved list\n";
        return false;
    }

    while(file.peek()!=EOF)
    {
        std::string review{""};
        std::string temp{""};
        double rating{};
        int ownerID{};
        int renterID{};

        std::getline(file, review, ',');

        std::getline(file, temp, ',');
        rating = std::stod(temp);

        std::getline(file, temp, ',');
        ownerID = std::stod(temp);

        std::getline(file, temp, '\n');
        renterID = std::stod(temp);

        this->m_listRenterRating.push_back({ownerID, renterID, rating, review});
    }

    file.close();
    return true;
}

bool System::reloadDataMotorRating()
{
    std::fstream file;
    file.open("RatingMotor.dat", std::ios::in);
    if (!file)
    {
        std::cout << "no saved list\n";
        return false;
    }

    while(file.peek()!=EOF)
    {
        std::string review{""};
        std::string temp{""};
        double rating{};
        int motorbikeID{};
        int renterID{};

        std::getline(file, review, ',');

        std::getline(file, temp, ',');
        rating = std::stod(temp);

        std::getline(file, temp, ',');
        motorbikeID = std::stod(temp);

        std::getline(file, temp, '\n');
        renterID = std::stod(temp);

        this->m_listMotorRating.push_back({renterID, motorbikeID, rating, review});
    }

    file.close();
    return true;
}

bool System::reloadDataRequest()
{
    std::fstream file;
    file.open("Request.dat", std::ios::in);
    if (!file)
    {
        std::cout << "no saved list\n";
        return false;
    }

    while(file.peek()!=EOF)
    {
        std::string temp{""};
        int senderID{};
        int receiverID{};

        std::getline(file, temp, ',');
        senderID = std::stoi(temp);

        std::getline(file, temp, '\n');
        receiverID = std::stoi(temp);

        this->m_listRequest.push_back({senderID, receiverID});
    }

    file.close();
    return true;
}

void System::viewMotor(int motorID)
{
    Motorbike temp{m_listMotorbikes[MotorbikeIDtoIndex(motorID)]};
    temp.printMotorbike();
    std::cout << "\nRating:\n";
    for(MotorbikeRating& rating : m_listMotorRating)
    {
        if(rating.m_motorbikeID == motorID)
        {
            rating.printMotorRating();
            std::cout << "-\n";
        }
    }
}

void System::rateMotorbike(int memberID)
{
    Member& rater{m_listMembers[MemberIDtoIndex(memberID)]};
    if(rater.m_rentMotorbikeID == 0)
    {
        std::cout << "***You are not renting any motorbike***\n";
        return;
    }
    for(MotorbikeRating& rating : m_listMotorRating)
    {
        if
        (
            rating.m_renterID == memberID &&
            rating.m_motorbikeID == rater.m_rentMotorbikeID
        )
        {
            std::cout << "***You have already rated this motorbike!***\n";
            return;
        }
    }
    Motorbike& rated{m_listMotorbikes[MotorbikeIDtoIndex(rater.m_rentMotorbikeID)]};
    std::cout << "Rate motorbike with motorbike ID " << rated.m_motorbikeID << '\n';
    double rating{};
    std::cout << "Enter your rating (1 - 10): ";
    std::cin >> rating;
    std::cin.ignore();
    if (rating < 1 || rating > 10)
    {
        std::cout << "***Invalid rating!***\n";
        return;
    }
    
    std::string review{""};
    std::cout << "Enter your review: ";
    std::getline(std::cin, review);

    rated.m_motorbikeRating = (rated.m_motorbikeRating + rating)/2;
    m_listMotorRating.push_back({rater.m_memberID, rated.m_motorbikeID, rating, review});
    std::cout << "***Rating recored***\n";
}

void System::rateRenter(int memberID)
{
    Member& rater{m_listMembers[MemberIDtoIndex(memberID)]};
    Motorbike& raterMotor{m_listMotorbikes[MotorbikeIDtoIndex(rater.m_ownMotorbikeID)]};

    if(raterMotor.m_renterID == 0)
    {
        std::cout << "***Your motorbike is not rented by anybody***\n";
        return;
    }
    for(RenterRating& rating : m_listRenterRating)
    {
        if
        (
            rating.m_ownerID == memberID &&
            rating.m_renterID == raterMotor.m_renterID
        )
        {
            std::cout << "***You have already rated this renter!***\n";
            return;
        }
    }
    Member& rated{m_listMembers[MemberIDtoIndex(raterMotor.m_renterID)]};
    std::cout << "Rate renter with member ID " << rated.m_memberID << '\n';
    double rating{};
    std::cout << "Enter your rating (1 - 10): ";
    std::cin >> rating;
    std::cin.ignore();
    if (rating < 1 || rating > 10)
    {
        std::cout << "***Invalid rating!***\n";
        return;
    }
    
    std::string review{""};
    std::cout << "Enter your review: ";
    std::getline(std::cin, review);

    rated.m_renterRating = (rated.m_renterRating + rating)/2;
    m_listRenterRating.push_back({memberID, rated.m_memberID, rating, review});
    std::cout << "***Rating recored***\n";
}

void System::AvailableList(int memberID)
{
    Member &member = m_listMembers[MemberIDtoIndex(memberID)];
    int dd{}, mm{}, yyyy{};
    std::cout << "Search available motorbike:\n";
    std::cout << "Please enter start date (dd mm yyyy):\n";
    std::cin >> dd >> mm >> yyyy;
    std::cin.ignore();
    Date startDate{dd, mm, yyyy};

    std::cout << "Please enter end date (dd mm yyyy)\n";
    std::cin >> dd >> mm >> yyyy;
    std::cin.ignore();
    Date endDate{dd, mm, yyyy};

    std::string location{};
    std::cout << "Please enter location\n";
    std::getline(std::cin, location);

    for (Motorbike& motorbike : m_listMotorbikes)
    {
        if
        (
            motorbike.m_consumingPoint <= member.m_creditPoint &&
            motorbike.m_requiredRating <= member.m_renterRating &&
            motorbike.m_startDate <= startDate &&
            motorbike.m_endDate >= endDate &&
            motorbike.m_location == location &&
            motorbike.m_renterID == 0
        )
        {
            std::cout << "\n";
            this->viewMotor(motorbike.m_motorbikeID);
            std::cout << "\n===\n\n";
        }
    }
}

void System::viewRequest(int memberID)
{
    Member member{m_listMembers[MemberIDtoIndex(memberID)]};
    std::cout << "Members that requested to rent your motorbike " << member.m_ownMotorbikeID << ":\n";
    for(Request& request : m_listRequest)
    {
        if(request.m_receiverID == memberID)
        {
            std::cout << "\n";
            this->viewMember(request.m_senderID);
            std::cout << "\n===\n\n";
        }
    }
}

void System::sendRequest(int memberID)
{
    int choice{};
    Member member{m_listMembers[MemberIDtoIndex(memberID)]};
    if(member.m_rentMotorbikeID!=0)
    {
        std::cout << "***You have already rented a motorbike!***\n";
        return;
    }
    std::cout << "Please choose the available motorbike ID from the available list: ";
    std::cin >> choice;
    std::cin.ignore();
    Motorbike motorbike{m_listMotorbikes[MotorbikeIDtoIndex(choice)]};
    if
    (!(
        motorbike.m_consumingPoint <= member.m_creditPoint &&
        motorbike.m_requiredRating <= member.m_renterRating &&
        motorbike.m_renterID == 0
    ))
    {
        std::cout << "***You cannot rent this motorbike due to low rating or credit point!***\n";
        return;
    }
    for(Request& request: m_listRequest)
    {
        if
        (
            request.m_receiverID == motorbike.m_ownerID &&
            request.m_senderID == memberID
        )
        {
            std::cout << "***You have already requested this motorbike***\n";
            return;
        }
    }
    m_listRequest.push_back({memberID, motorbike.m_ownerID});
    std::cout << "***Request sent!***\n";
}

void System::acceptRequest(int memberID)
{
    int accept{};
    std::cout << "Enter the requester's member ID you want to accept: ";
    std::cin >> accept;
    std::cin.ignore();
    Member owner{m_listMembers[MemberIDtoIndex(memberID)]};
    Motorbike& rentMotor{m_listMotorbikes[MotorbikeIDtoIndex(owner.m_ownMotorbikeID)]};
    Member& renter{m_listMembers[MemberIDtoIndex(accept)]};

    int count{0};
    int index{};
    bool found{false};
    for(Request& request : m_listRequest)
    {
        if 
        (
            request.m_receiverID == memberID &&
            request.m_senderID == accept
        )
        {
            index = count;
            found = true;
            break;
        }
        ++count;
    }
    if (!found)
    {
        std::cout << "***This member did not sent any request!***\n";
        return;
    }
    renter.m_creditPoint = renter.m_creditPoint - rentMotor.m_consumingPoint;
    renter.m_rentMotorbikeID = rentMotor.m_motorbikeID;
    rentMotor.m_renterID = accept;
    m_listRequest.erase(m_listRequest.begin() + index);
    std::cout << "***Request accepted!***\n";
}

void System::returnMotorBike(int memberID)
{
    Member& member{m_listMembers[MemberIDtoIndex(memberID)]};
    Motorbike& motor{m_listMotorbikes[MotorbikeIDtoIndex(member.m_rentMotorbikeID)]};

    if(member.m_rentMotorbikeID == 0)
    {
        std::cout << "***You have not rented any motorbike!***\n";
        return;
    }
    motor.m_renterID = 0;
    member.m_rentMotorbikeID = 0;
    std::cout << "***Return successfully!***\n";
}

int System::signIn()
{
    std::string username{};
    std::string password{};

    std::cout << "Enter your username: ";
    std::getline(std::cin, username);
    
    std::cout << "Enter your password: ";
    std::getline(std::cin, password);
    for(Member& member : m_listMembers)
    {
        if (member.m_username == username && member.m_password == password)
        {
            std::cout << "***SIGNED IN AS " << member.m_fullName << "***\n";
            return member.m_memberID;
        }
    }
    std::cout << "***invalid username or password!***\n";
    return -1;
}

bool System::adminSignIn()
{
    std::string username{};
    std::string password{};

    std::cout << "Enter your admin username: ";
    std::getline(std::cin, username);
    
    std::cout << "Enter your admin password: ";
    std::getline(std::cin, password);

    if(m_adminUsername == username && m_adminPassword == password)
    {
        std::cout << "***SIGNED IN AS ADMIN***\n";
        return true;
    }
    std::cout << "***Invalid admin account!***\n";
    return false;
}

void System::saveMember()
{
    std::ofstream outfile;
    
    if(!m_listMembers.empty()){ //true if vector size is 0, false otherwise
        outfile.open("customer.dat");
        if(!outfile){
            std::cerr << "Problem with the file.\n";
        }else{
            //store each object in vector students to file
            for(auto i : m_listMembers)
                outfile << i.toFile();
            
            outfile.close();
            std::cout << "Member list saved successfully.\n";        
        }
    }else{
        std::cout << "Member list is empty. 0 student is saved.\n";
    }
}

void System::saveMotorbike()
{
    std::ofstream outfile;
    
    if(!m_listMembers.empty()){ //true if vector size is 0, false otherwise
        outfile.open("Motorbike.dat");
        if(!outfile){
            std::cerr << "Problem with the file.\n";
        }else{
            //store each object in vector students to file
            for(auto i : m_listMotorbikes)
                outfile << i.toFile();
            
            outfile.close();
            std::cout << "Motorbike list saved successfully.\n";        
        }
    }else{
        std::cout << "Motorbike list is empty. 0 student is saved.\n";
    }
}

void System::saveRenterRating()
{
    std::ofstream outfile;
    
    if(!m_listMembers.empty()){ //true if vector size is 0, false otherwise
        outfile.open("RatingRenter.dat");
        if(!outfile){
            std::cerr << "Problem with the file.\n";
        }else{
            //store each object in vector students to file
            for(auto i : m_listRenterRating)
                outfile << i.toFile();
            
            outfile.close();
            std::cout << "Renter rating list saved successfully.\n";        
        }
    }else{
        std::cout << "Renter rating list is empty. 0 student is saved.\n";
    }
}

void System::saveMotorRating()
{
    std::ofstream outfile;
    
    if(!m_listMembers.empty()){ //true if vector size is 0, false otherwise
        outfile.open("RatingMotor.dat");
        if(!outfile){
            std::cerr << "Problem with the file.\n";
        }else{
            //store each object in vector students to file
            for(auto i : m_listMotorRating)
                outfile << i.toFile();
            
            outfile.close();
            std::cout << "Motor rating list saved successfully.\n";        
        }
    }else{
        std::cout << "Motor rating list is empty. 0 student is saved.\n";
    }
}

void System::saveRequest()
{
    std::ofstream outfile;
    
    if(!m_listMembers.empty()){ //true if vector size is 0, false otherwise
        outfile.open("Request.dat");
        if(!outfile){
            std::cerr << "Problem with the file.\n";
        }else{
            //store each object in vector students to file
            for(auto i : m_listRequest)
                outfile << i.toFile();
            
            outfile.close();
            std::cout << "Request list saved successfully.\n";        
        }
    }else{
        std::cout << "Request list is empty. 0 student is saved.\n";
    }
}

void System::viewMotorListAdmin()
{
    for(Motorbike& motorbike : m_listMotorbikes)
    {
        std::cout << '\n';
        this->viewMotor(motorbike.m_motorbikeID);
        std::cout << "\n===\n";
    }
}

void System::viewMemberListAdmin()
{
    for(Member& member : m_listMembers)
    {
        std::cout << '\n';
        this->viewMemberAdmin(member.m_memberID);
        std::cout << "\n===\n";
    }
}