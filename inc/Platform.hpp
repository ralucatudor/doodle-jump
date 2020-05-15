#pragma once

#include "BaseEntity.hpp"
#include "DEFINITIONS.hpp"

class Platform : public BaseEntity
{
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    Platform();

    ~Platform() override = default;

    Platform(const Platform& ob); 

    void updatePosition() override;

    sf::Vector2f getPosition() const override final; 

    void setPosition(sf::Vector2f ) override final;

    sf::Vector2u getTextureSize() override final;

    virtual unsigned getSpeed() = 0;
};

