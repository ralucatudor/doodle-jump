#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

#include "constants.hpp"
#include "BaseEntity.hpp"

class Doodler : public BaseEntity
{
private:
    const float jumping_speed = 65;
    float timeAccumulator = 0;

    float deltaY;

    sf::Vector2f position = sf::Vector2f(WINDOW_WIDTH / 2, 150);
    sf::Vector2f actualPosition;

    sf::Texture doodlerTexture;
    sf::Sprite doodlerSprite;

    // Overriding sf::Drawable::draw
    void draw(sf::RenderTarget&, sf::RenderStates) const override;

    void setLeftRightPosition(const float, const float);

    void setDeltaY(const float);
public:
    void updateCollision() override;

    Doodler();

    ~Doodler() override = default;

    Doodler(const Doodler& ob); 

    void updatePosition(const float) override;

    sf::Vector2f& getPosition() override; 

    float getDeltaY() override;

    sf::Vector2u getTextureSize() override;


    void testupdate();

    void sayHello() {
        std::cout << "oh yes\n";
    }
};