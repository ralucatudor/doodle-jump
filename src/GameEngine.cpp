#include "GameEngine.hpp"

#include <random>
//#include <iostream>

void GameEngine::checkCollision(std::vector<std::shared_ptr<BaseEntity>>& entities)
{
    // std::shared_ptr<BaseEntity> doodler2 = *std::find_if(entities.begin(), entities.end(), isDoodler);

    // std::shared_ptr<Doodler> actualDoodler (std::dynamic_pointer_cast<Doodler>(doodler2));
    // actualDoodler->sayHello();

    doodler = *std::find_if(entities.begin(), entities.end(), isDoodler);

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());

    doodler->dy += 0.2;
	// playerY += dy;
    doodler->testupdate();

    if (doodler->getPosition().y < DOODLER_HEIGHT) {
        doodler->getPosition().y = DOODLER_HEIGHT;
		for (auto& entity : entities) { 
            //if (dynamic_cast<Platform*>(entity.get())) {
            if (std::dynamic_pointer_cast<Platform>(entity)) {
			    //entity->getPosition().y += (doodler->getDeltaY()) / 20;//dy;  // vertical translation
                entity->getPosition().y -= doodler->dy;
                if (entity->getPosition().y > WINDOW_HEIGHT) // set new platform on the top
                {
                    entity->getPosition().y = 0;
                    std::uniform_int_distribution<unsigned> x(0, WINDOW_WIDTH - entity->getTextureSize().x);
                    entity->getPosition().x = x(generator);				
                }
            }
        }
	}
    //std::cout << doodler->getDeltaY()<<'\n';

    std::for_each(entities.begin(), entities.end(), applyForEach);
}

void GameEngine::processCollision(const std::shared_ptr<BaseEntity>& entity)
{
    if (doesIntersect(entity)) {
        //doodler->updateCollision();
        doodler->dy = -10;
    }
}

bool GameEngine::doesIntersect(const std::shared_ptr<BaseEntity>& platform) const
{
    //std::cout << doodler->getPosition().x << ' '<<doodler->getPosition().y<<'\n';
    if ((doodler->getPosition().x + DOODLER_RIGHT_BOUNDING_BOX > platform->getPosition().x)
        && (doodler->getPosition().x + DOODLER_LEFT_BOUNDING_BOX < platform->getPosition().x + platform->getTextureSize().x) 
        && (doodler->getPosition().y + DOODLER_BOTTOM_BOUNDING_BOX > platform->getPosition().y)
        && (doodler->getPosition().y + DOODLER_BOTTOM_BOUNDING_BOX < platform->getPosition().y + platform->getTextureSize().y)
        && (doodler->dy > 0)) //dy > 0
        return 1;
    return 0;
}