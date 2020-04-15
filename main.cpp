// #include <SFML/Graphics.hpp> already included in the hpp
#include <iostream>
#include "GameLoop.hpp"

int main(int argc, char* argv[])
{

    if (argc > 1)
    {
        const std::string arg = argv[1];
        if (arg == "--help")
        {
            std::cout << "Usage: doodle-jump\n"
                      << "Options:\n"
                      << "  --help: show help information\n";
            return 0;
        }
    }

    GameLoop gameLoop;  //  the main game loop - basically an infinite loop that only ends when the game is closed

    gameLoop.init();

    // while (gameLoop.getWindow().isOpen())
    // {
    //     gameLoop.pollEvents();
    //     gameLoop.update();
    //     gameLoop.redrawFrame();
    // }

    return 0;
}