#pragma once
#include<iostream>

constexpr int MAX_LENGHT = 21;
class Passenger {
private:
	char name[MAX_LENGHT]="Unknown";
	unsigned age = 0;
public:
	Passenger() = default;
	Passenger(const char* name,unsigned age);
	const char* getName() const;
	void setName(const char* name);

};