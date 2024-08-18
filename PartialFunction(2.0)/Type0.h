#include "Function.h"
#pragma once

class Type0 : public Function {
private:
    int32_t* results;
   
    void copy(const Type0& other);
    void move(Type0&& other);
    void free();
    
public:
    Type0()=default;
    Type0(const int32_t* points,size_t size,int32_t* results);
    Type0(const Type0& other);
    Type0(Type0&& other);
    
    Type0& operator=(const Type0& other);
    Type0& operator=(Type0&& other);
    
    ~Type0();
    virtual Pair operator()(int32_t point) const override;
    virtual bool isPointExcluded(int32_t point) const override;
    
};
