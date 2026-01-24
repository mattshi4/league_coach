#include "controller.h"

#include <iostream>
#include <string>

int main() {
    Controller controller;

    std::cout << "Initialising league coach!\n";
    controller.run();
    std::cout << "Running, type 'q' and enter to shut down league coach!\n";

    // listen for a q command from user
    char command;
    while (true) {
        std::cin >> command;
        if (command == 'q') {
            break;
        }
    }
    controller.kill();
    std::cout << "Successfully shut down!\n";
}
