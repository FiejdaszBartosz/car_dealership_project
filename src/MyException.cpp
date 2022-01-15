#include "MyException.h"

MyException::MyException(const std::string& type,
                         const std::string& message,
                         const std::string& source,
                         const std::string& function,
                         const std::string& line) :
    aMessage(makeMessage(type, message, source, function, line)) {}

const char *MyException::what() const throw()
{
    return aMessage.c_str();
}

std::string MyException::makeMessage(const std::string& type,
                                     const std::string& message,
                                     const std::string& source,
                                     const std::string& function,
                                     const std::string& line) {
    std::string s;

    s = "!Exception! " + type + "\n" + "Message: " + message + "\n" +
        "In: " + source + "\n" + "Function: " + function + "\n" + "Line: " + line + "\n";

    return s;
}
