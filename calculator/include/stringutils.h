#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class StringUtils {
    public:
        vector<string> split(string str, char delimiter);
        vector<string> split(string str, char delimiters[], unsigned int delimitersSize, bool addDelim);

        string getSubstring(string str, unsigned int start, unsigned int end);
        string getSubstring(string str, int fromEnd);
        
        string replaceAll(string str, char regex, char replacement);
        string replaceAll(string str, string regex, string replacement);
    
        string dropIndex(string str, unsigned int idx);

        string tostring(int value);
        string tostring(float value);
        string tostring(long double value);
        string tostring(char value);
    protected:
        
    private:

};

#endif // STRINGUTILS_H
