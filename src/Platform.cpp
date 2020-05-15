#include "Platform.hpp"

#include <random>

void Platform::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

Platform::Platform() 
{
    // texture.loadFromFile(PLATFORM_FILEPATH);
    // sprite.setTexture(texture);
    // sprite.setPosition(position);

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<unsigned> x(0, WINDOW_WIDTH - texture.getSize().x);
    std::uniform_int_distribution<unsigned> y(0, WINDOW_HEIGHT - 30);

    position.x = x(generator);
    position.y = y(generator);
}

Platform::Platform(const Platform& ob) 
{
    texture = ob.texture;
    sprite = ob.sprite;
    position = ob.position;
    sprite.setTexture(texture);
}

void Platform::updatePosition()
{
    sprite.setPosition(position);
}

sf::Vector2f Platform::getPosition() const
{
    return position;
} 

sf::Vector2u Platform::getTextureSize() 
{
    return texture.getSize();
}

void Platform::setPosition(sf::Vector2f newPosition) 
{
    position = newPosition;
}