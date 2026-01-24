cmake_minimum_required(VERSION 3.20)
project("personal_analyst" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(personal_analyst
    src/main.cpp
    src/controller.cpp
    src/screenshot_agent.cpp
    src/league_analyst.cpp
    src/frame_listener.cpp
)

target_include_directories(personal_analyst PRIVATE include)
