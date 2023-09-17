#include "MemberRating.h"
#include <sstream>

MemberRating::MemberRating(Member *owner, Member *member, double rating, std::string review)
    : owner{owner}, member{member}, rating_{rating}, review_{review} {}

std::string MemberRating::toString()
{
    std::ostringstream oss;

    oss << "Rating from " << owner->getFullName() << std::endl
        << "Rating: " << rating_ << std::endl
        << "Review: " << review_ << std::endl;

    return oss.str();
}

std::string MemberRating::serialize()
{
    std::ostringstream oss;

    oss << owner->id_ << ","
        << member->id_ << ","
        << rating_ << ","
        << review_;

    return oss.str();
}
