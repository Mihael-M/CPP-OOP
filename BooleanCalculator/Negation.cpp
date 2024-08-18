#include "Negation.h"
#include <stdio.h>

Negation::Negation(Expression* expr) : UnaryExpression(expr){}

bool Negation::evaluate(const BooleanIntepretation &interpretation)const
{
    return !expr->evaluate(interpretation);
}

Expression* Negation::clone() const{
    return new Negation(*this);
}
