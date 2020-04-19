#pragma once

#include <SFML/Graphics.hpp>
#include "constants.hpp"

class BaseEntity : public sf::Drawable, public sf::Transformable
// inherit Transformable for getposition() and Drawable for draw()
{
private:
    //virtual void checkCollision() = 0;
public:
    virtual void updateCollision() {};

    std::map<sf::Keyboard::Key, bool> keysMap;

    virtual void updatePosition(const float) {};
    virtual void updatePosition() {};

    virtual sf::Vector2f& getPosition() = 0;

    virtual float getDeltaY() {return 0.f;};

    virtual sf::Vector2u getTextureSize() = 0;
};