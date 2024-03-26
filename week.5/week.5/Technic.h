#pragma once
#include <iostream>
#include "Categories.h"
#include "BrokenAppliance.h"
class Technic {
private:
	char name[33] = "Unknown";
	char EGN[11] = "Unknown";
	bool categories[categories::NUM_CATEGORIES];
	double money = 0;
	int timesHired = 0;
	bool isWorking = false;
public:
	Technic() = default;
	Technic(const char* name, const char* EGN,const bool* categories, double money, int timesHired,bool isWorking)
	{
		setName(name);
		strcpy_s(this->EGN, EGN);
		this->isWorking = isWorking;
		for (int i = 0; i < categories::NUM_CATEGORIES; i++) {
			this->categories[i] = categories[i];
		}
		this->money = money;
		this->timesHired = timesHired;
	}
	const char* getName()const {
		return this->name;
	}
	void setName(const char* name)
	{
		strcpy_s(this->name, name);
	}
	const char* getEGN()const {
		return this->EGN;
	}
	void setEGN(const char* EGN)
	{
		strcpy_s(this->EGN, EGN);
	}
	bool getWorking() const
	{
		return this->isWorking;
	}
	void setWork(bool isWorking)
	{
		this->isWorking = isWorking;
	}
	double getMoney()const {
		return this->money;
	}
	void setMoney(double money)
	{
		this->money= money;
	}
	int getTimesHired()const {
		return this->timesHired;
	}
	void setTimesHired(int timesHired)
	{
		this->timesHired = timesHired;
	}

	bool canFix(const Technic& th,const BrokenAppliance& br) const;
	double averageEarnings(Technic& technic);
};
