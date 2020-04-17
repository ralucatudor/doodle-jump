#pragma once

class BaseEntity : public sf::Drawable, public sf::Transformable
// inherit Transformable for getposition() and Drawable for draw()
{
private:
    virtual void checkCollision() = 0;

public:
    std::map<sf::Keyboard::Key, bool> keysMap;

    virtual void updatePosition(const float deltaTime) = 0;
};