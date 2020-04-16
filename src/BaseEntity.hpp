#pragma once

class BaseEntity : public sf::Drawable, public sf::Transformable
// inherit Transformable for getposition() and Drawable for draw()
{
private:
    virtual void checkCollision() = 0;

public:
    virtual void updatePosition(float deltaTime) = 0;
};