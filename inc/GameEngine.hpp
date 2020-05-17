#pragma once

#include <memory>
#include <random>

#include "GameLoop.hpp"
#include "Logger.hpp"

// Game engine responsible for collision detection & running and stopping the game
class GameEngine
{
private:
    GameLoop gameLoop;

    const lambda<void> processCollisionForEach = [&](const std::shared_ptr<Platform>& platform) -> void {
        processCollision(platform);
    };

    const lambda<bool, Doodler> checkGameOver = [&](const std::shared_ptr<Doodler>& doodler) {
        return (doodler != nullptr && doodler->getPosition().y > WINDOW_HEIGHT);
    };

    void processCollision(const std::shared_ptr<Platform>&);

    bool doesIntersect(const std::shared_ptr<Platform>&) const;
public:
    ~GameEngine();

    void checkCollision();

    void run();

    void displayGameOverWindow();
};