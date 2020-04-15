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

void GameLoop::pollEvents()
{
    sf::Event event{};
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                break;
            default:
                break;
        }
    }
}

void GameLoop::redrawFrame()
{
    sf::Texture texture;                          
    texture.loadFromFile("background.png");
    sf::Sprite background(texture);
    window.draw(background);
    window.display();
}

void GameLoop::update()
{
}
