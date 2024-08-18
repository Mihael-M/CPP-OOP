#include"PartialFunction.h"
#pragma once

class MaximumOrMinimum : public PartialFunction{
protected:
    PartialFunction** functions;
    size_t count;
    size_t capacity;
    
    void copy(const MaximumOrMinimum& other);
    void move(MaximumOrMinimum&& other);
    void free();
    void resize(size_t newCap);
    
public:
    MaximumOrMinimum();
    MaximumOrMinimum(PartialFunction** functions,size_t count);
    MaximumOrMinimum(const MaximumOrMinimum& other);
    MaximumOrMinimum(MaximumOrMinimum&& other);
    
    MaximumOrMinimum& operator=(const MaximumOrMinimum& other);
    MaximumOrMinimum& operator=(MaximumOrMinimum&& other);
    virtual ~MaximumOrMinimum();
    void add(PartialFunction* function);
    virtual bool isDefined(int32_t point) const override;
    
};
