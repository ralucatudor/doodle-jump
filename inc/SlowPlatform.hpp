#pragma once

#include "Platform.hpp"

class SlowPlatform : public Platform
{
public:
    SlowPlatform();

    unsigned getSpeed() override;
};