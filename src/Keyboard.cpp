#include "Keyboard.hpp"

Keyboard::Keyboard()
{
    keysMap[sf::Keyboard::Left] = false;
    keysMap[sf::Keyboard::Right] = false;
}

keysMapType& Keyboard::getKeysMap()
{
    return keysMap;
}

void Keyboard::inputHandler(const sf::Event& event)
{
    switch (event.type) {
        case sf::Event::KeyPressed:
            // leftKeyPressed(event.key.code); 
            // rightKeyPressed(event.key.code);
            (*this) += event.key.code;
            break;
        case sf::Event::KeyReleased:
            // leftKeyReleased(event.key.code); 
            // rightKeyReleased(event.key.code);
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

/*
Implementation before operator overloading:

void Keyboard::leftKeyPressed(const sf::Keyboard::Key& key)
{
    if (key != sf::Keyboard::Left) {
        return;
    }
    keysMap[sf::Keyboard::Left] = true;
}

void Keyboard::rightKeyPressed(const sf::Keyboard::Key& key)
{
    if (key != sf::Keyboard::Right) {
        return;
    }
    keysMap[sf::Keyboard::Right] = true;
}

void Keyboard::leftKeyReleased(const sf::Keyboard::Key& key)
{
    if (key != sf::Keyboard::Left) {
        return;
    }
    keysMap[sf::Keyboard::Left] = false;
}

void Keyboard::rightKeyReleased(const sf::Keyboard::Key& key)
{
    if (key != sf::Keyboard::Right) {
        return;
    }
    keysMap[sf::Keyboard::Right] = false;
}
*/