#include "UnaryExpression.h"
#include <stdio.h>

UnaryExpression::UnaryExpression(Expression* _expression) : expression(_expression){}

UnaryExpression::~UnaryExpression()
{
    delete expression;
}

double UnaryExpression::calculate()
{
    if (expression != NULL)
        return - expression->calculate();
    return 0.0;
}
