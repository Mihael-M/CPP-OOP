#include "Employees.h"

void Employees::copy(const Employees& other)
{

	for (size_t i = 0; i < other.size; i++)
	{
		*data[i] = *other.data[i];
	}
	this->size = other.size;

}

void Employees::move(Employees&& other)
{
	for (size_t i = 0; i < other.size; i++)
	{
		data[i] = other.data[i];
		other.data[i] = nullptr;
	}
	this->size = other.size;
	

}

void Employees::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete data[i];
	}
	delete[] data;
}

void Employees::resize(unsigned newCapacity)
{
	capacity = newCapacity;
	Employee** temp = new Employee* [capacity];
	for (size_t i = 0; i < size; i++)
	{
		*temp[i] = *data[i];
	}
	delete data;
	data = temp;
	temp = nullptr;
	
}

Employees::Employees()
{
	data = new Employee*[10];
	size = 0;
	capacity = 10;
}

Employees::Employees(const Employees& other)
{
	copy(other);
}

Employees::Employees(Employees&& other)
{
	move(std::move(other));
}

Employees& Employees::operator=(const Employees& other)
{
	if (this != &other)
	{
		free();
		copy(other);

	}
	return *this;
}

Employees& Employees::operator=(Employees&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));

	}
	return *this;
}

Employees::~Employees()
{
	free();
}

void Employees::addEmployee(Employee* newEmployee)
{
	
	if (size == capacity)
		resize(capacity * 2);

	

	data[size++] = newEmployee;
	
}

double Employees::calculateSalary()
{
	double res = 0;
	for (size_t i = 0; i < size; i++)
	{
		res += data[i]->calculateSalary();
	}
	return res;
}



void Employees::sortBySalary()
{
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - i - 1; j++) {
			if (data[j]->calculateSalary() > data[j + 1]->calculateSalary()) {
			
				Employee* temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}

}

double Employees::findMaxSalary()
{
	double max = data[0]->calculateSalary();
	for (size_t i = 1; i < size; i++)
	{
		if (data[i]->calculateSalary() > max)
			max = data[i]->calculateSalary();
	}
	return max;
}

double Employees::findMinSalary()
{
	double min = data[0]->calculateSalary();
	for (size_t i = 1; i < size; i++)
	{
		if (data[i]->calculateSalary() < min)
			min = data[i]->calculateSalary();
	}
	return min;
}

double Employees::averageSalary()
{
	double res = 0;
	for (size_t i = 0; i < size; i++)
	{
		res += data[i]->calculateSalary();
	}
	return res / size;
}

Employee& Employees::getClosestToAverage()
{
	double closest = std::abs(averageSalary() - data[0]->calculateSalary());
	int index = 0;
	for (size_t i = 1; i < size; i++)
	{
		if (closest > std::abs(averageSalary() - data[i]->calculateSalary()))
		{
			closest = std::abs(averageSalary() - data[i]->calculateSalary());
			index = i;
		}
	}
	return *data[index];
}
