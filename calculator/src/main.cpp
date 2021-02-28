#include "../include/utils.h"

#define DEBUG true

using namespace std;

utils utils;
double acumulador;
char signs[] = {'+', '-'};

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
        char nextOp;
        vector<string> vctOp = utils.getOp(op);
        cout << "Imprimimos vctOp:\n";
        for (unsigned int i = 0; i < vctOp.size(); i++) {
            cout << vctOp[i] << endl;
        }
        cout << "Tamaño vctOp : " << vctOp.size() << endl;
        for (unsigned int i = 0; i < vctOp.size(); i+=3) {
            cout << "Trabajamos con: " << vctOp[i] << ", " << vctOp[i+1] << ", " << vctOp[i+2] << endl;
            
            
            if (utils.isNumber(vctOp[i])) {
                num1 = stof(vctOp[i]);
                nextOp = vctOp[i+1][0]; // cast string to char
                num2 = stof(vctOp[i+2]);
                if (i == 0) result = operar(num1, num2, nextOp);
                else result = operar(result, operar(num1, num2, nextOp), vctOp[i-1][0]);
            } else {
                num1 = stof(vctOp[i+1]);
                nextOp = vctOp[i][0]; // cast string to char
                result = operar(result, num1, nextOp);
            }
            
            cout << "Result = " << result << endl;
        }
    }
    return result;
}

double solve(string cmdStr) {
    vector<string> vctOp = utils.strUtils.split(cmdStr, signs, 2, true);
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
