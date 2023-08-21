/* Header file:  
*  Only contain declarations (prototypes) 
*  of classes/ functions/ user defined data types
*/

#ifndef _HOUSEHOLD_H_     
#define _HOUSEHOLD_H_     
/* make sure that this file will be included only once in compilation process
   (when the keyword _HOUSEHOLD_H_ is not defined before)
*/

#include "function.h"

#include <iostream>
using std::string;
using std::cout;

class HouseHold{
public:
    string name;
    HouseHold *purchasedPerson = NULL;

    //declarations of constructors/methods
    HouseHold (string name);
    void showinfo();
};

#endif

