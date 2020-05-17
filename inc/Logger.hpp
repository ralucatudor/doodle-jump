#pragma once

#include <iostream>

class Logger
{
    Logger();

    Logger(const Logger& ) = delete;
    
    Logger& operator=(const Logger& ) = delete;
public:
    static Logger& getInstance();

    // `<<` operator implemented inline
    template <class T>
    Logger& operator<<(const T& item)
    {
        std::cerr << item;
        return *this;
    }
};
