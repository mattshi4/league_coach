#include "frame_listener.h"

#include <string>

void FrameListener::notify(std::string frame_path) {
    callback_(frame_path);
}
