#include <fstream>
#pragma once

template <class T>
class PartialFunction{
public:
    virtual T operator() (int x) const = 0;
    virtual bool isDefined(int point) const = 0;
    virtual ~PartialFunction() = default;
    virtual PartialFunction<T>* clone() const = 0;
};
