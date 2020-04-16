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
}

void Doodler::updatePosition(float deltaTime)
{
    checkCollision();   // bottom collision 
    timeAccumulator += deltaTime * TIME_ACCELERATOR;
    double nextY = position.y - speed * timeAccumulator + 0.5 * STANDARD_GRAVITY * std::pow(timeAccumulator, 2);
    const sf::Vector2f nextPosition = {circle.getPosition().x, static_cast<float>(nextY)};
    circle.setPosition(nextPosition);
}

void Doodler::checkCollision()
{
    const float currentBottomPosition = circle.getPosition().y + radius + outlineThickness;
    if (currentBottomPosition > WINDOW_HEIGHT) {    //is below zero level
        timeAccumulator = 0;
    }
}