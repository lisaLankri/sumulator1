#ifndef PROJECT_PLUS_H
#define PROJECT_PLUS_H

#include "BinaryExpression.h"

class Plus : public BinaryExpression {
public:
    Plus(Expression* left, Expression* right);
    virtual double calculate();

};


#endif //PROJECT_PLUS_H
