#include "UnaryExpression.h"
#include <stdio.h>

UnaryExpression::UnaryExpression(Expression* expr) : expr(expr){}

void UnaryExpression::fetchVariables(bool *variables)const{
    expr->fetchVariables(variables);
}
UnaryExpression::~UnaryExpression(){
    delete expr;
}
