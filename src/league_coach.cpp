#include "league_coach.h"

#include <memory>
#include <iostream>

LeagueCoach::LeagueCoach() {
    listener_ = std::make_unique<FrameListener>();
    FrameListener &l = *listener_;
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
