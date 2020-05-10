#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "constants.hpp"
#include "BaseEntity.hpp"
#include "Doodler.hpp"
#include "Platform.hpp"

class GameLoop 
{
private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Clock clock;

    float deltaTime = 0;

    void createWindow();
public:
    void pollEvents(const std::shared_ptr<Doodler>&);

    void update(const std::vector<std::shared_ptr<BaseEntity>>&);

    void redrawFrame(const std::vector<std::shared_ptr<BaseEntity>>&);

    void init();

    sf::RenderWindow& getWindow();
};