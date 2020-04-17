#include "Doodler.hpp"

// Overriding sf::Drawable::draw
void Doodler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(circle, states);
}

Doodler::Doodler()
{
    circle.setRadius(radius);
    circle.setOrigin(radius, radius);
    circle.setPosition(position);
    circle.setFillColor(sf::Color::White);
    circle.setOutlineColor(sf::Color::Black);
    circle.setOutlineThickness(outlineThickness);

    keysMap[sf::Keyboard::Left] = false;
    keysMap[sf::Keyboard::Right] = false;
}

void Doodler::updatePosition(const float deltaTime)
{
    checkCollision();   // bottom collision 
    timeAccumulator += deltaTime * TIME_ACCELERATOR;
    double nextY = position.y - jumping_speed * timeAccumulator + 0.7 * STANDARD_GRAVITY * std::pow(timeAccumulator, 2);
    const sf::Vector2f nextPosition = {position.x, static_cast<float>(nextY)};
    circle.setPosition(nextPosition);
    setLeftRightPosition(MOVE_SPEED, deltaTime);
}

void Doodler::checkCollision()
{
    const float currentBottomPosition = circle.getPosition().y + radius + outlineThickness;
    if (currentBottomPosition > WINDOW_HEIGHT) {    //is below zero level
        timeAccumulator = 0;
    }
}

void Doodler::setLeftRightPosition(const float move_speed, const float deltaTime)
{
    // check right collision before updating
    if (keysMap[sf::Keyboard::Right] && position.x + radius + outlineThickness < WINDOW_WIDTH) {
        position.x += move_speed * deltaTime;
    } // check left collision before updating
    else if (keysMap[sf::Keyboard::Left] && position.x - radius - outlineThickness > 0) {
        position.x -= move_speed* deltaTime;
    }
}