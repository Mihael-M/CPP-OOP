#include "Type2.h"
#include <stdio.h>

Type2::Type2(const int32_t* points,size_t count) : Function(points, count){}

bool Type2::isPointExcluded(int32_t point)const {
    return false;
}

Pair Type2::operator()(int32_t point)const{
    int32_t value=0;
    for(int i =0;i<count;i++)
    {
        if(points[i] == point)
            value=1;
    }
    return Pair(isPointExcluded(point), value);
}
