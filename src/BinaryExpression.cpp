#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression* _left, Expression* _right) : left(_left), right(_right)
{
}

BinaryExpression::~BinaryExpression()
{
    delete left;
    delete right;
}

void BinaryExpression::setLeft(Expression* _left)
{
    delete left;
    left = _left;
}
void BinaryExpression::setRight(Expression* _right)
{
    delete right;
    right = _right;
}
