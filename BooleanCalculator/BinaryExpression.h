#include "Expression.h"
#pragma once

class BinaryExpression : public Expression{
protected:
    Expression* left;
    Expression* right;
public:
    BinaryExpression(Expression* left,Expression* right);
    
    void fetchVariables(bool* variables) const override;
    
    ~BinaryExpression();
    
};
