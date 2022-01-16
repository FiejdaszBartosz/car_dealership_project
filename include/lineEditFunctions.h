#ifndef LINEEDITFUNCTIONS_H
#define LINEEDITFUNCTIONS_H

#include <QString>
#include <iostream>
#include <stdexcept>
#include <math.h>
#include "MyException.h"

void convertToString(const QString &rInput, std::string &rOutput);

void convertToInt(const QString &rInput, int &rOutput);

void validateYear(const int &rYear);

#endif // LINEEDITFUNCTIONS_H
