#ifndef LINEEDITFUNCTIONS_H
#define LINEEDITFUNCTIONS_H

#include <QString>
#include <iostream>
#include <stdexcept>
#include <math.h>
#include "MyException.h"

void convertToString(const QString &rInput, std::string &rOutput);

void convertToString(const QString &rInput, std::string &rOutput, bool &rFlag);

void convertToString(const QString &rInput, std::string &rOutput, bool &rFlag, bool &rAdd);

void convertToInt(const QString &rInput, int &rOutput);

void convertToInt(const QString &rInput, int &rOutput, bool &rFlag);

void convertToInt(const QString &rInput, int &rOutput, bool &rFlag, bool &rAdd);

void validateYear(const int &rYear);

#endif // LINEEDITFUNCTIONS_H
