#ifndef DATE_H_
#define DATE_H_

class Date
{
    unsigned int year_;
    unsigned int month_;
    unsigned int day_;

public:
    Date(unsigned int year, unsigned int month, unsigned int day);

    bool operator==(Date &d);

    bool operator<(Date &d);

    bool operator>(Date &d);

    bool operator<=(Date &d);

    bool operator>=(Date &d);
};

#endif