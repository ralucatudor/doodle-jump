#pragma once

#include "Platform.hpp"

class FastPlatform : public Platform
{
public:
    FastPlatform();

    ~FastPlatform();

    unsigned getDistance() override;
};