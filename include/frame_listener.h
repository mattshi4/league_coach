#pragma once

#include <string>
#include <vector>
#include <functional>

// Allows classes to bind to ScreenshotAgent without needing to bind
// entire class
class FrameListener {
public:
    FrameListener(const std::function<void(std::string)> &callback);
    void notify(std::string frame_path);
private:
    std::function<void(std::string)> callback_;
};
