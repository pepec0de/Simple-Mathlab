#include "../include/utils.h"

#define DEBUG true

using namespace std;

utils utils;
double acumulador;

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
    if (utils.checkBrackets(op)) {

    } else {
        double num1, num2;
        int cont = 0;
        num1 = utils.getNumberFromOp(op, cont);
        cont++;
        num2 = utils.getNumberFromOp(op, cont);
        result = num1*num2;
    }
    return result;
}

double solve(string cmdStr) {
    char delimiters[] = {'+', '-'};
    vector<string> vctOp = utils.strUtils.split(cmdStr, delimiters, 2, true);
    for (unsigned int i = 0; i < vctOp.size(); i++) {
        string num = vctOp[i];
        if (DEBUG) cout << "Procesamos el elemento: \"" << num << "\"\n";
        if (utils.isNumber(num)) {
            acumulador += stof(num);
        } else {
            /* Para ordenar operaciones dentro de () necesito
             * un arbol binario
             * TODO: aprender arboles binarios
             */
            if (DEBUG) cout << num << " : no es un numero\n";
            acumulador += calc(num);
        }
    }
    return acumulador;
}

void input(string &cmdStr) {
    cout << ">> ";
    getline(cin, cmdStr);
    cmdStr = utils.strUtils.replaceAll(cmdStr, " ", "");
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
