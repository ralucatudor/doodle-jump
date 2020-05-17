#pragma once

#include <random>

#include "BaseEntity.hpp"
#include "DEFINITIONS.hpp"

class Platform : public BaseEntity
{
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override final;
public:
    Platform();

    ~Platform();        // will also be virtual because virtual-ness propagates to derived classes

    Platform(const Platform&); 

    Platform& operator=(const Platform&);

    void updatePosition();

    sf::Vector2f getPosition() const override final; 

    void setPosition(sf::Vector2f ) override final;

    sf::Vector2u getTextureSize() override;

    // How far up the doodler will jump after collision with the plaform
    virtual unsigned getDistance() = 0;
};

