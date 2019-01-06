#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Lexer {
public:
    Lexer() {}
    vector<string> lex(string & fileName);
};

#endif