#include "GameLoop.hpp"

GameLoop::GameLoop(sf::RenderWindow& window, sf::Clock clock) : window(window), clock(clock) {}

void GameLoop::createWindow()
{
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(MAX_FPS);
}

void GameLoop::init()
{
    if (!window.isOpen()) {
        createWindow();
    }
}

void GameLoop::pollEvents()
{
    deltaTime = clock.restart().asSeconds();
    sf::Event event{};
    while (window.pollEvent(event)) {
        switch (event.type) {
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

void GameLoop::redrawFrame(const std::vector<std::shared_ptr<BaseEntity>>& entities)
{
    //window.clear(sf::Color::Cyan);
    sf::Texture texture;                          
    texture.loadFromFile("img/background.png");
    sf::Sprite background(texture);
    window.draw(background);

    std::for_each(entities.begin(), entities.end(), 
        [&](const std::shared_ptr<BaseEntity> item) -> void {
            window.draw(*item);
        });

    window.display();
}

void GameLoop::update(const std::vector<std::shared_ptr<BaseEntity>>& entities)
{
    std::for_each(entities.begin(), entities.end(), 
        [&](const std::shared_ptr<BaseEntity> item) -> void {
            item->updatePosition(deltaTime);
        });
}
