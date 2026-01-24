#pragma once

// header file ordering: your headers, stdlib, 3rd party libraries
#include "process.h"

#include <memory>
#include <vector>

class Controller : public Process{
public:
    int run() override;
    int kill() override;
private:
    std::vector<std::unique_ptr<Process>> processes;
};
