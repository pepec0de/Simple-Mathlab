#include "../include/utils.h"
#include "../include/stringutils.h"

#define DEBUG true

using namespace std;

stringutils strUtils;
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
    // Caso base -> si no hay parentesis operar normal
    /*if (utils.checkBrackets(op)) {

    } else {
        double num1, num2;

    }*/
    return result;
}

double solve(string cmdStr) {
    vector<string> vctOp = utils.splitBySign(cmdStr);
    for (unsigned int i = 0; i < vctOp.size(); i++) {
        string num = vctOp[i];
        if (DEBUG) cout << "Procesamos el elemento: \"" << num << "\"\n";
        if (isNumber(num)) {
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
    cmdStr = utils.replaceAll(cmdStr, " ", "");
    if (DEBUG) cout << "Result = " << cmdStr << endl;
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
