#pragma once
#include "Function.h"


class FunctionWithExcludedValues : public Function{
    
    
public:
    FunctionWithExcludedValues() = default;
    FunctionWithExcludedValues(const int32_t* points,size_t size);
    
    virtual bool isPointExcluded(int32_t point) const override;
    virtual int32_t operator()(int32_t point) const override;
};
