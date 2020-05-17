#include "FastPlatform.hpp"

FastPlatform::FastPlatform() : Platform()   // position is set is the base class Platform
{
    texture.loadFromFile(FAST_PLATFORM_FILEPATH);
    sprite.setTexture(texture);
}

FastPlatform::~FastPlatform() {}

unsigned FastPlatform::getDistance()
{
    return FAST_PLATFORM_DISTANCE;
}