#include "screenshot_agent.h"
#include "frame_listener.h"

#include <filesystem>
#include <atomic>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

// we want screenshots to be taken every second. The easy way to do this
// is to just add a 1 second sleep in the loop. But this is sequential
// the actual work (taking the screenshot, saving it etc) will take however
// many ms. This means that we are actually taking a screenshot every 1 + x
// seconds which is not what we want. Instead we will spawn a thread that
// will continually update the 
void timer_begin(std::atomic<bool> &go) {
    while (true) {
        std::cout << "start sleep\n";
        std::this_thread::sleep_until(std::chrono::steady_clock::now() + std::chrono::seconds(1));
        std::cout << "end sleep\n";
        go.store(true);
    }
};

int ScreenshotAgent::run() {
    running = true;
    // create a temp directory - perhaps one day we set up a db
    // TODO: one day the directory generation will be nicer 
    frame_dir = "random_ahh_name";
    std::filesystem::create_directory(frame_dir);
    std::string ss_command = "screencapture -D1 ";

    std::atomic<bool> go(false);
    // TODO: there is def a better way to do this, can probs decouple from this func
    std::thread(timer_begin, std::ref(go)).detach();

    int photo_num = 0;
    while (running) {
        if (go.exchange(true)) {
            // take a screenshot, there is no support for cpp screenshots lol!
            // mac api only supports swift and objective c. Instead we will
            // directly run a shell command using screencapture
            // we can use the -D option to specify which display. By default 
            // we should assume that league is on the main display
            // TODO: write an objective C function that will take screenshots for us
            std::string frame_path = frame_dir + "/" + std::to_string(photo_num) + ".png";
            std::string cmd = ss_command + frame_path;
            std::system(cmd.c_str());
            std::cout << "A frame has been saved\n";

            notify_listeners(frame_path);
            std::cout << "Listeners have been notified\n";

            photo_num++;
        }
    }

    return 0;
}

int ScreenshotAgent::kill() {
    // I want to keep the folder for now
    // std::filesystem::remove_all(frame_dir);
    return 0;
}

void ScreenshotAgent::notify_listeners(std::string &frame_path) {
    for (FrameListener &l : listeners) {
        l.notify(frame_path);
    }
}

void ScreenshotAgent::bind_listener(FrameListener &listener) {
    listeners.push_back(listener);
}
