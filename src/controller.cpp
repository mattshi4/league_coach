#include "controller.h"
#include "screenshot_agent.h"
#include "league_analyst.h"

#include <iostream>
#include <memory>
#include <thread>
#include <utility>

int Controller::run() {
    // create the processes
    auto screenshot_agent = std::make_unique<ScreenshotAgent>();
    auto league_analyst = std::make_unique<LeagueAnalayst>();

    // business logic
    screenshot_agent->bind_listener(league_analyst->get_listener());

    // add processes and run them concurently. To decouple, kill logic 
    // is managed in main
    processes.push_back(std::move(screenshot_agent));
    processes.push_back(std::move(league_analyst));
    for (auto &p : processes) {
        std::thread([ptr = p.get()] {
            ptr->run();
        }).detach(); 
    }

    return 0;
}


int Controller::kill() {
    for (auto &p : processes) {
        p->kill();
    }

    return 0;
}
