#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

#include "stringutils.h"

using namespace std;

class utils {
public:
    stringutils strUtils;

    bool isSign(char c);
    bool isOperator(char c);
    bool isNumber(string str);
    bool isNumber(char c);
    bool checkBrackets(string str);
    double getNumberFromOp(string op, int idx);
protected:
private:
};
#endif // UTILS_H
