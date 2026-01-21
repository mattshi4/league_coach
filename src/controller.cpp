#include "controller.h"
#include "screenshot.h"
#include "league_coach.h"

int Controller::run() {
    // processes
    ScreenshotAgent screenshot_agent;
    LeagueCoach league_coach;
    processes.push_back(screenshot_agent);
    processes.push_back(league_coach);

    screenshot_agent.bind_listener(league_coach);

    screenshot_agent.run();
    league_coach.run();

    return 0;
}


int Controller::kill() {
    for (auto &p : processes) {
        p.kill();
    }

    return 0;
}
