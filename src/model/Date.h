#ifndef DATE_H_
#define DATE_H_

#include <string>

class Date
{
    unsigned int year_;
    unsigned int month_;
    unsigned int day_;

public:
    // default date constructor, default to 0000/00/00
    Date();

    Date(std::string date);

    Date(unsigned int year, unsigned int month, unsigned int day);

    std::string toString();

    std::string serialize();

    bool operator==(Date &d);

    bool operator<(Date &d);

    bool operator>(Date &d);

    bool operator<=(Date &d);

    bool operator>=(Date &d);
};

#endif
