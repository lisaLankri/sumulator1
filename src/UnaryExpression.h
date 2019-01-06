#ifndef PROJECT_UNARYEXPRESSION_H
#define PROJECT_UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression {
public:
    UnaryExpression(Expression*);
    ~UnaryExpression();
    virtual double calculate();

private:
    Expression* expression;
};


#endif //PROJECT_UNARYEXPRESSION_H
