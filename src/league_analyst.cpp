#include "league_analyst.h"

#include <memory>
#include <iostream>

LeagueAnalyst::LeagueAnalyst() {
    listener_ = std::make_unique<FrameListener>();
    FrameListener &l = *listener_;
}

int LeagueAnalyst::run() {
    return 0;
}

int LeagueAnalyst::kill() {
    return 0;
}

FrameListener& LeagueAnalyst::get_listener() {
    return *listener_;
}
