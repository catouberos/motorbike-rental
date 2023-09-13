#ifndef DATE_H_
#define DATE_H_

#include <string>

class Date
{
    unsigned int year_;
    unsigned int month_;
    unsigned int day_;

public:
    Date(std::string date);

    Date(unsigned int year, unsigned int month, unsigned int day);

    std::string toString();

    bool operator==(Date &d);

    bool operator<(Date &d);

    bool operator>(Date &d);

    bool operator<=(Date &d);

    bool operator>=(Date &d);
};

#endif