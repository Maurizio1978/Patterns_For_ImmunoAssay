#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <string>

class Exceptions
{
public:
     Exceptions() {}
    ~Exceptions() {}
};

class ConfigurationException
{
private:
    std::string m_MissingParameter;
    ConfigurationException() {}

public:
    ConfigurationException(std::string missingParameter) : m_MissingParameter(missingParameter) {    }
    std::string GetError() { return m_MissingParameter; }
};

#endif // EXCEPTIONS_H
