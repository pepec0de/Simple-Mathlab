#include "../include/utils.h"
#include "../include/stringutils.h"

stringutils strUtils;

bool utils::isSign(char c) {
    return c == '+' || c == '-';
}

bool utils::isOperator(char c) {
    switch(c) {
        case '*':
        case '/':
            return true;
            break;
    }
}

bool utils::isNumber(string str) {
    try {
        stof(str);
    } catch (exception& e) {
        return false;
    }
    return true;
}

bool utils::checkBrackets(string str) {
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == ')') return true;
    }
    return false;
}

double getNumberFromOp(string str, int idx) {
    vector<double> vct;
    int currIdx = 0;
    unsigned int relEnd = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (isNumber(strUtils.tostring(str[i]))) {
            if (currIdx == idx) {
                
            }
            currIdx++;
        }
    }
    return vct;
}
