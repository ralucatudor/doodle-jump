#include "GameLoop.hpp"

GameLoop::GameLoop(sf::RenderWindow& window, sf::Clock clock) : window(window), clock(clock) {}

void GameLoop::createWindow() const
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

void GameLoop::pollEvents(const std::shared_ptr<BaseEntity>& entity)
{
    deltaTime = clock.restart().asSeconds();
    sf::Event event{};
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed: {
                switch (event.key.code) {
                    case sf::Keyboard::Left:
                        entity->keysMap[sf::Keyboard::Left] = true;
                        break;
                    case sf::Keyboard::Right:
                        entity->keysMap[sf::Keyboard::Right] = true;
                        break;
                    default:
                        break;
                }
                break;
            }
            case sf::Event::KeyReleased:
                switch (event.key.code) {
                    case sf::Keyboard::Left:
                        entity->keysMap[sf::Keyboard::Left] = false;
                        break;
                    case sf::Keyboard::Right:
                        entity->keysMap[sf::Keyboard::Right] = false;
                        break;
                    default:
                        break;
                }
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
    // std::for_each(entities.begin(), entities.end(), 
    //     [&](const std::shared_ptr<BaseEntity> item) -> void {
    //         item->updatePosition(deltaTime);
    //     });

    std::for_each(entities.begin(), entities.end(), [&](const std::shared_ptr<BaseEntity> item) -> void {
        if (dynamic_cast<Doodler*>(item.get()))
        {
            item->updatePosition(deltaTime);
        } else if (dynamic_cast<Platform*>(item.get()))
        {
            item->updatePosition();
        }
    });

}
