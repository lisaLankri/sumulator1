#include "Div.h"

Div::Div(Expression* _left, Expression* _right) : BinaryExpression(_left, _right) {}

double Div::calculate()
{
    return left->calculate() / right->calculate();
}
