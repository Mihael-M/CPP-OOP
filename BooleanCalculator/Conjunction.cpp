#include "Conjunction.h"
#include <stdio.h>

Conjunction::Conjunction( Expression* left, Expression* right) :
BinaryExpression(left, right){}

bool Conjunction::evaluate(const BooleanIntepretation &intepretation)const{
    
    return left->evaluate(intepretation) && right->evaluate(intepretation);
}
Expression* Conjunction::clone()const{
    return new Conjunction(left->clone(), right->clone());
}

