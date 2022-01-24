#include "../include/lineEditFunctions.h"

/**
 * @brief converts QString to string with validation to empty input
 * @param rInput in QString
 * @param rOutput in String - returning that by reference
 */
void convertToString(const QString &rInput, std::string &rOutput) {

  if (rInput == "") {
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToString",
					  "10");
  } else {
	rOutput = rInput.toUtf8().constData();
  }

}

/**
 * @brief converts QString to string with validation to empty input
 * @param rInput in QString
 * @param rOutput in String - returning that by reference
 * @param rFlag - whether it was previously added
 * @param rAdd - confirms input
 */
void convertToString(const QString &rInput, std::string &rOutput, bool &rFlag, bool &rAdd) {

  if (rInput == "" && rFlag == false)
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToString",
					  "31");
  else {
	rOutput = rInput.toUtf8().constData();
	rAdd = true;
  }

}

/**
 * @brief converts QString to int with validation to: empty input, unknown input type, double instead of int
 * @param rInput in QString
 * @param rOutput in int - returning that by reference
 */
void convertToInt(const QString &rInput, int &rOutput) {
  int tempInt = 0;
  double tempDouble = 0.0, tempIntPart = 0.0, tempFractPart = 0.0;
  bool ok = false;

  if (rInput == "") {
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToInt",
					  "54");
  }

  tempDouble = rInput.toDouble(&ok);
  if (ok) {
	tempFractPart = modf(tempDouble, &tempIntPart);
	if (tempFractPart == 0.0) {
	  rOutput = (int)tempIntPart;
	} else
	  throw MyException("warning",
						"Input is double instead of int",
						"lineEditFunction.cpp",
						"convertToInt",
						"65");
  } else
	throw MyException("warning",
					  "Unknown type of input",
					  "lineEditFunction.cpp",
					  "convertToInt",
					  "63");
}

/**
 * @brief converts QString to int with validation to: empty input, unknown input type, double instead of int
 * @param rInput in QString
 * @param rOutput in int - returning that by reference
 * @param rFlag - whether it was previously added
 * @param rAdd - confirms input
 */
void convertToInt(const QString &rInput, int &rOutput, bool &rFlag, bool &rAdd) {
  int tempInt = 0;
  double tempDouble = 0.0, tempIntPart = 0.0, tempFractPart = 0.0;
  bool ok = false;

  if (rInput == "" && rFlag == false) {
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToInt",
					  "93");
  }
  if (rInput != "") {
	tempDouble = rInput.toDouble(&ok);
	if (ok) {
	  tempFractPart = modf(tempDouble, &tempIntPart);
	  if (tempFractPart == 0.0) {
		rOutput = (int)tempIntPart;
		rAdd = true;
	  } else
		throw MyException("warning",
						  "Input is double instead of int",
						  "lineEditFunction.cpp",
						  "convertToInt",
						  "104");
	} else
	  throw MyException("warning",
						"Unknown type of input",
						"lineEditFunction.cpp",
						"convertToInt",
						"102");
  }

}

/**
  * @brief validates the input year
  * @param rYear - given year, should be greater then 1885
*/
void validateYear(const int &rYear) {
  if (rYear < 1885)
	throw MyException("warning",
					  "Invalid year",
					  "lineEditFunction.cpp",
					  "validateYear",
					  "109");
}

/**
 * @brief converts QString to string with validation to empty input
 * @param rInput in QString
 * @param rOutput in String - returning that by reference
 * @param rFlag - whether it was previously added
 */
void convertToString(const QString &rInput, std::string &rOutput, bool &rFlag) {

  if (rInput == "" && rFlag == false)
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToString",
					  "144");
  else
	rOutput = rInput.toUtf8().constData();

}

/**
 * @brief converts QString to int with validation to: empty input, unknown input type, double instead of int
 * @param rInput in QString
 * @param rOutput in int - returning that by reference
 * @param rFlag - whether it was previously added
 * @param rAdd - confirms input
 */
void convertToInt(const QString &rInput, int &rOutput, bool &rFlag) {
  int tempInt = 0;
  double tempDouble = 0.0, tempIntPart = 0.0, tempFractPart = 0.0;
  bool ok = false;

  if (rInput == "" && rFlag == false) {
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToInt",
					  "167");
  }

  tempDouble = rInput.toDouble(&ok);
  if (ok) {
	tempFractPart = modf(tempDouble, &tempIntPart);
	if (tempFractPart == 0.0) {
	  rOutput = (int)tempIntPart;
	} else
	  throw MyException("warning",
						"Input is double instead of int",
						"lineEditFunction.cpp",
						"convertToInt",
						"178");
  } else
	throw MyException("warning",
					  "Unknown type of input",
					  "lineEditFunction.cpp",
					  "convertToInt",
					  "176");
}
