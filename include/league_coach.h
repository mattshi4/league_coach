#pragma once

#include "frame_listener.h"
#include "process.h"

#include <vector>
#include <string>

class LeagueCoach : public Process, public FrameListener {
public:
    int run() override;
    int kill() override;
    void notify(std::string frame_path) override;
private:
    std::vector<std::string> frame_paths;
};
