#include <iostream>

#include "Lexer.h"
#include "Parser.h"
#include "ShuntingYard.h"

using namespace std;

int main(int argc, char** argv){
    if (argc > 1){
        string commandsFileName = argv[1];
        Lexer lex;
        vector<string> stringsVec = lex.lex(commandsFileName);
        Parser parser;
        parser.start(stringsVec);
    }   

    return 0;  
}


