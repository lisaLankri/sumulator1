#include "Mul.h"

Mul::Mul(Expression* _left, Expression* _right) : BinaryExpression(_left, _right) {}

double Mul::calculate()
{
    return left->calculate() * right->calculate();
}
