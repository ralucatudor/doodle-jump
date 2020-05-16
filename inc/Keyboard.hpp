#pragma once

#include <SFML/Graphics.hpp>

class Keyboard
{
public:
    Keyboard();

    void inputHandler(const sf::Event& event);

    std::map<sf::Keyboard::Key, bool>& getKeysMap();

private:
    std::map<sf::Keyboard::Key, bool> keysMap;
    
    Keyboard& operator+=(const sf::Keyboard::Key& key);  // KeyPressed
    
    Keyboard& operator-=(const sf::Keyboard::Key& key);  // KeyReleased
};
