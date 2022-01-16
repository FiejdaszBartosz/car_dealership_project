#include "../include/lineEditFunctions.h"

void convertToString(const QString &rInput, std::string &rOutput) {

    if(rInput == ""){
        throw MyException("warning",
                          "Input is empty",
                          "lineEditFunction.cpp",
                          "convertToString",
                          "6");
    } else {
        rOutput = rInput.toUtf8().constData();
    }

}

void convertToInt(const QString &rInput, int &rOutput){
    int tempInt;
    double tempDouble, tempIntPart, tempFractPart;
    bool ok = false;

    if(rInput == ""){
        throw MyException("warning",
                          "Input is empty",
                          "lineEditFunction.cpp",
                          "convertToInt",
                          "13");
    }

    tempDouble = rInput.toDouble(&ok);
    if(ok){
        tempFractPart = modf(tempDouble, &tempIntPart);
        if(tempFractPart == 0.0){
            rOutput = (int)tempIntPart;
        } else
             throw MyException("warning",
                               "Input is double instead of int",
                               "lineEditFunction.cpp",
                               "convertToInt",
                               "16");
    } else
        throw MyException("warning",
                          "Unknown type of input",
                          "lineEditFunction.cpp",
                          "convertToInt",
                          "13");
}

void validateYear(const int &rYear){
    if(rYear < 1885)
        throw MyException("warning",
                          "Invalid year",
                          "lineEditFunction.cpp",
                          "validateYear",
                          "50");
}
