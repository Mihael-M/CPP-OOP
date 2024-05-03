#pragma once
#include "Set.h"
class SetByCriteria : private Set {
public:
    SetByCriteria(unsigned n, bool (*incl)(unsigned n));
    void setInclude(bool (*incl)(unsigned n));

    using Set::print;
    using Set::contains;

private:
    void fillSet(bool (*criteria)(unsigned n));
};
