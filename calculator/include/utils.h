#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

#define DEBUG true

using namespace std;

class Utils {
public:
    bool isSign(char c);
    bool isOperator(char c);
    bool isNumber(string str);
    bool isNumber(char c);
    
    string getNextNumber(string op, unsigned int &idx);
    vector<string> getOp(string op);

    // Calc functions
    long double op(long double a, long double b, char cop);
    long double linearcalc(string op);
    long double bracketscalc(string bracketsOp);
protected:
private:
};
#endif // UTILS_H
