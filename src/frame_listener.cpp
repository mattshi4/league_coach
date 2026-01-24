#include "frame_listener.h"

#include <string>
#include <functional>

FrameListener::FrameListener(const std::function<void(std::string)> &callback) 
    : callback_(callback)
{}

void FrameListener::notify(std::string frame_path) {
    callback_(frame_path);
}
