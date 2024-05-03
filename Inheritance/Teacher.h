#pragma once
#include "Person.h"

class Teacher : public Person {
private:
	char** subjects;
	size_t subjectsCount;

	void free();
	void copy(const Teacher& other);
	void move(Teacher&& other);

public:
	Teacher(const char* name, int age, const char* const* subjects, size_t subjectsCount);

	Teacher(const Teacher& other);
	Teacher& operator=(const Teacher& other);

	Teacher(Teacher&& other);
	Teacher& operator=(Teacher&& other);
	~Teacher();


};
