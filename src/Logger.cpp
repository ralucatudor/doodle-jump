#include "Logger.hpp"

Logger::Logger() {}

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}