#ifndef STRINGUTILS_H
#define STRINGUTILS_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class stringutils {
    public:
        /*
         * stringutils();
         * virtual ~stringutils();
         *
         */
        vector<string> split(string str, char deliminator);
        vector<string> split(string str, char delimiters[], bool addDelim);

        string getSubstring(string str, unsigned int start, unsigned int end);
        string getSubstring(string str, int fromEnd);
        
        string replaceAll(string str, char regex, char replacement);
        string replaceAll(string str, string regex, string replacement);

        string tostring(float value);

    protected:
        
    private:

};

#endif // STRINGUTILS_H
