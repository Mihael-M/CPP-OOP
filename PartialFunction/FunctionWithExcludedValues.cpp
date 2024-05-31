#include <stdio.h>
#include "FunctionWithExcludedValues.h"


FunctionWithExcludedValues::FunctionWithExcludedValues(const int32_t* points,size_t size) : Function(points, size){}

bool FunctionWithExcludedValues::isPointExcluded(int32_t point) const{
    for(int i = 0;i<size;i++){
        if(point == points[i])
            return true;
    }
    return false;
}

int32_t FunctionWithExcludedValues::operator()(int32_t point) const{
    if(isPointExcluded(point))
        throw std::invalid_argument("The point is excluded");
    return point;
}
