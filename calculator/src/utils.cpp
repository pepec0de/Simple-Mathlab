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
    if (str == "") return false;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (!(isNumber(str[i]) || isSign(str[i]))) {
            return false;
        }
    }
    return true;
}

bool utils::isNumber(char c) {
    if (c == '.') return true;
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

string utils::getNumberFromOp(string str, int idx) {
    // DEBUG : cout << "getNumberFromOp : " << str << ", " << idx << endl;
    string number;
    int currIdx = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (isNumber(str[i])) {
            if (currIdx == idx) {
                // Conditional to add sign
                if (i < 0) if (isSign(str[i-1])) number.push_back(str[i-1]);
                number.push_back(str[i]);
            }
            // If the number has more digits we dont change index
            if (!isNumber(strUtils.tostring(str[i+1]))) currIdx++;
        }
    }
    // DEBUG : cout << "getNumberFromOp :: return stof -> " << number << endl;
    return number;
}

vector<string> utils::getOp(string op) {
    vector<string> vct;
    // String must have less numbers than its size. numbers < size()
    for (unsigned int i = 0; i < op.size(); i++) {
        string currStr = getNumberFromOp()
        if (getNumberFromOp(op, i) != "") {
            vct.push_back()
        } else {
            break;
        }
    }
    return vct;
}
