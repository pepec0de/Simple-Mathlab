#include "../include/utils.h"

bool checkBrackets(string str) {
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == ')') return true;
    }
    return false;
}
