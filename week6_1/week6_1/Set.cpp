#include "Set.h"

void Set::setSet(const char* set)
{
	if (!set)
		return;
	this->set = new char[strlen(set) + 1];
	for (size_t i = 0; i < strlen(set); i++)
	{
		this->set[i] = set[i];
	}
}

void Set::setCapacity(unsigned capacity)
{
	this->capacity = capacity;
}

Set::Set(const char* set, unsigned capacity)
{
	setSet(set);
	setCapacity(capacity);
}

Set::Set(const Set& other)
{
	copy(other);

}

Set& Set::operator=(const Set& other)
{
	if (!other.set || &other == this)
		return;
	free();
	copy(other);
	return *this;
}

Set::~Set()
{
	free();
}

char* Set::getSet() const
{
	return set;
}

unsigned Set::getCapacity()
{
	return capacity;
}

void Set::free()
{
	delete[] set;
	set = nullptr;
	capacity = 0;
}

void Set::copy(const Set& other)
{
	
	set = new char[strlen(other.set) + 1];
	for (size_t i = 0; i < strlen(other.set); i++)
	{
		set[i] = other.set[i];
	}

}

void Set::addNum(unsigned num)
{
	if (strlen(set) > MAX)
		return;

	set[num] |= 1;

	
}

bool Set::contains(unsigned num) const 
{
	return false;
}
