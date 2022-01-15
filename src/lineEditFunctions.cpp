#include "../include/lineEditFunctions.h"

template<class T>
bool intValuValidation(T &rInput){

}

bool convertToInt(const QString &rInput, int &rOutput){
    int tempInt;
    double tempDouble, tempIntPart, tempFractPart;
    bool ok = false;

    tempDouble = rInput.toDouble(&ok);
    if(ok){
        tempFractPart = modf(tempDouble, &tempIntPart);
        if(tempFractPart == 0.0){
            rOutput = (int)tempIntPart;
            return true;
        } else {
             throw MyException("Warning",
                               "Input is double instead of int",
                               "lineEditFunction.cpp",
                               "convertToInt",
                               "16");
             return false;
        }
    } else
        throw MyException("Warning",
                          "Unknown input",
                          "lineEditFunction.cpp",
                          "convertToInt",
                          "13");
    return false;
}
