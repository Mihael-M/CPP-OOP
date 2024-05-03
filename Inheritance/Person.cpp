#include "Person.h"

void Person::copy(const Person& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	this->age = other.age;
}

void Person::free()
{
	delete[] name;
	name = nullptr;
	age = 0;
}

void Person::move(Person&& other)
{
	name = other.name;
	other.name = nullptr;
	this->age = other.age;
}

Person::Person(const char* name, int age)
{
	setName(name);
	setAge(age);

}

Person::Person(const Person& other)
{
	copy(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Person::Person(Person&& other)
{
	move(std::move(other));
}

Person& Person::operator=(Person&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}
	return *this;
}

const char* Person::getName() const
{
	return name;
}

int Person::getAge() const
{
	return age;
}

Person::~Person()
{
	free();
}

void Person::print() const
{
	std::cout << name << " " << age << std::endl;
}

void Person::setName(const char* name)
{
	if (name == nullptr || this->name == name)
		return;

	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

}

void Person::setAge(int age)
{
	this->age = age;
}
