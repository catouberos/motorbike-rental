#include "Date.h"

bool operator==(Date& d1, Date& d2)
{
    return (d1.m_day == d2.m_day && d1.m_month == d2.m_month && d1.m_year == d2.m_year);
}

void Date::printDate()
{
    std::cout << m_day << "/" << m_month << '/' << m_year;
}

bool operator< (Date& d1, Date& d2)
{
    if(d1.m_year < d2.m_year)
    {
        return true;
    }
    else if(d1.m_year == d2.m_year && d1.m_month < d2.m_month)
    {
        return true;
    }
    else if(d1.m_year == d2.m_year && d1.m_month == d2.m_month && d1.m_day <d2.m_day)
    {
        return true;
    }
    return false;
}

bool operator> (Date& d1, Date& d2)
{
    return operator<(d2, d1);
}

bool operator<= (Date& d1, Date& d2)
{
    return !operator>(d1, d2);
}

bool operator>= (Date& d1, Date& d2)
{
    return !operator<(d1, d2);
}