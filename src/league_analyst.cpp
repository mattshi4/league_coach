#include "league_analyst.h"

#include <functional>
#include <memory>
#include <string>
#include <iostream>

LeagueAnalyst::LeagueAnalyst() {
    listener_ = std::make_unique<FrameListener>(
        [this](const std::string &frame_path) {
            analyse(frame_path);
        }
    );
}

int LeagueAnalyst::run() {
    return 0;
}

int LeagueAnalyst::kill() {
    return 0;
}

void LeagueAnalyst::analyse(const std::string &frame_path) {
    frame_paths_.push_back(frame_path);
    // we must turn the image binary into base64 so that chat can understand it
    // next we must look into setting up our request struct / chat history
    return;
}

FrameListener& LeagueAnalyst::get_listener() {
    return *listener_;
}
