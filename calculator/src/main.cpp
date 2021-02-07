#include <iostream>
#include <vector>
#include "../include/utils.h"

using namespace std;

utils utils;
double acumulador;

// Funcion para comprobar si un char es un simbolo
bool isSign(char c) {
    return c == '+' || c == '-';
}

// Funcion para comprobar si un char es un operador
bool isOperator(char c) {
    return c == '*' || c == '/';
}

// Funcion para comprobar si un char es una int
bool isNumber(string str) {
    try {
        stof(str);
    } catch (exception& e) {
        return false;
    }
    return true;
}

double operar(double a, double b, char op) {
    switch(op) {
        case '*':
            return a*b;
            break;
        case '/':
            return a/b;
            break;
    }
    return 0;
}

double calc(string op) {
    double result = 0;
    // Caso base -> si no hay parentesis operar normal
    if (utils.checkBrackets(op)) {

    } else {
        double num1, num2;

    }
    return result;
}

double solve(string cmdStr) {
    vector<string> vctOp = utils.splitBySign(cmdStr);
    for (unsigned int i = 0; i < strSigns.size(); i++) {
        string num = vctOp[i];
        cout << "Procesamos el elemento: \"" << num << "\"\n";
        if (isNumber(num)) {
            acumulador += stof(num);
        } else {
            cout << num << " : no es un numero\n";
            acumulador += calc(num);
        }
    }
    return acumulador;
}

void input(string &cmdStr) {
    cout << ">> ";
    getline(cin, cmdStr);
    cmdStr = utils.replaceAll(cmdStr, " ", "");
    cout << "Result = " << cmdStr << endl;
}

int main() {
    cout << "Calculator 1.0\n";
    cout << "Type q for exit the program\n";

    // String para almacenar la operacion
    string cmdStr;
    input(cmdStr);
    
    acumulador = 0;
    while (cmdStr != "q") {
        acumulador = 0;
        acumulador = solve(cmdStr);
        cout << "\n\tans = " << acumulador << endl; 
        input(cmdStr);
    }
    return 0;
}
