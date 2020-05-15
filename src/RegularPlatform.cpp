#include "RegularPlatform.hpp"

RegularPlatform::RegularPlatform() : Platform()
{
    texture.loadFromFile(PLATFORM_FILEPATH);
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

unsigned RegularPlatform::getSpeed()
{
    return 10;
}