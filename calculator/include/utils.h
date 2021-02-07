#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

using namespace std;

class utils {
public:
    vector<string> splitBySign(string str);
    string getSubstring(string str, unsigned int start, unsigned int end);
    string replaceAll(string str, char regex, char replacement);
    string replaceAll(string str, string regex, string replacement);
protected:
private:
};
#endif // UTILS_H
