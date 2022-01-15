#ifndef LINEEDITFUNCTIONS_H
#define LINEEDITFUNCTIONS_H

#include <QString>
#include <iostream>
#include <stdexcept>
#include <math.h>
#include "MyException.h"

template<class T>
bool intValuValidation(T &rInput);

bool stringValuValidation(std::string &rInput);

bool convertToInt(const QString &rInput, int &rOutput);

#endif // LINEEDITFUNCTIONS_H
