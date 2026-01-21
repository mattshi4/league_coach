#pragma once

#include "frame_listener.h"
#include "process.h"

#include <vector>
#include <vector>
#include <string>

class ScreenshotAgent : public Process {
public:
    // we need to somehow also determine that one is actually in a league game
    int run() override;
    int kill() override;

    int get_frame();
    int notify_listeners();
    int bind_listener(FrameListener listener);
private:
    std::vector<FrameListener> listeners;
    bool running;
    std::string frame_dir;
};
