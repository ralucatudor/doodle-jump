#include "FastPlatform.hpp"

FastPlatform::FastPlatform() : Platform()
{
    texture.loadFromFile(FAST_PLATFORM_FILEPATH);
    sprite.setTexture(texture);
    sprite.setPosition(position);

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<unsigned> x(0, WINDOW_WIDTH - getTextureSize().x);
    std::uniform_int_distribution<unsigned> y(0, WINDOW_HEIGHT - 30);

    position.x = x(generator);
    position.y = y(generator);
}

unsigned FastPlatform::getDistance()
{
    return FAST_PLATFORM_DISTANCE;
}