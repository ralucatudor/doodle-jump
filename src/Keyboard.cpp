#include "Keyboard.hpp"

Keyboard::Keyboard()
{
    keysMap[sf::Keyboard::Left] = false;
    keysMap[sf::Keyboard::Right] = false;
}

std::map<sf::Keyboard::Key, bool>& Keyboard::getKeysMap()
{
    return keysMap;
}

void Keyboard::inputHandler(const sf::Event& event)
{
    switch (event.type) {
        case sf::Event::KeyPressed:
            (*this) += event.key.code;
            break;
        case sf::Event::KeyReleased:
            (*this) -= event.key.code;
            break;
        default:
            break;
    }
}

Keyboard& Keyboard::operator+=(const sf::Keyboard::Key& key)    // KeyPressed
{
    if (key == sf::Keyboard::Right) {
        keysMap[sf::Keyboard::Right] = true;
    } else {
        keysMap[sf::Keyboard::Left] = true;
    }
    return (*this);
}

Keyboard& Keyboard::operator-=(const sf::Keyboard::Key& key)    // KeyReleased
{
    if (key == sf::Keyboard::Right) {
        keysMap[sf::Keyboard::Right] = false;
    } else {
        keysMap[sf::Keyboard::Left] = false;
    }
    return (*this);
}