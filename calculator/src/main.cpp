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
    return result;
}

double solve(string cmdStr) {
    vector<string> strSigns = utils.splitBySign(cmdStr);
    for (unsigned int i = 0; i < strSigns.size(); i++) {
        string num = strSigns[i];
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

int main() {
    cout << "Calculator 1.0\n";
    cout << "Type q for exit the program\n";

    // String para almacenar la operacion
    string cmdStr;
    cout << ">> ";
    getline(cin, cmdStr);

    acumulador = 0;

    while (cmdStr != "q") {
        acumulador = 0;
        acumulador = solve(cmdStr);
        cout << "\n\tans = " << acumulador << endl; 
        cout << ">> ";
        getline(cin, cmdStr);
    }
    return 0;
}
