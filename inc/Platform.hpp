#pragma once

#include "BaseEntity.hpp"
#include "constants.hpp"

class Platform : public BaseEntity
{
    sf::Texture platformTexture;
    sf::Sprite platformSprite;
    
    sf::Vector2f position;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
public:
    Platform();

    ~Platform() override = default;

    Platform(const Platform& ob); 

    void updatePosition() override;

    sf::Vector2f& getPosition() override; 

    sf::Vector2u getTextureSize() override;
};

