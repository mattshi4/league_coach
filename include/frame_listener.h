#pragma once

#include <string>

class FrameListener {
public:
    void notify(std::string frame_path);
};
