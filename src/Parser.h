#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>

using namespace std;

class Parser {

public:
    Parser();
    void start(vector<string>& commands);
    void run(vector<string>& commands);
};

#endif
