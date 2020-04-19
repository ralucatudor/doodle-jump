#include "Platform.hpp"

#include <random>

void Platform::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(platformSprite, states);
}

Platform::Platform() 
{
    platformTexture.loadFromFile("img/platform.png");
    platformSprite.setTexture(platformTexture);
    platformSprite.setPosition(position);

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<unsigned> x(0, WINDOW_WIDTH - platformTexture.getSize().x);
    std::uniform_int_distribution<unsigned> y(0, WINDOW_HEIGHT - 30);

    position.x = x(generator);
    position.y = y(generator);
}

Platform::Platform(const Platform& ob) 
{
    platformTexture = ob.platformTexture;
    platformSprite = ob.platformSprite;
    position = ob.position;
    platformSprite.setTexture(platformTexture);
}

void Platform::updatePosition()
{
    platformSprite.setPosition(position);
    setPosition(position);
}

sf::Vector2f& Platform::getPosition()
{
    return position;
} 

sf::Vector2u Platform::getTextureSize() {
    return platformTexture.getSize();
}