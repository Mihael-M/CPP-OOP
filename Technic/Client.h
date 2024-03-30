#pragma once
#include <iostream>
#include "BrokenAppliance.h"
class Client {
public:
	char name[33]="";
	BrokenAppliance brokenAppliance;
	Client() = default;
	Client(const char* name, const BrokenAppliance brokenAppliance)
	{
		this->brokenAppliance = brokenAppliance;
		strcpy_s(this->name, name);
	}

};
