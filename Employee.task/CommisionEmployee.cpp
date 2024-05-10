#include "CommisionEmployee.h"


CommisionEmployee::CommisionEmployee(const char* name, double salary, double commision) : Employee(name, salary)
{
    this->commision = commision;
}
double CommisionEmployee::calculateSalary()
{
    return salary + salary * commision;
}
