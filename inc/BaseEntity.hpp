#pragma once

#include <SFML/Graphics.hpp>
#include "constants.hpp"

class BaseEntity : public sf::Drawable, public sf::Transformable
// inherit Transformable for getposition() and Drawable for draw()
{
// maybe declare texture and sprite protected?
public:
    virtual void updatePosition(const float) {}
    virtual void updatePosition() {}

    virtual sf::Vector2f& getPosition() = 0;

    virtual sf::Vector2u getTextureSize() = 0;
};

