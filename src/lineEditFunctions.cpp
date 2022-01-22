#include "../include/lineEditFunctions.h"

void convertToString(const QString &rInput, std::string &rOutput) {

  if (rInput == "") {
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToString",
					  "5");
  } else {
	rOutput = rInput.toUtf8().constData();
  }

}

void convertToString(const QString &rInput, std::string &rOutput, bool &rFlag, bool &rAdd) {

  if (rInput == "" && rFlag == false)
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToString",
					  "18");
  else {
	rOutput = rInput.toUtf8().constData();
	rAdd = true;
  }

}

void convertToInt(const QString &rInput, int &rOutput) {
  int tempInt = 0;
  double tempDouble = 0.0, tempIntPart = 0.0, tempFractPart = 0.0;
  bool ok = false;

  if (rInput == "") {
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToInt",
					  "39");
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
						"50");
  } else
	throw MyException("warning",
					  "Unknown type of input",
					  "lineEditFunction.cpp",
					  "convertToInt",
					  "48");
}

void convertToInt(const QString &rInput, int &rOutput, bool &rFlag, bool &rAdd) {
  int tempInt = 0;
  double tempDouble = 0.0, tempIntPart = 0.0, tempFractPart = 0.0;
  bool ok = false;

  if (rInput == "" && rFlag == false) {
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToInt",
					  "71");
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
						  "91");
	} else
	  throw MyException("warning",
						"Unknown type of input",
						"lineEditFunction.cpp",
						"convertToInt",
						"89");
  }

}

void validateYear(const int &rYear) {
  if (rYear < 1885)
	throw MyException("warning",
					  "Invalid year",
					  "lineEditFunction.cpp",
					  "validateYear",
					  "109");
}

void convertToString(const QString &rInput, std::string &rOutput, bool &rFlag) {

  if (rInput == "" && rFlag == false)
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToString",
					  "119");
  else
	rOutput = rInput.toUtf8().constData();

}

void convertToInt(const QString &rInput, int &rOutput, bool &rFlag) {
  int tempInt = 0;
  double tempDouble = 0.0, tempIntPart = 0.0, tempFractPart = 0.0;
  bool ok = false;

  if (rInput == "" && rFlag == false) {
	throw MyException("warning",
					  "Input is empty",
					  "lineEditFunction.cpp",
					  "convertToInt",
					  "135");
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
						"146");
  } else
	throw MyException("warning",
					  "Unknown type of input",
					  "lineEditFunction.cpp",
					  "convertToInt",
					  "143");
}
