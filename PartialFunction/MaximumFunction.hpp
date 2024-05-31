#include "TypeFunction.hpp"
#pragma once

template<class T>
class MaximumFunction : public TypeFunction<T>{
    
public:
    MaximumFunction();
    MaximumFunction(PartialFunction<T>** funcs, size_t size);
    virtual T operator()(int32_t point) const override;
    virtual PartialFunction<T>* clone() const override;
};


template<class T>
MaximumFunction<T>::MaximumFunction() : TypeFunction<T>(){}

template<class T>
MaximumFunction<T>::MaximumFunction(PartialFunction<T>** funcs, size_t size) : TypeFunction<T>(funcs,size){}


template<class T>
T MaximumFunction<T>::operator()(int32_t point) const{
    T max = TypeFunction<T>::functions[0]->operator()(point);
    for(int i = 1;i<TypeFunction<T>::functionsCount;i++){
        T temp = TypeFunction<T>::functions[i]->operator()(point);
        if(temp.getValue() > max.getValue()){
            max = temp;
        }
    }
    return max;
}


template<class T>
PartialFunction<T>* MaximumFunction<T>::clone() const{
    return new MaximumFunction(*this);
}
