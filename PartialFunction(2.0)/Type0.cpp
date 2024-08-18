#include "Type0.h"
#include <stdio.h>

void Type0::copy(const Type0 &other)
{
    this->results = new int32_t[other.count];
    for(int i =0;i<other.count;i++)
        this->results[i] = other.results[i];
}
void Type0::move(Type0 &&other)
{
    this->results=other.results;
    other.results=nullptr;
    
}
void Type0::free()
{
    delete[] results;
}
Type0::Type0(const int32_t* points,size_t size,int32_t* results)
{
    this->results=new int32_t[size];
    for(int i=0;i<size;i++)
    {
        this->results[i] = results[i];
    }
    
}
Type0::Type0(const Type0& other)
{
    copy(other);
}
Type0::Type0( Type0&& other)
{
    move(std::move(other));
}
Type0& Type0::operator=(const Type0 &other)
{
    if(this!=&other)
    {
        free();
        copy(other);
    }
    return *this;
}
Type0& Type0::operator=(Type0 &&other)
{
    if(this!=&other)
    {
        free();
        move(std::move(other));
    }
    return *this;
}
Type0::~Type0()
{
    free();
}
bool Type0::isPointExcluded(int32_t point)const
{
    for (int i=0; i<count; i++) {
        if(points[i]==point)
            return false;
    }
    return true;
}
Pair Type0::operator() (int32_t point)const {
    int32_t value = 0;
    for(int i = 0;i<count;i++)
    {
        if(point == points[i])
            value=points[i];
    }
    return Pair(!isPointExcluded(point), value);
}
