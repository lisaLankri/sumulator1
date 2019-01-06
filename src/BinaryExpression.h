#ifndef PROJECT_BINARYEXPRESSION_H
#define PROJECT_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
public:
    BinaryExpression(Expression* left, Expression* right);
    ~BinaryExpression();
    virtual double calculate() = 0;
    void setLeft(Expression*);
    void setRight(Expression*);

protected:
    Expression* left;
    Expression* right;
};


#endif //PROJECT_BINARYEXPRESSION_H
