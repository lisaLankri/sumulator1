#ifndef PROJECT_VARIABLE_H
#define PROJECT_VARIABLE_H

#include "Expression.h"
#include <string>

using namespace std;

class Variable : public Expression {
public:
    Variable(string);
    virtual double calculate();

private:
    string variableName;

};


#endif //PROJECT_VARIABLE_H
