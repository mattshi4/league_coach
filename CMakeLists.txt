cmake_minimum_required(VERSION 3.20)
project("league_coach" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(league_coach
    src/main.cpp
    src/controller.cpp
    src/screenshot_agent.cpp
    src/league_coach.cpp
    src/frame_listener.cpp
)

target_include_directories(league_coach PRIVATE include)
