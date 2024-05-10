#include "HourlyEmployee .h"

HourlyEmployee::HourlyEmployee(const char* name, double salary, unsigned overtime) : Employee(name, salary)
{
    this->overtime = overtime;
}

double HourlyEmployee::calculateSalary()
{
    return 40 * 4 * salary + salary * 0.5 * overtime;
}
