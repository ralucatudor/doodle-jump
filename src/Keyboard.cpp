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

void Keyboard::eventHandler(const sf::Event& event)
{
    switch (event.type) {
        case sf::Event::KeyPressed:
            onLeftKeyPressed(event.key.code);
            onRightKeyPressed(event.key.code);
            break;
        case sf::Event::KeyReleased:
            onLeftKeyReleased(event.key.code);
            onRightKeyReleased(event.key.code);
            break;
        default:
            break;
    }
}

void Keyboard::onLeftKeyPressed(const sf::Keyboard::Key &key)
{
    if (key != sf::Keyboard::Left) {
        return;
    }
    keysMap[sf::Keyboard::Left] = true;
}

void Keyboard::onRightKeyPressed(const sf::Keyboard::Key &key)
{
    if (key != sf::Keyboard::Right) {
        return;
    }
    keysMap[sf::Keyboard::Right] = true;
}

void Keyboard::onLeftKeyReleased(const sf::Keyboard::Key &key)
{
    if (key != sf::Keyboard::Left) {
        return;
    }
    keysMap[sf::Keyboard::Left] = false;
}

void Keyboard::onRightKeyReleased(const sf::Keyboard::Key &key)
{
    if (key != sf::Keyboard::Right) {
        return;
    }
    keysMap[sf::Keyboard::Right] = false;
}