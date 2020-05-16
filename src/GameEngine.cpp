#include "GameEngine.hpp"

#include <iostream>

#include <random>

void GameEngine::checkCollision(Entities& entities)
{
    std::shared_ptr<BaseEntity> doodlerEntity = *std::find_if(entities.begin(), entities.end(), isDoodler);

    //std::shared_ptr<Doodler> doodler (std::dynamic_pointer_cast<Doodler>(doodlerEntity)); 
    doodler = std::dynamic_pointer_cast<Doodler>(doodlerEntity);  

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());

    doodler->dy += 0.2;             // mai bine pui dy privat si faci getter si setter
    doodler->setUpDownPosition();

    if (doodler->getPosition().y < DOODLER_HEIGHT) {    // I maintain my doodler at DOODLER_HEIGHT
        doodler->setPosition({doodler->getPosition().x, DOODLER_HEIGHT});

		for (auto& entity : entities) { 
            if (std::dynamic_pointer_cast<Platform>(entity))    //(dynamic_cast<Platform*>(entity.get()))
            { 
                entity->setPosition({entity->getPosition().x, entity->getPosition().y - doodler->dy}); // vertical translation
                if (entity->getPosition().y > WINDOW_HEIGHT) {
                    // set new platform on the top    
                    std::uniform_int_distribution<unsigned> x(0, WINDOW_WIDTH - entity->getTextureSize().x);	
                    entity->setPosition({static_cast<float>(x(generator)), 0});

                    if (std::shared_ptr<SlowPlatform> sp = std::dynamic_pointer_cast<SlowPlatform>(entity)) {
                        if (sp->getHasCollision() == true) {
                            sp->setHasCollision(false);
                        }
                    }
                }
            }
        }
	}

    std::for_each(entities.begin(), entities.end(), processCollisionForEach); 
}

void GameEngine::processCollision(const std::shared_ptr<BaseEntity>& entity)
{ 
    // Init statement for if - Feature of C++17
    if (std::shared_ptr<Platform> platform = std::dynamic_pointer_cast<Platform>(entity); doesIntersect(platform)) {
        //doodler->dy = -static_cast<int>(platform->getSpeed());  // Distance travelled when jumping on this platform
    
        if (std::shared_ptr<SlowPlatform> sp = std::dynamic_pointer_cast<SlowPlatform>(platform)) {
            if (sp->getHasCollision() == false) {
                doodler->dy = -static_cast<int>(platform->getSpeed()); 
                sp->setHasCollision(true);
            }
        } else {
            doodler->dy = -static_cast<int>(platform->getSpeed()); 
        }
    }
}

bool GameEngine::doesIntersect(const std::shared_ptr<BaseEntity>& platform) const
{
    if ((doodler->getPosition().x + DOODLER_RIGHT_BOUNDING_BOX > platform->getPosition().x)
        && (doodler->getPosition().x + DOODLER_LEFT_BOUNDING_BOX < platform->getPosition().x + platform->getTextureSize().x) 
        && (doodler->getPosition().y + DOODLER_BOTTOM_BOUNDING_BOX > platform->getPosition().y)
        && (doodler->getPosition().y + DOODLER_BOTTOM_BOUNDING_BOX < platform->getPosition().y + platform->getTextureSize().y)
        && (doodler->dy > 0))
        return 1;
    return 0;
}


void GameEngine::run() 
{
    Logger::getInstance() << "Starting Doodle Jump..." << '\n';

    bool gameIsOver = false;
    while (gameLoop.getWindow().isOpen() && !gameIsOver) 
    {
        gameLoop.pollEvents();
        gameLoop.update();
        gameLoop.updateScore();
        checkCollision(gameLoop.entities);
        gameLoop.redrawFrame();

        gameIsOver = checkGameOver(doodler);
    }
    if (gameIsOver) {
        displayGameOverWindow();
    }
}


void GameEngine::displayGameOverWindow() {
    Logger::getInstance() << "Doodle Jump Over!" << '\n';

    gameLoop.getWindow().clear(sf::Color::Black);

    sf::Font font;
	font.loadFromFile("res/font/arial.ttf");
    sf::Text gameoverText;
    gameoverText.setFont(font);
    gameoverText.setString("Game Over!");
    gameoverText.setCharacterSize(60);
    gameoverText.setFillColor(sf::Color::White);
    gameoverText.setPosition(40, 200);

    gameLoop.getWindow().draw(gameoverText);

    // Display final score

    sf::Text finalScoreText;
	finalScoreText.setFont(font);   
    finalScoreText.setCharacterSize(40);
	finalScoreText.setFillColor(sf::Color::White);
	finalScoreText.setString( "Score: " + std::to_string( static_cast<int>( gameLoop.totalScore.getScore() ) ) );
    // center the final score text
    finalScoreText.setPosition(WINDOW_WIDTH/2.0f, WINDOW_HEIGHT/2.0f); //Window width divided by 2, same with height.
    finalScoreText.setOrigin(finalScoreText.getLocalBounds().width/2.0f, finalScoreText.getLocalBounds().height/2.0f);

    gameLoop.getWindow().draw(finalScoreText);
    
    gameLoop.getWindow().display();

    sf::Event event;
    while (gameLoop.getWindow().isOpen()) {
        while (gameLoop.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                gameLoop.getWindow().close();
            }
        }
    }
}