#include "PlatformCreator.hpp"

Platform* PlatformCreator::getPlatform(const int& choice)
{
    if (choice == 1)
        return new RegularPlatform();
    if (choice == 2)
        return new SlowPlatform();
    if (choice == 3)
        return new FastPlatform();
    return nullptr; // maybe throw exception
}