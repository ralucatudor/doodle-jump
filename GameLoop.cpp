#include "GameLoop.hpp"

void GameLoop::createWindow()
{
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(MAX_FPS);
}

const sf::RenderWindow& GameLoop::getWindow() const
{
    return window;
}

void GameLoop::init()
{
    if (!window.isOpen()) {
        createWindow();
    }
}

