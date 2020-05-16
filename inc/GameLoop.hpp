#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "DEFINITIONS.hpp"
#include "BaseEntity.hpp"
#include "Doodler.hpp"
#include "PlatformCreator.hpp"

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

    std::shared_ptr<Doodler> doodler;
public:
    
    Entities entities;

    GameLoop();

    Score<float> totalScore;        // public because I display the final score at the end, in main
    
    void pollEvents();

    void update();

    void updateScore();

    void redrawFrame();

    sf::RenderWindow& getWindow();
};