#include "MyException.h"

/**
  * @brief constructor - creates MyException using makeMessage function
  * @param type - exception type
  * @param message
  * @param source - file
  * @param function - name
  * @param line - in code
*/
MyException::MyException(const std::string &type,
						 const std::string &message,
						 const std::string &source,
						 const std::string &function,
						 const std::string &line) :
	aMessage(makeMessage(type, message, source, function, line)), aType(type) {}

/**
  * @returns message using c_str()
*/
const char *MyException::what() const throw() {
  return aMessage.c_str();
}

/**
  * @param rType - returns aType as a reference
  * @returns message using c_str()
*/
const char *MyException::what(std::string &rType) const throw() {
  rType = aType;
  return aMessage.c_str();
}

/**
  * @brief prepares a message
  * @returns message
*/
std::string MyException::makeMessage(const std::string &type,
									 const std::string &message,
									 const std::string &source,
									 const std::string &function,
									 const std::string &line) {
  std::string s;

  s = "!Exception! " + type + "\n" + "Message: " + message + "\n" +
	  "In: " + source + "\n" + "Function: " + function + "\n" + "Line: " + line + "\n\n";

  return s;
}
