#pragma once

#include "Platform.hpp"

class SlowPlatform : public Platform
{
private:
    bool hasCollision;
public:
    SlowPlatform();

    unsigned getDistance() override;

    bool getHasCollision() const;

    void setHasCollision(bool);
};