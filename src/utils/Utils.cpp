#include "Utils.h"

//clear the screen
void Utils::clrscr()
{
    std::cout << "\033[2J\033[1;1H";
}
