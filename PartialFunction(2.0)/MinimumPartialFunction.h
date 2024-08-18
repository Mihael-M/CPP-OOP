#include "MaximumOrMinimum.h"
#pragma once

class MinimumPartialFunction : public MaximumOrMinimum{
    
public:
    MinimumPartialFunction();
    MinimumPartialFunction(PartialFunction** functions,size_t size);
    virtual int32_t operator() (int32_t point) const override;
    virtual PartialFunction* clone() const override;
};
