#pragma once
#include <iostream>
class SoftwareEngineer {

private:
	char* name = nullptr;
	char* position = nullptr;
	int salary = 0;
	void copy(const SoftwareEngineer& other);
	void free();
public:

	SoftwareEngineer() = default;
	SoftwareEngineer(const char* name, const char* position, int salary);
	~SoftwareEngineer();
	SoftwareEngineer(const SoftwareEngineer& other);
	SoftwareEngineer& operator=(const SoftwareEngineer& other);
	const char* getName()const;
	void setName(const char* name);
	const char* getPosition() const;
	void setPosition(const char* position);
	int getSalary()const;
	void setSalary(int salary);


};