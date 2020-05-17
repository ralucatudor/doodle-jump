#pragma once

#include "Platform.hpp"

class RegularPlatform : public Platform
{
public:
    RegularPlatform();

    ~RegularPlatform();

    unsigned getDistance() override;
};