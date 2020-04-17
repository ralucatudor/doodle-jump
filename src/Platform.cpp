#include "Platform.hpp"

void Platform::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(shape, states);
}

Platform::Platform() {
    position.x = rand() % WINDOW_WIDTH;
    position.y = rand() % WINDOW_HEIGHT;

    if (position.x + size.x > WINDOW_WIDTH) {
        position.x -= size.x;
    }

    if (position.x - size.x < 0) {
        position.x += size.x;
    }

    shape.setSize(size);
    shape.setFillColor(sf::Color::Green);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(outlineThickness);
}

void Platform::updatePosition()
{
    shape.setPosition(position);
}