#include "PartialFunction.h"
#pragma once
template<class Function>
class PartialFunctionByCriteria : public PartialFunction{
public:
    PartialFunctionByCriteria()=default;
    PartialFunctionByCriteria(const Function& func);
    virtual bool isDefined(int32_t point) const override;
    virtual int32_t operator() (int32_t point) const override;
    virtual PartialFunction* clone() const override;
    
private:
    Function func;
    
};

template <class Function>
PartialFunctionByCriteria<Function>::PartialFunctionByCriteria(const Function& func)
{
    this->func=func;
}
template <class Function>
bool PartialFunctionByCriteria<Function>::isDefined(int32_t point) const{
    return !func.isPointExcluded(point);
}

template <class Function>
int32_t PartialFunctionByCriteria<Function>::operator() (int32_t point) const{
    return func(point).getValue();
}

template <class Function>
PartialFunction* PartialFunctionByCriteria<Function>::clone() const {
    return new PartialFunctionByCriteria(*this);
}
