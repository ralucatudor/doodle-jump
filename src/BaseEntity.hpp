#pragma once

class BaseEntity : public sf::Drawable, public sf::Transformable
{
private:
    virtual void checkCollision() = 0;

public:
    virtual void updatePosition(float deltaTime) = 0;
};