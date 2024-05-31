#pragma once
#include "Function.h"


class FunctionWithConstantValues : public Function{
    
    
public:
    FunctionWithConstantValues() = default;
    FunctionWithConstantValues(const int32_t* points,size_t size);
    
    
    virtual bool isPointExcluded(int32_t point) const override;
    virtual int32_t operator()(int32_t point)const override;
};
