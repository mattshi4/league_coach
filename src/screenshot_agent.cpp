#include <screenshot_agent.h>

#include <filesystem>

namespace fs = std::filesystem;

int ScreenshotAgent::run() {
    running = true;
    // create a temp directory - perhaps one day we set up a db
    // TODO: one day the directory generation will be nicer 
    frame_dir = "random_ahh_name";
    fs::create_directory(frame_dir);
    while (running) {
        // take a screenshot, there is no support for cpp screenshots lol!
        // mac api only supports swift and objective c. Instead we will
        // directly run a shell command using screencapture
        // we can use the -D option to specify which display. By default 
        // we should assume that league is on the main display
        // TODO: write an objective C function that will take screenshots for us
    
        // save it in a temp directory
    }
}
