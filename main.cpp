#include <iostream>

#include "Logger.hpp"
#include "GameEngine.hpp"

void displayGameOverWindow(GameLoop&);

int main(int argc, char* argv[])
{
    if (argc > 1) {
        const std::string arg = argv[1];
        if (arg == "--help") {
            Logger::getInstance() << "Usage: doodle-jump\n"
                                  << "Options:\n"
                                  << "  --help: show help information\n";
        }
    }
    
    GameEngine gameEngine;

    gameEngine.run();

    return EXIT_SUCCESS;
}