#pragma once
#include<iostream>

class Person {
private:
	char* name = nullptr;
	int age = 0;

	void copy(const Person& other);
	void free();
	void move(Person&& other);

public:
	Person() = default;
	Person(const char* name, int age);

	Person(const Person& other);
	Person& operator=(const Person& other);

	Person(Person&& other);
	Person& operator=(Person&& other);

	const char* getName() const;
	int getAge() const;

	~Person();
	void print() const;

protected:
	void setName(const char* name);
	void setAge(int age);
};