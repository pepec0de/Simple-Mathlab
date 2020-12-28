#include <iostream>
#include <vector>

using namespace std;

double ans;

// Funcion para comprobar si un char es un simbolo
bool isSign(char c) {
    return c == '+' || c == '-';
}

// Funcion para comprobar si un char es un operador
bool isOperator(char c) {
    return c == '*' || c == '/';
}

// Funcion para comprobar si un char es una int
bool isNumber(char c) {
    string str = "";
    str[0] = c;
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

// Funcion para dividir la cadena por signos
/*
 * 1+2*2-4-3+4 -> 1, +2*2, -4, -3, +4
 */
// Voy a aplicar el metodo para dividir strings por un delimitador del eqsolver
vector<string> splitBySign(string str) {
    vector<string> vct;
    unsigned int relStart = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        if( (str[i] == '+' || str[i] == '-') && relStart+i != 0) {
            
        }
    }
    return vct;
}

double solve(string cmdStr) {
    string currNum = "";
    bool numFound = false;
    for (unsigned int i = 0; i < cmdStr.size(); i++) {
        // Linear
        char c = cmdStr[i];
        if (isSign(c) && currNum == "") {
            numFound = true;
            currNum += c;
        } else if (isNumber(c) && numFound) {
            currNum += c;
        } else if (numFound && isSign(c)){
            numFound = false;
        }

        if (!numFound && currNum != "") {
            ans += stof(currNum);
        }
    }
    return ans;
}

int main() {
    cout << "Calculator 1.0\n";
    cout << "Type q for exit the program\n";

    // String para almacenar la operacion
    string cmdStr;
    cout << ">> ";
    getline(cin, cmdStr);

    ans = 0;

    while (cmdStr != "q") {
        ans = 0;
        ans = solve(cmdStr);
        cout << "\n\tans = " << ans << endl; 
        cout << ">> ";
        getline(cin, cmdStr);
    }
    return 0;
}
