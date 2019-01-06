#include "Minus.h"

Minus::Minus(Expression* _left, Expression* _right) : BinaryExpression(_left, _right) {}

double Minus::calculate()
{
    return left->calculate() - right->calculate();
}
