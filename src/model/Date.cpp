#include <sstream>
#include <iomanip>

#include "Date.h"

//Default constructor
Date::Date() : year_(0), month_(0), day_(0) {}

//Constructor with string Input 
Date::Date(std::string date)
{
    // assume the input is always correct, parse as yyyy/mm/dd
    year_ = std::stoi(date.substr(0, 4));
    month_ = std::stoi(date.substr(5, 2));
    day_ = std::stoi(date.substr(8, 2));
}

//Constructor with specified year, month, and day components provided as arguments.
Date::Date(unsigned int year, unsigned int month, unsigned int day) : year_(year), month_(month), day_(day) {}

//returns the date components formatted as "dd/mm/yyyy."
std::string Date::toString()
{
    return std::to_string(day_) + "/" + std::to_string(month_) + "/" + std::to_string(year_);
}

//returns the year component of the Date object.
unsigned int Date::getYear()
{
    return year_;
}

//returns the month component of the Date object.
unsigned int Date::getMonth()
{
    return month_;
}

//returns the day component of the Date object.
unsigned int Date::getDay()
{
    return day_;
}

//returns a string representation suitable for storage.
std::string Date::serialize()
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

//returns true if the year, month, and day components of the two Date objects are equal; 
//otherwise, it returns false.
bool Date::operator==(Date &d)
{
    return (day_ == d.day_ && month_ == d.month_ && year_ == d.year_);
}

//returns true if the year, month, or day components of the two Date objects are not equal; 
//otherwise, it returns false.
bool Date::operator!=(Date &d)
{
    return !(*this == d);
}
//returns true if the Date object on the left is chronologically earlier than the Date object on the right; 
//otherwise, it returns false.
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

//returns true if the Date object on the left is chronologically later than the Date object on the right; 
//otherwise, it returns false.
bool Date::operator>(Date &d)
{
    return d < *this;
}

//returns true if the Date object on the left is chronologically earlier or equal to the Date object on the right; 
//otherwise, it returns false.
bool Date::operator<=(Date &d)
{
    return !(*this > d);
}

//returns true if the Date object on the left is chronologically later or equal to the Date object on the right; 
//otherwise, it returns false.
bool Date::operator>=(Date &d)
{
    return !(*this < d);
}
