#ifndef MEMBER_RATING_
#define MEMBER_RATING_

#include <string>

#include "Member.h"
#include "Motorbike.h"

// this class is to preserve member rating, which a motorbike owner would given a rating to a member after rental
class MemberRating {
    Member *owner;
    Member *member;
    double rating_;
    std::string review_;

public:
    MemberRating(Member *owner, Member *member, double rating, std::string review);

    std::string toString();
    std::string serialize();

    friend class MemberRatingManager;
};

#endif
