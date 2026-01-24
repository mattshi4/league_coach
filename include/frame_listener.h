#pragma once

#include <string>

class FrameListener {
public:
    virtual ~FrameListener() = default;
    virtual void notify(std::string frame_path) = 0;
};
