#pragma once
#include <iostream>
class Function{
protected:
    int32_t* points = nullptr;
    size_t size = 0;
    
    void copy(const Function& other);
    void move(Function&& other);
    void free();
    
public:
    Function() = default;
    Function(const int32_t* points,size_t count);
    Function(const Function& other);
    Function(Function&& other);
    Function& operator=(const Function& other);
    Function& operator=(Function&& other);
    virtual ~Function();
    
    virtual bool isPointExcluded(int32_t point) const = 0;
    virtual int32_t operator()(int32_t point)const = 0;
};
