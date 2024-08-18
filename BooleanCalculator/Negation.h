#pragma once
#include "UnaryExpression.h"

class Negation: public UnaryExpression{
public:
    Negation(Expression* expr);
    virtual bool evaluate(const BooleanIntepretation& interpretation)const  override;
    virtual Expression* clone() const override;
    
    
};
