#pragma once

#include <SFML/Graphics.hpp>
#include "constants.hpp"

class BaseEntity : public sf::Drawable, public sf::Transformable
// inherit Transformable for getposition() and Drawable for draw()
{
private:
    //virtual void checkCollision() = 0;
    virtual void checkCollision() {};

public:
    std::map<sf::Keyboard::Key, bool> keysMap;

    virtual void updatePosition(const float) {};
    virtual void updatePosition() {};
};