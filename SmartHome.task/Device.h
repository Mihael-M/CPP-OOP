#pragma once
#include<iostream>
#include "MyString.h"
class Device {
protected:
	MyString name;
	MyString manufacturer;

public:
	Device(MyString name, MyString manufaturer);
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
	virtual void printDetails() = 0;
	

};
