#include "GameLoop.hpp"

#include <iostream>

void GameLoop::createWindow()
{   
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    window.setFramerateLimit(MAX_FPS);    
}

sf::RenderWindow& GameLoop::getWindow()
{
    return window;
}

GameLoop::GameLoop()
{
    if (!window.isOpen()) {
        createWindow();
    }        
                            
    backgroundTexture.loadFromFile(BACKGROUND_FILEPATH);
    backgroundSprite.setTexture(backgroundTexture);

    for (size_t i = 0; i < PLATFORM_COUNT; ++i) {
        // x MOD 4 => 0 1 2 3 | MOD 3 => 0 1 2 0 | + 1 => 1 2 3 1 
        int type = (i % 4) % 3 + 1;
        platforms.emplace_back(PlatformCreator::getPlatform(type));
    }

    doodler = std::make_shared<Doodler>(Doodler());
}

GameLoop::~GameLoop() {}

void GameLoop::pollEvents()
{
    deltaTime = clock.restart().asSeconds();
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else {
            doodler->handleKeyboardInput(event);
        }
    }    
}

void GameLoop::update()
{        
    doodler->updatePosition(deltaTime);
    std::for_each(platforms.begin(), platforms.end(), [&](const std::shared_ptr<Platform>& item) -> void {
        item->updatePosition();
    });
}

void GameLoop::updateScore()
{
    if (doodler->getPosition().y == DOODLER_HEIGHT && doodler->get_dy() < (-1.62)) {
        Score<float> addScore(0.5);
		totalScore = totalScore + addScore;
	}
}

void GameLoop::redrawFrame()
{
    window.draw(backgroundSprite);

    sf::Font font;
	font.loadFromFile(FONT_FILEPATH);
    sf::Text scoreText;
	scoreText.setFont(font);   
    scoreText.setCharacterSize(40);
	scoreText.setFillColor(sf::Color::Black);
    
	scoreText.setString( "Score: " + std::to_string(static_cast<int>(totalScore.getScore())));
    
    window.draw(scoreText);

    // draw doodler
    window.draw(*doodler);
    // draw platforms
    std::for_each(platforms.begin(), platforms.end(), 
        [&](const std::shared_ptr<Platform>& item) -> void {
            if (std::shared_ptr<SlowPlatform> sp = std::dynamic_pointer_cast<SlowPlatform>(item)) {
                if (sp->getHasCollision() == false) {
                    window.draw(*item);
                }
            }else{
                window.draw(*item);
            }
        });

    window.display();
}
