#pragma once

#include "Platform.hpp"

class FastPlatform : public Platform
{
public:
    FastPlatform();

    unsigned getSpeed() override;
};