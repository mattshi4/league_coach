#pragma once

// int should be changed to some sort of status enum when we add error handling
class Process {
public:
    virtual ~Process() = default;
    virtual int run() = 0;
    virtual int kill() = 0;
};
