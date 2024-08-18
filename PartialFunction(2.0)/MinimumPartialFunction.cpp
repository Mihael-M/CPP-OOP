#include "MinimumPartialFunction.h"
#include <stdio.h>

MinimumPartialFunction::MinimumPartialFunction(): MaximumOrMinimum(){}

MinimumPartialFunction::MinimumPartialFunction(PartialFunction** func,size_t size):MaximumOrMinimum(func, size){}

PartialFunction* MinimumPartialFunction::clone() const{
    
    return new MinimumPartialFunction(*this);
}

int32_t MinimumPartialFunction::operator()(int32_t point)const
{
    int32_t min = functions[0]->operator()(point);
    for (int i=1; i<count; i++) {
        int32_t current=functions[i]->operator()(point);
        if(min > current)
            min = current;
    }
    return min;
}
