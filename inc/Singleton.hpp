#ifndef SINGLETON_
#define SINGLETON_

#include <bits/stdc++.h>

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

#endif // SINGLETON_