#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "BaseEntity.hpp"
#include "Keyboard.hpp"

#include "Exception.hpp"

class Doodler : public BaseEntity
{
private:
    float deltaY;

    float dy;
    
    // Overriding sf::Drawable::draw
    void draw(sf::RenderTarget&, sf::RenderStates) const override;

    void setLeftRightPosition(const float, const float);

    void setDeltaY(const float);
public:
    Keyboard keyboardInput;     

    float get_dy() const {
        return dy;
    }

    void set_dy(float value) {
        dy = value;
    }

    Doodler();

    ~Doodler() override = default;

    Doodler(const Doodler& ob); 

    void updatePosition(const float) override;

    sf::Vector2f getPosition() const override; 

    void setPosition(sf::Vector2f ) override;

    float getDeltaY();

    sf::Vector2u getTextureSize() override;

    void setUpDownPosition();
};