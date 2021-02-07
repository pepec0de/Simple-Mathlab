#include "../include/utils.h"

/*
 * 1+2*2+3-4+5 -> [1, +2*2, +3, -4, +5]
 */
vector<string> utils::splitBySign(string str) {
    vector<string> strVct;
    unsigned int relStart = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == '+' || str[i] == '-') {
            // Hacemos el substring y despues lo añadimos al vector str
            strVct.push_back(getSubstring(str, relStart, i));
            relStart = i;
        }
    }
    strVct.push_back(getSubstring(str, relStart, str.size()));
    return strVct;
}

bool checkBrackets(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == ')') return true;
    }
    return false;
}

// Func to do substring having an interval
string utils::getSubstring(string str, unsigned int start, unsigned int end) {
    string result = "";
    for (unsigned int i = start; i < end; i++) {
        result += str[i];
    }
    return result;
}

// Func to replace all characters that matches with another from a string
string utils::replaceAll(string str, char regex, char replacement) {
    string result = "";
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == regex) str[i] = replacement;
    }
    return result;
}

string utils::replaceAll(string str, string regex, string replacement) {
    for (unsigned int i = 0; i < str.size(); i++) {
        // We check if the first char of regex matches with current char
        if (str[i] == regex[0]) {
            if (getSubstring(str, i, regex.size()+i) == regex) {
                str = getSubstring(str, 0, i) + replacement 
                    + getSubstring(str, regex.size()+i, str.size());
            }
        }
    }
    return str;
}
