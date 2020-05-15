#pragma once

#include "RegularPlatform.hpp"
#include "SlowPlatform.hpp"
#include "FastPlatform.hpp"

class PlatformCreator
{
public:
    static Platform* getPlatform(const int& choice);
};