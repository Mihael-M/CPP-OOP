#include "SoftwareEngineer.h"

void SoftwareEngineer::copy(const SoftwareEngineer& other)
{
	this->name = new char[std::strlen(other.name) + 1];
	strcpy_s(this->name, std::strlen(other.name)+1, other.name);
	this->position = new char[std::strlen(other.position) + 1];
	strcpy_s(this->position, std::strlen(other.position) + 1, other.position);
	this->salary = other.salary;
}

void SoftwareEngineer::free()
{
	delete[] name;
	delete[] position;
	name = nullptr;
	position = nullptr;
	salary = 0;
}

SoftwareEngineer::SoftwareEngineer(const char* name, const char* position, int salary)
{
	setName(name);
	setPosition(position);
	setSalary(salary);
}

SoftwareEngineer::~SoftwareEngineer()
{
	free();
}

SoftwareEngineer::SoftwareEngineer(const SoftwareEngineer& other)
{
	copy(other);
}

SoftwareEngineer& SoftwareEngineer::operator=(const SoftwareEngineer& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

const char* SoftwareEngineer::getName() const
{
	return name;
}

void SoftwareEngineer::setName(const char* name)
{
	if (!name || this->name == name)
		return;
	this->name = new char[std::strlen(name) + 1];
	strcpy_s(this->name, std::strlen(name) + 1, name);
}

const char* SoftwareEngineer::getPosition() const
{
	return position;
}

void SoftwareEngineer::setPosition(const char* position)
{
	if (!position || this->position == position)
		return;
	this->position = new char[std::strlen(position) + 1];
	strcpy_s(this->position, std::strlen(position) + 1, position);
}

int SoftwareEngineer::getSalary() const
{
	return salary;
}

void SoftwareEngineer::setSalary(int salary)
{
	this->salary = salary;
}

