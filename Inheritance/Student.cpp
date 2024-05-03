#include "Student.h"

Student::Student(const char* name, int age, size_t fn) : Person(name,age) {}

size_t Student::getFn() const
{
	return fn;
}

void Student::setFn(size_t fn)
{
	this->fn = fn;
}
