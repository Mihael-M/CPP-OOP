#include "Implication.h"
#include <stdio.h>

Implication:: Implication(Expression* left,Expression* right) :
BinaryExpression(left, right){}

bool Implication::evaluate(const BooleanIntepretation &intepretation) const
{
    return left->evaluate(intepretation) && right->evaluate(intepretation);
}

Expression* Implication::clone() const{
    return new Implication(left->clone(),right->clone());
}
