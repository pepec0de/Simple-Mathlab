#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

using namespace std;

class utils {
public:
    bool isSign(char c);
    bool isOperator(char c);
    bool isNumber(string str);
    bool checkBrackets(string str);
    vector<double> getNumbersFromOp(string str);
protected:
private:
};
#endif // UTILS_H
