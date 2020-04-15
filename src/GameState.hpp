#pragma once

#include <SFML/Graphics.hpp>
#include "BaseState.hpp"

class GameState : public BaseState
{
private:
    float score = 0.f;
    sf::RenderWindow& m_window;
public:
    void eventHandler(const sf::Event &event) override;
};