// #include <SFML/Graphics.hpp> already included in the hpp
// same for #include <memory>
#include <iostream>
#include "Logger.hpp"

#include "GameLoop.hpp"
#include "Doodler.hpp"
#include "Platform.hpp"

#include "GameEngine.hpp"

void displayGameOverWindow(GameLoop&);

int main(int argc, char* argv[])
{
    if (argc > 1) {
        const std::string arg = argv[1];
        if (arg == "--help") {
            std::cout << "Usage: doodle-jump\n"
                      << "Options:\n"
                      << "  --help: show help information\n";
            return 0;
        }
    }

    Logger::getInstance() << "Starting Doodle Jump..." << '\n';

    std::vector<std::shared_ptr<BaseEntity>> entities;

    GameLoop gameLoop;
    gameLoop.init();

    for (size_t i = 0; i < PLATFORM_COUNT; ++i) {
        /* std::shared_ptr<Platform> platform = std::make_shared<Platform>(Platform());
           entities.emplace_back(platform); */
           
        entities.emplace_back(std::shared_ptr<Platform>(new Platform()));   // heap memory allocation
    }

    std::shared_ptr<Doodler> doodler = std::make_shared<Doodler>(Doodler());

    entities.emplace_back(doodler);
    
    GameEngine gameEngine;


    while (gameLoop.getWindow().isOpen()) {
        gameLoop.pollEvents(doodler);
        gameLoop.update(entities);
        gameLoop.updateScore(doodler);
        gameEngine.checkCollision(entities);
        gameLoop.redrawFrame(entities);

        bool gameIsOver = (doodler != nullptr && doodler->getPosition().y > WINDOW_HEIGHT);
        if (gameIsOver) {
            displayGameOverWindow(gameLoop);
            break;
        }
    }

    return 0;
}

void displayGameOverWindow(GameLoop& gameLoop) {
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