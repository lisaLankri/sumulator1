#ifndef PROJECT_MINUS_H
#define PROJECT_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression* left, Expression* right);
    virtual double calculate();

};


#endif //PROJECT_MINUS_H
