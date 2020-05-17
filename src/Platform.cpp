#include "Platform.hpp"

void Platform::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

Platform::Platform() 
{
    texture.loadFromFile(PLATFORM_FILEPATH);
    sprite.setTexture(texture);

    sprite.setPosition(position);

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<unsigned> x(0, WINDOW_WIDTH - getTextureSize().x);
    std::uniform_int_distribution<unsigned> y(0, WINDOW_HEIGHT - 30);

    position.x = x(generator);
    position.y = y(generator);
}

Platform::~Platform() {}

Platform::Platform(const Platform& other) 
{
    texture = other.texture;
    sprite = other.sprite;
    position = other.position;
    sprite.setTexture(texture);
}

Platform& Platform::operator=(const Platform& other)
{
    if (this == &other) {
        return *this;
    }

    texture = other.texture;
    sprite = other.sprite;
    sprite.setTexture(texture);
    position = other.position;

    return *this;
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