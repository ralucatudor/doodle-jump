// #include <SFML/Graphics.hpp> already included in the hpp
// same for #include <memory>
#include <iostream>
#include "GameLoop.hpp"
#include "Doodler.hpp"

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

    std::vector<std::shared_ptr<BaseEntity>> entities;

    sf::RenderWindow window;
    sf::Clock clock;

    GameLoop gameLoop(window, clock);   // the main game loop - basically an infinite loop that only ends when the game is closed
    gameLoop.init();

    std::shared_ptr<Doodler> doodler = std::make_shared<Doodler>(Doodler());

    entities.push_back(doodler);

    while (window.isOpen()) {
        gameLoop.pollEvents(doodler);
        gameLoop.update(entities);
        gameLoop.redrawFrame(entities);
    }

    return 0;
}