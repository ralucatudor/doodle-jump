#include "GameEngine.hpp"

GameEngine::~GameEngine() {}

void GameEngine::checkCollision()
{
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());

    gameLoop.doodler->set_dy(gameLoop.doodler->get_dy() + 0.2f);
    gameLoop.doodler->setUpDownPosition();

    if (gameLoop.doodler->getPosition().y < DOODLER_HEIGHT) {    // I maintain my doodler at DOODLER_HEIGHT
        gameLoop.doodler->setPosition({gameLoop.doodler->getPosition().x, DOODLER_HEIGHT});

		for (auto& platform : gameLoop.platforms) { 
            platform->setPosition({platform->getPosition().x, platform->getPosition().y - gameLoop.doodler->get_dy()}); // vertical translation
            if (platform->getPosition().y > WINDOW_HEIGHT) {
                // Set new platform on the top    
                std::uniform_int_distribution<unsigned> x(0, WINDOW_WIDTH - platform->getTextureSize().x);	
                platform->setPosition({static_cast<float>(x(generator)), 0});

                if (std::shared_ptr<SlowPlatform> sp = std::dynamic_pointer_cast<SlowPlatform>(platform)) {
                    if (sp->getHasCollision() == true) {
                        sp->setHasCollision(false);
                    }
                }
            }
        }
	}

    std::for_each(gameLoop.platforms.begin(), gameLoop.platforms.end(), processCollisionForEach); 
}

void GameEngine::processCollision(const std::shared_ptr<Platform>& platform)
{ 
    if (doesIntersect(platform)) {
        if (std::dynamic_pointer_cast<SlowPlatform>(platform)) {
            // Init statement for if - Feature of C++17
            if (std::shared_ptr<SlowPlatform> sp = std::dynamic_pointer_cast<SlowPlatform>(platform); sp->getHasCollision() == false) {
                gameLoop.doodler->set_dy(-static_cast<float>(platform->getDistance()));// Distance travelled when jumping on this platform
                sp->setHasCollision(true);
            }
            // Note: I do not call setHasCollision if the doodler intersects a SlowPlatform that has "hasCollision" = true
            // because this means that the platform is not visible.
        } else {
            gameLoop.doodler->set_dy(-static_cast<float>(platform->getDistance()));
        }
    }
}

bool GameEngine::doesIntersect(const std::shared_ptr<Platform>& platform) const
{
    if ((gameLoop.doodler->getPosition().x + DOODLER_RIGHT_BOUNDING_BOX > platform->getPosition().x)
        && (gameLoop.doodler->getPosition().x + DOODLER_LEFT_BOUNDING_BOX < platform->getPosition().x + platform->getTextureSize().x) 
        && (gameLoop.doodler->getPosition().y + DOODLER_BOTTOM_BOUNDING_BOX > platform->getPosition().y)
        && (gameLoop.doodler->getPosition().y + DOODLER_BOTTOM_BOUNDING_BOX < platform->getPosition().y + platform->getTextureSize().y)
        && (gameLoop.doodler->get_dy() > 0))
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
        checkCollision();
        gameLoop.redrawFrame();

        gameIsOver = checkGameOver(gameLoop.doodler);
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
    // Center the final score text
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