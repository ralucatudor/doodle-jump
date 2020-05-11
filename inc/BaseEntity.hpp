#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"

class BaseEntity : public sf::Drawable
// inherit Drawable for draw()
// I could've also inherited sf::Transformable for getposition(), 
// but I eventually wrote my own method.
{
protected: 
    sf::Vector2f position;
    
    sf::Texture texture;
    sf::Sprite sprite;
public:
    virtual void updatePosition(const float) {}
    virtual void updatePosition() {}

    virtual sf::Vector2f getPosition() const = 0;

    virtual void setPosition(sf::Vector2f ) = 0;

    virtual sf::Vector2u getTextureSize() = 0;
};

