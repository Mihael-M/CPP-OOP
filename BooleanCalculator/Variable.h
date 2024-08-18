#pragma once
#include"Expression.h"

class Variable : public Expresion{
private:
    char symbol;
    
public:
    Variable(char symbol);
    char getSymbol() const;
    
    virtual bool evaluate(const BooleanIntepretation& interpretation) override;
    virtual Expression* clone() const override;
    virtual void fetchVariables(bool* variable) const override;
    
    
    
};
