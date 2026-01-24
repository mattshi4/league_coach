#pragma once

#include <string>
#include <vector>
#include <functional>

class FrameListener {
public:
    void notify(std::string frame_path);
private:
    std::function<void()> callback_;
};
