#include "Lexer.h"
#include "Utils.h"

vector<string> Lexer::lex(string & fileName){
    vector<string> stringsVec;
    ifstream file(fileName.c_str());
    if(file.is_open()) {
        string line;
        for (; getline(file, line);) {
            line = Utils::trim(line);
            if (line.size() > 0)
                stringsVec.push_back(line);
        }
    } else {
        throw "encounter an error while openning the file!";
    }
    file.close();
    return stringsVec;
};