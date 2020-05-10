#include "Singleton.hpp"

Singleton* Singleton::instance_ = nullptr;

Singleton::Singleton() {}

Singleton& Singleton::getInstance()
{
    if (instance_ == nullptr)
        instance_ = new Singleton();

    return *instance_;
}
