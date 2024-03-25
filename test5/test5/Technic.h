#pragma once
#include <iostream>
class Technic {
	char name[33] = "Unknown";
	char EGN[11] = "Unknown";
	char category[7] = "";
	double money = 0;
	int timesHired = 0;
	Technic() = default;
	Technic(const char* name, const char* EGN, const char* category, double money, int timesHired)
	{
		std::strcpy(this->name, name);
		std::strcpy(this->EGN, EGN);
		std::strcpy(this->category, category);
		this->money = money;
		this->timesHired = timesHired;
	}
	void getName() {
		std::cout << this->name << std::endl;
	}
	void setName(const char* name)
	{
		
	}
};