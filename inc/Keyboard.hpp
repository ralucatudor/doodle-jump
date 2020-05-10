#pragma once

#include <SFML/Graphics.hpp>

using keysMapType = std::map<sf::Keyboard::Key, bool>;

class Keyboard
{
public:
    Keyboard();

    void inputHandler(const sf::Event &event);

    keysMapType& getKeysMap();

private:
    keysMapType keysMap;
    
    Keyboard& operator+=(const sf::Keyboard::Key &key);  // KeyPressed
    Keyboard& operator-=(const sf::Keyboard::Key& key);  // KeyReleased

    // void leftKeyPressed(const sf::Keyboard::Key& key);
    
    // void rightKeyPressed(const sf::Keyboard::Key& key);

    // void leftKeyReleased(const sf::Keyboard::Key& key);

    // void rightKeyReleased(const sf::Keyboard::Key& key);
};
