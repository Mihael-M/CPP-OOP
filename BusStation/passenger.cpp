#include "passenger.h"

Passenger::Passenger(const char* name,unsigned age)
{
    setName(name);
    this->age = age;
}

const char* Passenger::getName() const
{
    return name;
}

void Passenger::setName(const char* name)
{
    if (!name || this->name == name)
    return;
    for (size_t i = 0; i < MAX_LENGHT; i++)
    {
        this->name[i] = name[i];
    }
   
}
