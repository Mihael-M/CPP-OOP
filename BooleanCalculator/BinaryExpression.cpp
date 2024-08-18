#include "BinaryExpression.h"
#include <stdio.h>

BinaryExpression::BinaryExpression(Expression* left,Expression* right) :
left(left),right(right){}

void BinaryExpression::fetchVariables(bool *variables)const
{
    left->fetchVariables(variables);
    right->fetchVariables(variables);
}
BinaryExpression::~BinaryExpression(){
    delete left;
    delete right;
}
