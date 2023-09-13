#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#ifndef DATE_H
#define DATE_H
class Date
{
    int m_day{};
    int m_month{};
    int m_year{};

public:
    Date() = default;
    Date(int dd, int mm, int yyyy) :m_day{dd}, m_month{mm}, m_year{yyyy}{}

    friend class Motorbike;
    
    friend bool operator==(Date& d1, Date& d2);

    void printDate();

    friend bool operator< (Date& d1, Date& d2);


    friend bool operator> (Date& d1, Date& d2);

    friend bool operator<= (Date& d1, Date& d2);

    friend bool operator>= (Date& d1, Date& d2);

};
#endif