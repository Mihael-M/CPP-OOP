#pragma once
#include "BinaryExpression.h"

class Conjunction : public BinaryExpression{
public:
    Conjunction(Expression* left,Expression* right);
    
    virtual bool evaluate(const BooleanIntepretation& intepretation) const override;
    
    virtual Expression* clone() const override;
    
    
};
