#pragma once
#include "Employee.h"

class HourlyEmployee : public Employee {
private:
	unsigned overtime;
public:

	HourlyEmployee(const char* name, double salary, unsigned overtime);
	double calculateSalary() override;


};

