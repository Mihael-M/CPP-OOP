#include "Function.h"
#pragma once

class FunctionWithStandartValue : public Function{
    
private:
    int32_t* results = nullptr;
    
    void copy(const FunctionWithStandartValue& other);
    void move(FunctionWithStandartValue&& other);
    void free();
    
public:
    FunctionWithStandartValue() = default;
    FunctionWithStandartValue(const int32_t* points,size_t size,const int32_t* results);
    FunctionWithStandartValue(const FunctionWithStandartValue& other);
    FunctionWithStandartValue(FunctionWithStandartValue&& other);
    FunctionWithStandartValue& operator=(const FunctionWithStandartValue& other);
    FunctionWithStandartValue& operator=(FunctionWithStandartValue&& other);
    ~FunctionWithStandartValue();
    
    virtual bool isPointExcluded(int32_t point) const override;
    virtual int32_t operator()(int32_t point) const override;
};
