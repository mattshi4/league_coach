#pragma once

#include "frame_listener.h"
#include "process.h"

#include <functional>
#include <vector>
#include <string>

class ScreenshotAgent : public Process {
public:
    int run() override;
    int kill() override;

    void notify_listeners(std::string &frame_path);
    void bind_listener(FrameListener &listener);
private:
    std::vector<std::reference_wrapper<FrameListener>> listeners;
    bool running;
    std::string frame_dir;
};
