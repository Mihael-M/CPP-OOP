#include "Pair.h"
#include <stdio.h>

int32_t Pair::getValue() const{
    return this->value;
}

bool Pair::getIsDefined() const
{
    return this->isDefined;
}
Pair::Pair(bool isDefined,int32_t value)
{
    this->isDefined=isDefined;
    this->value=value;
}
