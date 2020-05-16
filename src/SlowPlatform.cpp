#include "SlowPlatform.hpp"

SlowPlatform::SlowPlatform() : Platform()
{
    texture.loadFromFile(SLOW_PLATFORM_FILEPATH);
    sprite.setTexture(texture);
    sprite.setPosition(position);

    hasCollision = false;
}

unsigned SlowPlatform::getSpeed()
{
    return 7;
}