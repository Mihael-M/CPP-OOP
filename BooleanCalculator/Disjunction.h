#pragma once
#include "BinaryExpression.h"

class Disjunction : public BinaryExpression{
    
public:
    Disjunction(Expression* left,Expression* right);
    
    virtual bool evaluate(const BooleanIntepretation& intepretation) const override;
    
    virtual Expression* clone() const override;
};
