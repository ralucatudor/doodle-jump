#pragma once

#include <memory>

#include "RegularPlatform.hpp"
#include "SlowPlatform.hpp"
#include "FastPlatform.hpp"

class PlatformCreator
{
public:
    static std::shared_ptr<Platform> getPlatform(const int& choice);
};