#include "Doodler.hpp"

// Overriding sf::Drawable::draw
void Doodler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(doodlerSprite, states);
}

Doodler::Doodler()
{
    doodlerTexture.loadFromFile(DOODLER_FILEPATH);
    doodlerSprite.setTexture(doodlerTexture);
    doodlerSprite.setPosition(position);
}

Doodler::Doodler(const Doodler& ob)         // copy constructor
{
    doodlerTexture = ob.doodlerTexture;
    doodlerSprite = ob.doodlerSprite;
    doodlerSprite.setTexture(doodlerTexture);
    position = ob.position;
    deltaY = ob.deltaY;
}

void Doodler::updatePosition(const float deltaTime)
{
    setLeftRightPosition(MOVE_SPEED, deltaTime);    // set position.x

    doodlerSprite.setPosition(position);
}

void Doodler::setLeftRightPosition(const float move_speed, const float deltaTime)
{
    if (keyboardInput.getKeysMap()[sf::Keyboard::Right]) {
        // check right collision before updating
        if (position.x + doodlerTexture.getSize().x > WINDOW_WIDTH)
            position.x = 0;
        position.x += 4;
    } else {
        if (keyboardInput.getKeysMap()[sf::Keyboard::Left]) {
            // check left collision before updating
            if (position.x < 0)
                position.x = WINDOW_WIDTH - doodlerTexture.getSize().x;
            position.x -= 4;
        }
    }
}

void Doodler::setDeltaY(const float nextY) 
{
    deltaY = position.y - nextY;
}

float Doodler::getDeltaY() 
{
    return deltaY;
}

sf::Vector2f Doodler::getPosition() const
{
    return position;
}

sf::Vector2u Doodler::getTextureSize() 
{
    return doodlerTexture.getSize();
}

void Doodler::setUpDownPosition() 
{
    position.y += dy;
}

void Doodler::setPosition(sf::Vector2f newPosition) 
{
    position = newPosition;
}