#include "Platform.hpp"

#include <random>

void Platform::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(shape, states);
}

Platform::Platform() {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> range(1, 100000);

    position.x = range(generator) % WINDOW_WIDTH;
    position.y = range(generator) % WINDOW_HEIGHT;

    // ----------------------------------
    // position.x = rand() % WINDOW_WIDTH;
    // position.y = rand() % WINDOW_HEIGHT;

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