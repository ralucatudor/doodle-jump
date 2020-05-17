#pragma once

#include <memory>

#include "RegularPlatform.hpp"
#include "SlowPlatform.hpp"
#include "FastPlatform.hpp"
#include "Exception.hpp"
#include "Logger.hpp"

class PlatformCreator
{
public:
    ~PlatformCreator();

    static std::shared_ptr<Platform> getPlatform(const int& choice);    // Factory method
};