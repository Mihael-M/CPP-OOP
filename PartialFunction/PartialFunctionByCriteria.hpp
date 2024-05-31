#include "PartialFunction.hpp"
#include <stdio.h>
#pragma once

template<class Func,class T>
class PartialFunctionByCriteria : public PartialFunction<T>
{
private:
    Func func;
public:
    PartialFunctionByCriteria() = default;
    PartialFunctionByCriteria(const Func& function);
    virtual T operator()(int32_t point) const override;
    virtual bool isDefined(int32_t point) const override;
    virtual PartialFunction<T>* clone() const override;
};





template<class Func,class T>
PartialFunctionByCriteria<Func,T>::PartialFunctionByCriteria(const Func& function){
    this->func = function;
}




template<class Func,class T>
T PartialFunctionByCriteria<Func,T>::operator()(int32_t point) const{
    return T(isDefined(point),func(point));
}


template<class Func,class T>
bool PartialFunctionByCriteria<Func,T>::isDefined(int32_t point) const{
    return !func.isPointExcluded(point);
}

template<class Func,class T>
PartialFunction<T>* PartialFunctionByCriteria<Func,T>::clone() const{
    return new PartialFunctionByCriteria(*this);
}
