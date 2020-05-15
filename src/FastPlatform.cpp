#include "FastPlatform.hpp"

FastPlatform::FastPlatform() : Platform()
{
    texture.loadFromFile(FAST_PLATFORM_FILEPATH);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

unsigned FastPlatform::getSpeed()
{
    return 15;
}