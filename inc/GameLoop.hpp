#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "DEFINITIONS.hpp"
#include "BaseEntity.hpp"
#include "Doodler.hpp"
#include "Platform.hpp"

#include "Score.hpp"

class GameLoop 
{
private:
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    sf::Clock clock;

    float deltaTime = 0;

    void createWindow();

    Score<float> totalScore;
public:
    void pollEvents(const std::shared_ptr<Doodler>&);

    void update(const std::vector<std::shared_ptr<BaseEntity>>&);

    void updateScore(const std::shared_ptr<Doodler>& );

    void redrawFrame(const std::vector<std::shared_ptr<BaseEntity>>&);

    void init();

    sf::RenderWindow& getWindow();
};