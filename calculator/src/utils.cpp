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

vector<string> Utils::splitBySigns(string op) {
    vector<string> vct;
    unsigned int relStart = 0;
    unsigned int bracketCounter = 0;
    for (unsigned int i = 0; i < op.size(); i++) {
        if (op[i] == '(') {
            bracketCounter++;
        } else if (op[i] == ')') {
            bracketCounter--;
        }
        if ( (op[i] == '+' || op[i] == '-') && bracketCounter == 0) {
            // Do substring and add to vector
            vct.push_back(strUtils.getSubstring(op, relStart, i));
            relStart = i;
        }
    }
    vct.push_back(strUtils.getSubstring(op, relStart, op.size()));
    return vct;
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
        // The calculator of brackets have to be here
        if (op[i] == '(') {
            /*
             * TODO : learn how to work with binary trees.
             * use binary trees as multi branch trees. (right childs), (left
             * brothers).
             */

        } 
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

long double Utils::operate(long double a, long double b, char cop) {
    switch(cop) {
        case '*': return a*b;
        case '/': return a/b;
    }
    return 0;
}

long double Utils::linearCalc(string op) {
    long double result = 0;
    
    // we could get rid of these vars but they make it easier to read the code.
    long double num1, num2;
    char nextOp;
    vector<string> vctOp = getOp(op);
    // Simple linear calc
    unsigned int step = 3; // default loop step
    for (unsigned int i = 0; i < vctOp.size(); i += step) {
        // if its the first calc we have to get two nums
        if (i == 0) {
            // Parameters for operator func:
            num1 = stof(vctOp[i]);
            nextOp = vctOp[i+1][0]; // cast string to char
            num2 = stof(vctOp[i+2]);
            result = operate(num1, num2, nextOp);
        } else {
            // it isnt the first calc so go on linearly like : *a
            nextOp = vctOp[i][0];
            num1 = stof(vctOp[i+1]);
            result = operate(result, num1, nextOp);
            step = 2;
        }
    }
    return result;
}

long double Utils::calcOp(string fullop) {
    long double acumulator = 0;
    // We follow the operation priority (), */, +-
    vector<string> vctOp = splitBySigns(fullop);
    for (string num : vctOp) {
        if (DEBUG) cout << "Procesamos el elemento: \"" << num << "\"\n";
        if (isNumber(num)) {
            acumulator += stof(num);
        } else {
            // Calculate : (), */
            if (DEBUG) cout << num << " : no es un numero\n";
            acumulator += linearCalc(num);
        }
    }
    return acumulator;
}

string Utils::bracketsFinish(string brackets) {
    string num;
    return num;    
}

long double Utils::bracketsCalc(string bracketsOp) {
    // TODO: Implement a binary tree builder that will process every child with
    // calcOp.
    struct Node {

    };
    return 0;
}
