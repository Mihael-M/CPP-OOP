#include "Variable.h"
#include <stdio.h>

Variable::Variable(char symbol):symbol(symbol){}
char Variable::getSymbol() const {
    
    return this->symbol;
}
bool Variable::evaluate(const BooleanIntepretation &interpretation)
{
    return interpretation.getValue(symbol);
}

void Variable::fetchVariables(bool *variables) const{
    variables[symbol - 'a'] = true;
}

Expression* Variable::clone() const {
    
    return new Variable(*this);
}
