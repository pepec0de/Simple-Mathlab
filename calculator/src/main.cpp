#include "../include/stringutils.h"
#include "../include/utils.h"

using namespace std;

StringUtils strUtils;
Utils utils;
long double acumulador;

// TODO : function interpreter
// ...

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
        if (cmdStr != "") {
            acumulador = utils.calcOp(cmdStr);
            cout << "\n\tans = " << acumulador << "\n\n"; 
        }
        input(cmdStr);
    }
    return 0;
}
