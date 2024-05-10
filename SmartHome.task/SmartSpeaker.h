#pragma once
#include "Device.h"

class SmartSpeaker : public Device {
private:
	double volume;
public:
	SmartSpeaker(MyString name, MyString manufacturer, double volume);
	void turnOn() override;
	void printDetails()override;
	void turnOff()override;




};
