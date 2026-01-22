#include <screenshot_agent.h>

#include <filesystem>
#include <atomic>
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
        std::this_thread::sleep_until(std::chrono::steady_clock::now() + std::chrono::seconds(1));
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
    timer_begin(go);

    int photo_num = 0;
    while (running) {
        if (go.exchange(true)) {
            // take a screenshot, there is no support for cpp screenshots lol!
            // mac api only supports swift and objective c. Instead we will
            // directly run a shell command using screencapture
            // we can use the -D option to specify which display. By default 
            // we should assume that league is on the main display
            // TODO: write an objective C function that will take screenshots for us
            std::string save_path = frame_dir + "/" std::to_string(photo_num);
            std::string cmd = ss_command + frame_dir + "/" + std::to_string(photo_num);
            std::system(cmd.c_str);

            photo_num++;
        }
    }
}
