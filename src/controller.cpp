#include "controller.h"
#include "screenshot_agent.h"
#include "league_coach.h"
#include <memory>

int Controller::run() {
    // processes
    auto screenshot_agent = std::make_unique<ScreenshotAgent>();
    auto league_coach = std::make_unique<LeagueCoach>();

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
