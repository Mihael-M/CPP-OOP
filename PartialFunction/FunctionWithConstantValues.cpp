#include <stdio.h>
#include "FunctionWithConstantValues.h"


FunctionWithConstantValues::FunctionWithConstantValues(const int32_t* points,size_t size) : Function(points, size){}

bool FunctionWithConstantValues::isPointExcluded(int32_t point) const{
    return false;
}

int32_t FunctionWithConstantValues::operator()(int32_t point) const{

    for(int i = 0;i<size;i++){
        if(points[i] == point)
            return 1;
    }
    return 0;
}
