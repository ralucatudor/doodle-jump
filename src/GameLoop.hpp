#pragma once

#include <SFML/Graphics.hpp>

#include "constants.hpp"
#include "GameState.hpp"

class GameLoop 
{
private:
    sf::RenderWindow window;

    void createWindow();
public:
    void pollEvents();

    void update();

    // void redrawFrame();
    void redrawFrame(const std::vector<sf::Drawable> &drawable);

    void init();

    const sf::RenderWindow& getWindow() const;
};