#include "../include/stringutils.h"

// Func to split a string with a given char
vector<string> stringutils::split(string str, char delimiter) {
	vector<string> strVct;
	unsigned int relStart = 0;
	for (unsigned int i = 0; i < str.size(); i++) {
		if (str[i] == delimiter) {
			// Hacemos el substring y despues lo añadimos al vector str
			strVct.push_back(getSubstring(str, relStart, i));
			relStart = i+1;
			// Si el delimitador esta en el ultimo caracter sacamos el vector
			if (relStart >= str.size()) {
				return strVct;
			}
		}
	}
	strVct.push_back(getSubstring(str, relStart, str.size()));
	return strVct;
}

/* Example output: split(str, {'+', '-'}, true)
 * "1+2*2+3-4+5" -> [1, +2*2, +3, -4, +5]
 */
vector<string> stringutils::split(string str, char delimiters[], bool addDelim) {
    int delimitersSize = sizeof(delimiters)/sizeof(delimiters[0]);
    vector<string> strVct;
    unsigned int relStart = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        for (unsigned int j = 0; j < delimitersSize; j++) {
            if (str[i] == delimiters[j]) {
                // Do substring
                strVct.push_back(getSubstring(str, relStart, i));
                relStart = addDelim ? i : i+1;
            }
        }
    }
    strVct.push_back(getSubstring(str, relStart, str.size()));
    return strVct;
}

//
// Substrings
//


// Func to do substring having an interval
string stringutils::getSubstring(string str, unsigned int start, unsigned int end) {
	string result = "";
	for (unsigned int i = start; i < end; i++) {
        result += str[i];
	}
	return result;
}

// Func to remove last characters of a string (has to be a negative number)
string stringutils::getSubstring(string str, int fromEnd) {
	string result = "";
	if (fromEnd < 0) {
		for (int i = 0; i < (fromEnd + (int)str.size()); i++) {
			result.push_back(str[i]);
		}
	}
	return result;
}

//
// Replace
//

// Func to replace all chars that matches with another
string stringutils::replaceAll(string str, char regex, char replacement) {
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == regex) str[i] = replacement;
    }
    return str;
}

// Func to replace all strs that matches with another
string stringutils::replaceAll(string str, string regex, string replacement) {
    int relEnd = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        // we check if the first char of regex matches with current char
        if (str[i] == regex[0]) {
            relEnd = regex.size()+i;
            if (getSubstring(str, i, relEnd) == regex) {
                str = getSubstring(str, 0, i) + replacement
                    + getSubstring(str, relEnd, str.size());
            }
        }
    }
    return str;
}

//
// Converters
//
string stringutils::tostring(float value) {
    ostringstream strs;
    strs << value;
    return strs.str();
}
