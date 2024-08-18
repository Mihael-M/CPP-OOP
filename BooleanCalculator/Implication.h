#pragma once
#include "BinaryExpression.h"

class Implication : public BinaryExpression{
  
public:
    Implication(Expression* left,Expression* right);
    
    virtual bool evaluate(const BooleanIntepretation& intepretation) const override;
    
    virtual Expression* clone() const override;
};
