#pragma once

#include <SFML/Graphics.hpp>

using keysMapType = std::map<sf::Keyboard::Key, bool>;

class Keyboard
{
public:
    Keyboard();

    void eventHandler(const sf::Event &event);

    keysMapType& getKeysMap();

private:
    keysMapType keysMap;

    void onLeftKeyPressed(const sf::Keyboard::Key& key);
    
    void onRightKeyPressed(const sf::Keyboard::Key& key);

    void onLeftKeyReleased(const sf::Keyboard::Key& key);

    void onRightKeyReleased(const sf::Keyboard::Key& key);
};
