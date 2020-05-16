// #include <SFML/Graphics.hpp> already included in the hpp
// same for #include <memory>
#include <iostream>

#include "GameEngine.hpp"

void displayGameOverWindow(GameLoop&);

int main(int argc, char* argv[])
{
    if (argc > 1) {
        const std::string arg = argv[1];
        if (arg == "--help") {
            std::cout << "Usage: doodle-jump\n"
                      << "Options:\n"
                      << "  --help: show help information\n";
            return 0;
        }
    }
    
    GameEngine gameEngine;

    gameEngine.run();

    return 0;
}