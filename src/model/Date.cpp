#include "Date.h"

Date::Date(unsigned int year, unsigned int month, unsigned int day) : year_(year), month_(month), day_(day) {}

bool Date::operator==(Date &d)
{
    return (day_ == d.day_ && month_ == d.month_ && year_ == d.year_);
}

bool Date::operator<(Date &d)
{
    if (year_ < d.year_)
    {
        return true;
    }

    if (year_ == d.year_ && month_ < d.month_)
    {
        return true;
    }

    if (year_ == d.year_ && month_ == d.month_ && day_ < d.day_)
    {
        return true;
    }

    return false;
}

bool Date::operator>(Date &d)
{
    return d < *this;
}

bool Date::operator<=(Date &d)
{
    return !(*this > d);
}

bool Date::operator>=(Date &d)
{
    return !(*this < d);
}