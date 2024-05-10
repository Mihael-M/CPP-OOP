#include "Employee.h"


Employee::Employee() {

	strcpy(this->name, "Unknown");
	salary = 0;
}


std::ostream& operator<<(std::ostream& os, const Employee& em)
{
	return os << em.name << "with salary: " << em.salary;
}

void Employee::copy(const Employee& other)
{
	name = new char[strlen(other.name)+1];
	strcpy(this->name, other.name);
	this->salary = other.salary;
}

void Employee::move(Employee&& other)
{
	this->name = other.name;
	other.name = nullptr;

	salary = other.salary;
}

void Employee::free()
{
	delete[] name;
	salary = 0;
}
Employee::Employee(const char* name, double salary)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	this->salary = salary;
}

Employee::Employee(const Employee& other)
{
	copy(other);
}



Employee::Employee(Employee&& other) noexcept
{
	move(std::move(other));
}


Employee& Employee::operator=(const Employee& other)
{
	if (this != &other)
	{
		free();
		copy(other);

	}
	return *this;
}
Employee& Employee::operator=(Employee&& other) noexcept
{
	if (this != &other)
	{
		free();
		move(std::move(other));

	}
	return *this;

}
Employee::~Employee()
{
	free();
}
