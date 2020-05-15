#pragma once

#include "Platform.hpp"

class RegularPlatform : public Platform
{
public:
    RegularPlatform();

    unsigned getSpeed() override;
};