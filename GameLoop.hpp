#pragma once

#include <SFML/Graphics.hpp>

#include "constants.hpp"

class GameLoop 
{
private:
    sf::RenderWindow window;

    void createWindow();
public:
    void pollEvents();

    void update();

    void redrawFrame();


    void init();

    const sf::RenderWindow& getWindow() const;
};