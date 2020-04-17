#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

#include "constants.hpp"
#include "BaseEntity.hpp"

class Doodler : public BaseEntity
{
private:
    const unsigned int radius = 25;
    const unsigned int outlineThickness = 2;

    const float jumping_speed = 75;
    float timeAccumulator = 0;

    sf::Vector2f position = sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT - radius - outlineThickness);
    sf::CircleShape circle;

    // Overriding sf::Drawable::draw
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void checkCollision() override;

public:
    Doodler();

    ~Doodler() override = default;

    void updatePosition(const float deltaTime) override;
    void setLeftRightPosition(const float, const float);
};