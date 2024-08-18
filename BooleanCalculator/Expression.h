#include "BooleanIntepretation.h"
#pragma once

class Expression{
public:
    virtual bool evaluate(const BooleanIntepretation& interpretation)const  = 0;
    virtual Expression* clone() const = 0;
    virtual void fetchVariables(bool* variable) const = 0;
    
    virtual ~Expression() = default;
    
    
};
