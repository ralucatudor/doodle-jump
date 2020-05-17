#include "Doodler.hpp"

// Overriding sf::Drawable::draw
void Doodler::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}

Doodler::Doodler() 
{
    position = sf::Vector2f(WINDOW_WIDTH / 2, 150);
    try {
        if (!std::filesystem::exists(DOODLER_FILEPATH)) 
            throw IncorrectFilePathException(DOODLER_FILEPATH);
        texture.loadFromFile(DOODLER_FILEPATH);
    }
    catch(IncorrectFilePathException& e) {
        Logger::getInstance() << "Exception: " << e.what() << '\n';
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

Doodler::~Doodler() 
{
    dy = 0;
}

Doodler::Doodler(const Doodler& other)  
{
    texture = other.texture;
    sprite = other.sprite;
    sprite.setTexture(texture);
    position = other.position;
    dy = other.dy;
    keyboardInput = other.keyboardInput;
}

Doodler& Doodler::operator=(const Doodler& other)
{
    if (this == &other) {
        return *this;
    }

    texture = other.texture;
    sprite = other.sprite;
    sprite.setTexture(texture);
    position = other.position;
    dy = other.dy;
    keyboardInput = other.keyboardInput;

    return *this;
}

void Doodler::updatePosition(const float deltaTime)
{
    setLeftRightPosition(MOVE_SPEED, deltaTime);    // set position.x

    sprite.setPosition(position);
}

void Doodler::setLeftRightPosition(const float move_speed, const float deltaTime)
{
    if (keyboardInput.getKeysMap()[sf::Keyboard::Right]) {
        // check right collision before updating
        if (position.x + texture.getSize().x > WINDOW_WIDTH)
            position.x = 0;
        position.x += 4;
    } else {
        if (keyboardInput.getKeysMap()[sf::Keyboard::Left]) {
            // check left collision before updating
            if (position.x < 0)
                position.x = WINDOW_WIDTH - texture.getSize().x;
            position.x -= 4;
        }
    }
}

sf::Vector2f Doodler::getPosition() const
{
    return position;
}

sf::Vector2u Doodler::getTextureSize() 
{
    return texture.getSize();
}

void Doodler::setUpDownPosition() 
{
    position.y += dy;
}

void Doodler::setPosition(sf::Vector2f newPosition) 
{
    position = newPosition;
}

float Doodler::get_dy() const
{
    return dy;
}

void Doodler::set_dy(float value) 
{
    dy = value;
}

void Doodler::handleKeyboardInput(const sf::Event& event) 
{
    keyboardInput.inputHandler(event);
}