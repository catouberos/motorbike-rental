#ifndef MEMBER_RATING_MANAGER_
#define MEMBER_RATING_MANAGER_

#include <vector>
#include <string>

#include "../model/MemberRating.h"
#include "MemberManager.h"

class MemberRatingManager {
    std::vector<MemberRating *> ratings_;

public:
    MemberRatingManager();
    ~MemberRatingManager();

    bool add(MemberRating *rating);

    double getAverageRating(unsigned int member_id);

    std::vector<MemberRating *> getRatings();

    std::vector<MemberRating *> getRatingsByOwnerId(unsigned int id);

    std::vector<MemberRating *> getRatingsByMemberId(unsigned int id);

    bool init(MemberManager &memberManager);

    bool save();
};

#endif
