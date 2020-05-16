#pragma once

#include "Platform.hpp"

class SlowPlatform : public Platform
{
private:
    bool hasCollision;
public:
    SlowPlatform();

    unsigned getSpeed() override;

    bool getHasCollision() const {
        return hasCollision;
    }

    void setHasCollision(bool value) {
        hasCollision = value;
    }
};