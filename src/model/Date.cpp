#include <sstream>
#include <iomanip>

#include "Date.h"

Date::Date(std::string date)
{
    // assume the input is always correct, parse as yyyy/mm/dd
    year_ = std::stoi(date.substr(0, 4));
    month_ = std::stoi(date.substr(5, 2));
    day_ = std::stoi(date.substr(8, 2));
}

Date::Date(unsigned int year, unsigned int month, unsigned int day) : year_(year), month_(month), day_(day) {}

std::string Date::toString()
{
    std::ostringstream oss;

    // this will print as yyyy/mm/dd
    oss << std::setw(4) << std::setfill('0') << year_;
    oss << "/";
    oss << std::setw(2) << std::setfill('0') << month_;
    oss << "/";
    oss << std::setw(2) << std::setfill('0') << day_;

    return oss.str();
}

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