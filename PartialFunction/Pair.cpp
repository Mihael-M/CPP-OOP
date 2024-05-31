#include "Pair.h"
Pair::Pair(bool isDefined,int value) : isDefined(isDefined),value(value){}

bool Pair::getIsDefined() const
{
    return this->isDefined;
}

int Pair::getValue() const
{
    
    return this-> value;
}

void Pair::setIsDefined(bool isDefined)
{
    this->isDefined = isDefined;
}

void Pair::setValue(int value)
{
    this->value = value;
}
std::ostream& operator<<(std::ostream& os,const Pair& obj)
{
    os << "(" << obj.isDefined<< ", " << obj.value << ")";
    return os;
    
}

