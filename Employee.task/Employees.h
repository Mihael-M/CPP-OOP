#pragma once
#include "HourlyEmployee .h"
#include "CommisionEmployee.h"

class Employees {
private:
	Employee** data;
	unsigned size;
	unsigned capacity;
	void copy(const Employees& other);
	void move(Employees&& other);
	void free();
	void resize(unsigned newCapacity);
public:

	Employees();
	Employees(const Employees& other);
	Employees(Employees&& other);

	Employees& operator=(const Employees& other);
	Employees& operator=(Employees&& other);
	~Employees();

	void addEmployee( Employee* newEmployee);
	double calculateSalary();
	void sortBySalary();
	double findMaxSalary();
	double findMinSalary();
	double averageSalary();
	Employee& getClosestToAverage();
};
