#pragma once

#include <SFML/Graphics.hpp>

#include "DEFINITIONS.hpp"
#include "BaseEntity.hpp"
#include "Keyboard.hpp"

#include "Exception.hpp"

class Doodler : public BaseEntity
{
private:
    float dy;   // delta y
    
    // Overriding sf::Drawable::draw
    void draw(sf::RenderTarget&, sf::RenderStates) const override;

    void setLeftRightPosition(const float, const float);
    
    Keyboard keyboardInput;     
public:
    Doodler();

    ~Doodler() override = default;

    Doodler(const Doodler& ob); 

    void updatePosition(const float);

    sf::Vector2f getPosition() const override; 

    void setPosition(sf::Vector2f ) override;

    sf::Vector2u getTextureSize() override;

    void setUpDownPosition();

    float get_dy() const;

    void set_dy(float);

    Keyboard& getKeyboardInput();
};