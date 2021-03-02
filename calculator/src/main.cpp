#include "../include/stringutils.h"
#include "../include/utils.h"

using namespace std;

StringUtils strUtils;
Utils utils;
long double acumulador;
char signs[] = {'+', '-'};


// TODO : function interpreter
// ...

long double operar(long double a, long double b, char op) {
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

long double calc(string op) {
    long double result;
    
    // we could get rid of these vars
    long double num1, num2;
    char nextOp;
    vector<string> vctOp = utils.getOp(op);
    // Simple linear calc
    unsigned int step = 3;
    try {
        for (unsigned int i = 0; i < vctOp.size(); i += step) {
            // if its the first calc we have to get two nums
            if (i == 0) {
                num1 = stof(vctOp[i]);
                nextOp = vctOp[i+1][0];
                num2 = stof(vctOp[i+2]);
                result = operar(num1, num2, nextOp);
            } else {
                // we calc like: (*x) doing it linearly
                num1 = stof(vctOp[i+1]);
                result = operar(result, num1, vctOp[i][0]);
                step = 2;
            }
        }
    } catch (exception& e) {
        cout << "\tSyntax error!\n";
        result = 0;
    }
    return result;
}

long double solve(string cmdStr) {
    vector<string> vctOp = strUtils.split(cmdStr, signs, 2, true);
    for (unsigned int i = 0; i < vctOp.size(); i++) {
        string num = vctOp[i];
        if (DEBUG) cout << "Procesamos el elemento: \"" << num << "\"\n";
        if (utils.isNumber(num)) {
            acumulador += stof(num);
        } else {
            /* Para ordenar operaciones dentro de () necesito
             * un arbol binario.
             * TODO: aprender a programar arboles binarios
             * Voy a aplicar la formula de los arboles multirama para usar
             * solo arboles binarios.
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
    cmdStr = strUtils.replaceAll(cmdStr, " ", "");
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
