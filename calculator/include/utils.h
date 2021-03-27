#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

#include "stringutils.h"

#define DEBUG true

using namespace std;

class Utils {
public:
    bool isSign(char c);
    bool isOperator(char c);
    bool isNumber(string str);
    bool isNumber(char c);
    char signsProc(char a, char b); 

    vector<string> getFullOp(string op);
    string getNextNumber(string op, unsigned int &idx);
    vector<string> getOp(string op);

    // Calc functions
    long double operate(long double a, long double b, char cop);
    long double linearCalc(string op);
    long double calcOp(string fullop);
    string bracketsCalc(string brackets);
    unsigned int getClosingBracketIndex(string str, unsigned int idxOpen);
protected:
private:
    StringUtils strUtils;
};
#endif // UTILS_H
