#include "league_coach.h"

#include <memory>

LeagueCoach::LeagueCoach() {
    listener_ = std::make_unique<FrameListener>();
}

int LeagueCoach::run() {
    return 0;
}

int LeagueCoach::kill() {
    return 0;
}

FrameListener& LeagueCoach::get_listener() {
    return *listener_;
}
