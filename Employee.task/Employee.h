#pragma once
#include <iostream>

#pragma warning(disable : 4996)
class Employee {
protected:
	char* name;
	double salary;
private:
	void copy(const Employee& other);
	void move(Employee&& other);
	void free();

public:
	Employee();
	Employee(const char* name, double salary);
	Employee(const Employee& other);
	Employee(Employee&& other) noexcept;
	Employee& operator=(const Employee& other);
	Employee& operator=(Employee&& other) noexcept;
	virtual ~Employee();
	
	friend std::ostream& operator<<(std::ostream& os, const Employee& em);
	virtual double calculateSalary() = 0;
	Employee* createEmployee(std::istream& is);
};
