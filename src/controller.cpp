#include "controller.h"
#include "screenshot_agent.h"
#include "league_coach.h"

#include <memory>
#include <utility>

int Controller::run() {
    // create the processes, there should only ever be one
    auto screenshot_agent = std::make_unique<ScreenshotAgent>();
    auto league_coach = std::make_unique<LeagueCoach>();

    processes.push_back(std::move(screenshot_agent));
    processes.push_back(std::move(league_coach));

    screenshot_agent->bind_listener(league_coach->get_listener());

    screenshot_agent->run();
    league_coach->run();

    return 0;
}


int Controller::kill() {
    for (auto &p : processes) {
        p->kill();
    }

    return 0;
}
