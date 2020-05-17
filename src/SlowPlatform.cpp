#include "SlowPlatform.hpp"

SlowPlatform::SlowPlatform() : Platform()   // position is set is the base class Platform
{
    texture.loadFromFile(SLOW_PLATFORM_FILEPATH);
    sprite.setTexture(texture);

    hasCollision = false;
}

SlowPlatform::~SlowPlatform() {}

unsigned SlowPlatform::getDistance()
{
    return SLOW_PLATFORM_DISTANCE;
}

bool SlowPlatform::getHasCollision() const 
{
    return hasCollision;
}

void SlowPlatform::setHasCollision(bool value) 
{
    hasCollision = value;
}