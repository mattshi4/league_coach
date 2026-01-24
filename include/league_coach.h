#pragma once

#include "frame_listener.h"
#include "process.h"

#include <memory>
#include <vector>
#include <string>

class LeagueCoach : public Process {
public:
    LeagueCoach();

    int run() override;
    int kill() override;

    FrameListener& get_listener();
private:
    std::unique_ptr<FrameListener> listener_;
    std::vector<std::string> frame_paths_;
};
