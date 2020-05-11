#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"

class BaseEntity : public sf::Drawable, public sf::Transformable
// inherit Transformable for getposition() and Drawable for draw()
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

