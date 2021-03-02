#include "../include/utils.h"

// Char checkers
bool Utils::isSign(char c) {
    return c == '+' || c == '-';
}

bool Utils::isOperator(char c) {
    switch(c) {
        case '*':
        case '/':
            return true;
            break;
    }
    return false;
}

bool Utils::isNumber(string str) {
    if (str == "") return false;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (!(isNumber(str[i]) || isSign(str[i]))) {
            return false;
        }
    }
    return true;
}

bool Utils::isNumber(char c) {
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

// Si buscas resultados distintos no hagas siempre lo mismo ~ Einstein
/*
 * Function to get the next number on a specified index of the string
 * given. It also works with floating point numbers.
 * The argument passed by reference marks the start of the number.
 * At the end we pass through idx the last index of the number.
 * Example: getNextNumber("12*12", 0)
 * return -> "12" and idx = 1
 */
string Utils::getNextNumber(string op, unsigned int &idx) {
    string number = "";
    bool signFound = false;
    for (unsigned int i = idx; i < op.size(); i++) {
        if (isSign(op[i])) {
            // add sign
            number.push_back(op[i]);
            signFound = true;
        } else if (isNumber(op[i])) {
            // Conditional to check if we can add the sign that go with the number
if (i > 0 && number.size() == 0) if (isSign(op[i-1])) number.push_back(op[i-1]);
            number.push_back(op[i]);
            signFound = true;
            // Check end of vector
            if (i+1 == op.size()) {
                idx = i;
                break;
            }
        }

        // Finish picking up the number
        if (!isNumber(op[i]) && signFound) {
            idx = i-1;
            break;
        }
    }
    return number;
}

/*
 * Function to get the full operation in a vector:
 * having numbers in the even indexes and operators(*, /) in
 * the odd indexes
 * Example:
 * 12*12*12/12 -> {"12", "*", "12", "*", "12", "/", 12}
 */
vector<string> Utils::getOp(string op) {
    vector<string> vct;
    // String must have less numbers than its size. numbers of nums < .size()
    // DONE : solve BUG with numbers that have 4 digits or more (including '.')
    unsigned int currIdx = 0;
    for (unsigned int i = 0; i < op.size(); i++) {
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
