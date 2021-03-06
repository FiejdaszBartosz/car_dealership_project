#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>

class MyException : public std::exception {
 private:
  std::string aMessage;
  const std::string aType;
  static std::string makeMessage(const std::string &type,
								 const std::string &message,
								 const std::string &source,
								 const std::string &function,
								 const std::string &line);

 public:
  MyException(const std::string &type,
			  const std::string &message,
			  const std::string &source,
			  const std::string &function,
			  const std::string &line);
  const char *what() const throw();
  const char *what(std::string &rType) const throw();
};

#endif // MYEXCEPTION_H
