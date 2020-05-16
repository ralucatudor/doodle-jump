#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"

// inherit Drawable for draw()
// Note: I could've also inherited sf::Transformable for getposition(), but I eventually wrote my own method.
class BaseEntity : public sf::Drawable
{
protected: 
    sf::Vector2f position;
    
    sf::Texture texture;
    
    sf::Sprite sprite;
public:
    virtual sf::Vector2f getPosition() const = 0;

    virtual void setPosition(sf::Vector2f ) = 0;

    virtual sf::Vector2u getTextureSize() = 0;
};

