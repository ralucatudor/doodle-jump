#pragma once

#include <memory>
#include <functional>

#include "GameLoop.hpp"

#include "Logger.hpp"

template<typename T, typename R = BaseEntity>
using Lambda = std::function<T(const std::shared_ptr<R> &)>;

// Game engine responsible for collision detection & running and stopping the game
class GameEngine
{
private:
    GameLoop gameLoop;

    std::shared_ptr<Doodler> doodler;

    const Lambda<bool> isDoodler = [&](const std::shared_ptr<BaseEntity>& entity) -> bool {
        return (dynamic_cast<Doodler*>(entity.get()));
    };

    const Lambda<void> processCollisionForEach = [&](const std::shared_ptr<BaseEntity>& entity) -> void {
        if (isDoodler(entity)) {
            return;
        }
        processCollision(entity);
    };

    const Lambda<bool, Doodler> checkGameOver = [&](const std::shared_ptr<Doodler>& doodler) {
        return (doodler != nullptr && doodler->getPosition().y > WINDOW_HEIGHT);
    };

    void processCollision(const std::shared_ptr<BaseEntity>&);

    bool doesIntersect(const std::shared_ptr<BaseEntity>&) const;
public:
    void checkCollision(Entities& entities);

    void run();

    void displayGameOverWindow();
};