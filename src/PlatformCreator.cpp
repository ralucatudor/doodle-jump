#include "PlatformCreator.hpp"

#include "Logger.hpp"

std::shared_ptr<Platform> PlatformCreator::getPlatform(const int& choice)
{
    try {
        switch(choice) {
            case 1:
                return std::make_shared<RegularPlatform>(RegularPlatform());
                break;
            case 2:
                return std::make_shared<SlowPlatform>(SlowPlatform());
                break;
            case 3:
                return std::make_shared<FastPlatform>(FastPlatform());
                break;
            default:
                throw UndefinedPlatformException();
                break;
        }
    }
    catch (UndefinedPlatformException& e)
    {
        Logger::getInstance() << "Exception: " << e.what() << '\n';
        return nullptr;
    }
}