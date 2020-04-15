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

void GameLoop::redrawFrame(const std::vector<sf::Drawable>& drawable)
{
    window.clear(sf::Color::Green);
    std::for_each(drawable.begin(), drawable.end(), [&](const sf::Drawable& item) -> void {
        window.draw(item);
    });
    window.display();
}

void GameLoop::update()
{
}
