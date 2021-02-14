#include "../include/utils.h"
#include "../include/stringutils.h"

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
    return false;
}

bool utils::isNumber(string str) {
    for (unsigned int i = 0; i < str.size(); i++) {
        if (!(isNumber(str[i]) || isSign(str[i]))) {
            return false;
        }
    }
    return true;
}

bool utils::isNumber(char c) {
    string str;
    str.push_back(c);
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

double utils::getNumberFromOp(string str, int idx) {
    cout << "getNumberFromOp : " << str << ", " << idx << endl;
    string number;
    int currIdx = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (isNumber(str[i])) {
            if (currIdx == idx) {
                if (i < 0) if (isSign(str[i-1])) number.push_back(str[i-1]);
                number.push_back(str[i]);
            }
            // If the number has more digits we dont cont it
            if (!isNumber(strUtils.tostring(str[i+1]))) currIdx++; else break;
        }
    }
    cout << "getNumberFromOp :: return stof -> " << number << endl;
    return stof(number);
}
