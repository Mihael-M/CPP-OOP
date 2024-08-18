#include "Disjunction.h"
#include <stdio.h>

Disjunction::Disjunction(Expression* left,Expression* right):BinaryExpression(left, right){}

bool Disjunction::evaluate(const BooleanIntepretation &intepretation)const
{
    return left->evaluate(intepretation) && right->evaluate(intepretation);
}

Expression* Disjunction::clone()const{
    return new Disjunction( left->clone() , right->clone());
}
