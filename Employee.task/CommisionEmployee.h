#pragma once
#include "Employee.h"


class CommisionEmployee : public Employee {
private:
	double commision;
public:
	CommisionEmployee(const char* name, double salary,double commision);
	double calculateSalary() override;
};
