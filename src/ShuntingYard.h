#ifndef PROJECT_SHUNTINGYARD_H
#define PROJECT_SHUNTINGYARD_H

#include <string>

using namespace std;
class Expression;

class ShuntingYard {
public:
    static Expression* createExpression(string expression);

private:
    static bool IsNumber(const string &symbol);
    static bool IsVariable(const string &symbol);
    static int Priority(const string &c);
    static bool isOperator(const string &c);
    static bool isOperator(char c);
};


#endif //PROJECT_SHUNTINGYARD_H
