#ifndef PROJECT_MUL_H
#define PROJECT_MUL_H

#include "BinaryExpression.h"

class Mul : public BinaryExpression {
public:
    Mul(Expression* left, Expression* right);
    virtual double calculate();
};


#endif //PROJECT_MUL_H
