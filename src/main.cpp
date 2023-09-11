#include <iostream>
#include <ostream>

int main() {
    // clear the console
    std::cout << "\033[2J\033[1;1H";

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

    // prompt the user to login
    std::cout << "Use the app as: [1] Guest, [2] Member, [3] Admin" << std::endl 
              << std::endl;
    std::cout << "Enter your choice: ";
    return 0;
}
