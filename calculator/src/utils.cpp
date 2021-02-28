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

string utils::getNextNumber(string op, unsigned int &idx) {
    string number = "";
    bool signFound = false;
    for (unsigned int i = idx; i < op.size(); i++) {
        if (isSign(op[i])) {
            number.push_back(op[i]);
            signFound = true;
        } else if (isNumber(op[i])) {
            if (i < 0 && number.size() == 0) if (isSign(op[i-1])) number.push_back(op[i-1]);
            signFound = true;
            number.push_back(op[i]);
        }
        if (!isNumber(op[i]) && signFound) {
            idx = i-1;
            break;
        }
    }
    cout << "getNextNumber : return -> " << number << endl;
    return number;
}

vector<string> utils::getOp(string op) {
    vector<string> vct;
    // String must have less numbers than its size. numbers of nums < .size()
    int cont = 0; 
    // TODO : solve BUG with floating point numbers that have more than
    // 2 digits
    unsigned int currIdx = 0;
    for (unsigned int i = 0; i < op.size(); i++) {
        cout << "Call number : " << cont << endl; cont++;
        string posibleNumb = getNextNumber(op, currIdx);
        if (posibleNumb != "") vct.push_back(posibleNumb);
        currIdx++;
        if (isOperator(op[currIdx])) {
            string aux; aux.push_back(op[currIdx]);
            vct.push_back(aux);
        }
        currIdx++;
        i = currIdx;
    }
    return vct;
}
