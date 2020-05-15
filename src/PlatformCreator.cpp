#include "PlatformCreator.hpp"

#include <iostream>

std::shared_ptr<Platform> PlatformCreator::getPlatform(const int& choice)
{
    if (choice == 1) {
        return std::make_shared<RegularPlatform>(RegularPlatform());
    }
    if (choice == 2) {
        return std::make_shared<SlowPlatform>(SlowPlatform());
    }
    if (choice == 3) {
        return std::make_shared<FastPlatform>(FastPlatform());
    }
    return nullptr; // maybe throw exception
}