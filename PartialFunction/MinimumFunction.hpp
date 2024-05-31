#include "TypeFunction.hpp"
#pragma once

template<class T>
class MinimumFunction : public TypeFunction<T>{
    
public:
    MinimumFunction();
    MinimumFunction(PartialFunction<T>** funcs, size_t size);
    virtual T operator()(int32_t point) const override;
    virtual PartialFunction<T>* clone() const override;
};


template<class T>
MinimumFunction<T>::MinimumFunction() : TypeFunction<T>(){}

template<class T>
MinimumFunction<T>::MinimumFunction(PartialFunction<T>** funcs,size_t size) : TypeFunction<T>(funcs,size){}


template<class T>
T MinimumFunction<T>::operator()(int32_t point)const{
    T min = TypeFunction<T>::functions[0]->operator()(point);
    for(int i = 1;i<TypeFunction<T>::functionsCount;i++){
        T curr = TypeFunction<T>::functions[i]->operator()(point);
        if(curr.getValue() < min.getValue()){
            min = curr;
        }
    }
    return min;
}

template<class T>
PartialFunction<T>* MinimumFunction<T>::clone() const{
    return new MinimumFunction(*this);
}
