// #include <SFML/Graphics.hpp> already included in the hpp
// same for #include <memory>
#include <iostream>
#include "Logger.hpp"

#include "GameLoop.hpp"
#include "Doodler.hpp"
#include "Platform.hpp"

#include "GameEngine.hpp"

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

    Logger::getInstance() << "Starting Doodle Jump..." << '\n';

    std::vector<std::shared_ptr<BaseEntity>> entities;

    GameLoop gameLoop;
    gameLoop.init();

    GameEngine gameEngine;

    for (size_t i = 0; i < PLATFORM_COUNT; ++i) {
        std::shared_ptr<Platform> platform = std::make_shared<Platform>(Platform());
        entities.emplace_back(platform);
    }

    std::shared_ptr<Doodler> doodler = std::make_shared<Doodler>(Doodler());

    entities.emplace_back(doodler);

    while (gameLoop.getWindow().isOpen()) {
        gameLoop.pollEvents(doodler);
        gameLoop.update(entities);
        gameEngine.checkCollision(entities);
        gameLoop.redrawFrame(entities);
    }

    return 0;
}