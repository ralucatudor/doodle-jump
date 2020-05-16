#pragma once

#include <string>
#include <exception>

class Exception : public std::exception
{
protected:
    std::string errorMessage;
public: 
    explicit Exception(const std::string& message) : errorMessage(message) {}

    // using noexcept because throw() is deprecated
    virtual ~Exception() noexcept {}

    virtual const char* what() const noexcept override 
    { 
        return errorMessage.c_str(); 
    }
};

class UndefinedPlatformException : public Exception
{
public:
    explicit UndefinedPlatformException() : Exception("Platform type undefined!") {}
};

class IncorrectFilePathException : public Exception
{
private:
    std::string filePath;
public:
    explicit IncorrectFilePathException(std::string filePath) : Exception("The following filepath is incorrect: "), 
                                                                filePath(filePath)
    {
        errorMessage = errorMessage + filePath + "!";
    }
};