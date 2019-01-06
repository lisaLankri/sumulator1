#ifndef PROJECT_DIV_H
#define PROJECT_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression {
public:
    Div(Expression* left, Expression* right);
    virtual double calculate();

};


#endif //PROJECT_DIV_H
