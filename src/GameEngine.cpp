#include "GameEngine.hpp"

#include <random>

void GameEngine::checkCollision(std::vector<std::shared_ptr<BaseEntity>>& entities)
{
    std::shared_ptr<BaseEntity> doodlerEntity = *std::find_if(entities.begin(), entities.end(), isDoodler);

    //std::shared_ptr<Doodler> doodler (std::dynamic_pointer_cast<Doodler>(doodlerEntity)); 
    doodler =std::dynamic_pointer_cast<Doodler>(doodlerEntity);  

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());

    doodler->dy += 0.2;
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
                }
            }
        }
	}

    std::for_each(entities.begin(), entities.end(), processCollisionForEach); 
}

void GameEngine::processCollision(const std::shared_ptr<BaseEntity>& entity)
{
    if (doesIntersect(entity)) {
        doodler->dy = -10;
    }
}

bool GameEngine::doesIntersect(const std::shared_ptr<BaseEntity>& platform) const
{
    if ((doodler->getPosition().x + DOODLER_RIGHT_BOUNDING_BOX > platform->getPosition().x)
        && (doodler->getPosition().x + DOODLER_LEFT_BOUNDING_BOX < platform->getPosition().x + platform->getTextureSize().x) 
        && (doodler->getPosition().y + DOODLER_BOTTOM_BOUNDING_BOX > platform->getPosition().y)
        && (doodler->getPosition().y + DOODLER_BOTTOM_BOUNDING_BOX < platform->getPosition().y + platform->getTextureSize().y)
        && (doodler->dy > 0)) //dy > 0
        return 1;
    return 0;
}