#include "RegularPlatform.hpp"

RegularPlatform::RegularPlatform() : Platform()     // position is set is the base class Platform
{
    texture.loadFromFile(PLATFORM_FILEPATH);
    sprite.setTexture(texture);
}

RegularPlatform::~RegularPlatform() {}

unsigned RegularPlatform::getDistance()
{
    return REGULAR_PLATFORM_DISTANCE;
}