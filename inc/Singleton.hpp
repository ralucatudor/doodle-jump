#pragma once

#include <iostream>

class Singleton
{
    Singleton();
    Singleton(const Singleton& ) = delete;
    Singleton& operator=(const Singleton& ) = delete;

    static Singleton* instance_;

public:
    static Singleton& getInstance();

    // `<<` operator implemented inline
    template <class T>
    Singleton& operator<<(const T& elem)
    {
        std::cerr << elem;
        return *this;
    }
};
