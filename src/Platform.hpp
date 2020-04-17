#pragma once

#include "BaseEntity.hpp"
#include "constants.hpp"

class Platform : public BaseEntity
{
    sf::RectangleShape shape;
    sf::Vector2f position;

    const sf::Vector2f size = sf::Vector2f(40, 10);
    const unsigned outlineThickness = 2;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    Platform();

    ~Platform() override = default;

    void updatePosition() override;
};

