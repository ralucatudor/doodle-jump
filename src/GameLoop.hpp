#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "constants.hpp"
#include "BaseEntity.hpp"

class GameLoop 
{
private:
    sf::RenderWindow& window;
    sf::Clock clock;

    float deltaTime = 0;

    void createWindow();
public:
    GameLoop(sf::RenderWindow&, sf::Clock);

    ~GameLoop() = default;

    void pollEvents(const std::shared_ptr<BaseEntity>&);

    void update(const std::vector<std::shared_ptr<BaseEntity>>&);

    void redrawFrame(const std::vector<std::shared_ptr<BaseEntity>>&);

    void init();
};