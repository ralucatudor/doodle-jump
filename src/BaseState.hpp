#pragma once

class BaseState
{
public:
    virtual void eventHandler(const sf::Event &event) = 0;
};
