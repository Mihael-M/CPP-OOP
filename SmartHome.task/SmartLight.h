#pragma once
#include"Device.h"

class SmartLight : public Device{
private:
	unsigned short brightnessLevel;

public:
	SmartLight(MyString name, MyString manufacturer, unsigned short brightnessLevel);
	void turnOn() override;
	void printDetails()override;
	void turnOff()override;


};