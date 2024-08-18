#include "MaximumOrMinimum.h"
#include <stdio.h>

void MaximumOrMinimum::copy(const MaximumOrMinimum &other)
{
    this->functions = new PartialFunction*[other.count];
    for(int i = 0;i<other.count;i++)
    {
        this->functions[i] = other.functions[i];
        
    }
    this->count=other.count;
    this->capacity=other.capacity;
}

void MaximumOrMinimum::move(MaximumOrMinimum &&other)
{
    
    this->functions=other.functions;
    other.functions=nullptr;
    this->count=other.count;
    other.count=0;
    this->capacity=other.capacity;
    other.capacity=0;
}
void MaximumOrMinimum::free()
{
    for(int i =0;i<count;i++)
    {
        delete functions[i];
    }
    delete[] functions;
}
void MaximumOrMinimum::resize(size_t newCap)
{
    PartialFunction** temp = new PartialFunction*[newCap];
    for(int i = 0;i<count;i++)
    {
        temp[i] = functions[i];
    }
    delete[] functions;
    functions=temp;
    this->capacity=newCap;
}

MaximumOrMinimum::MaximumOrMinimum()
{
    this->capacity = 8;
    this->functions = new PartialFunction*[capacity];
    this->count = 0;
}

MaximumOrMinimum::MaximumOrMinimum(PartialFunction** functions,size_t count)
{
    this->functions = new PartialFunction*[count];
    for(int i =0;i<count;i++)
    {
        this->functions[i] = functions[i];
    }
       
    this->count=this->capacity =count;
    
}

MaximumOrMinimum::MaximumOrMinimum (const MaximumOrMinimum &other)
{
    copy(other);
}
MaximumOrMinimum::MaximumOrMinimum(MaximumOrMinimum &&other)
{
    move(std::move(other));
}

MaximumOrMinimum& MaximumOrMinimum::operator=(const MaximumOrMinimum& other){
    
    if(this!=&other)
    {
        free();
        copy(other);
    }
    return *this;
}

MaximumOrMinimum& MaximumOrMinimum::operator=(MaximumOrMinimum&& other){
    
    if(this!=&other)
    {
        free();
        move(std::move(other));
    }
    return *this;
}

MaximumOrMinimum::~MaximumOrMinimum()
{
    free();
}
void MaximumOrMinimum::add(PartialFunction *function)
{
    if(count==capacity)
        resize(capacity*2);
    
    functions[count] = function;
}
bool MaximumOrMinimum::isDefined(int32_t point) const{
    for(int i =0;i<count;i++)
    {
        if(functions[i]->isDefined(point))
            return false;
    }
    return true;
}


