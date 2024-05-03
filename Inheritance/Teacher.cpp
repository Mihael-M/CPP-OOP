#include "Teacher.h"
static char** copyArrayOfString(const char* const* strings, size_t size)
{
	char** res = new char* [size];

	for (size_t i = 0; i < size; i++)
	{
		res[i] = new char[strlen(strings[i]) + 1];
		strcpy(res[i], strings[i]);
	}

	return res;
}
static void freeArraysOfString(char** strings, unsigned stringsCount)
{
	for (size_t i = 0; i < stringsCount; i++)
		delete[] strings[i];
	delete[] strings;
}
void Teacher::free()
{
	freeArraysOfString(subjects, subjectsCount);
}
void Teacher::copy(const Teacher& other)
{
	copyArrayOfString(other.subjects, other.subjectsCount);
	subjectsCount = other.subjectsCount;
}

void Teacher::move(Teacher&& other)
{
	subjects = other.subjects;
	subjectsCount = other.subjectsCount;
	other.subjects = nullptr;
	other.subjectsCount = 0;
}

Teacher::Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount) : Person(name, age)
{
	this->subjects = copyArrayOfString(subjects, subjectsCount);
	this->subjectsCount = subjectsCount;
}

Teacher::Teacher(const Teacher& other)
{
	copy(other);
}

Teacher& Teacher::operator=(const Teacher& other)
{
	if (this != &other)
	{
		Person::operator=(other);
		free();
		copy(other);
	}
	return *this;
}

Teacher::Teacher(Teacher&& other)
{
	move(std::move(other));
}

Teacher& Teacher::operator=(Teacher&& other)
{
	if (this != &other)
	{
		Person::operator=(std::move(other));
		free();
		move(std::move(other));
	}
	return *this;
}

Teacher::~Teacher()
{
	free();
}
