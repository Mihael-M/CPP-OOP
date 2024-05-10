#pragma once
#include "Device.h"

class SmartThermostat : public Device {
private:
	double currentTemp;
	double wantedTemp;
public:
	SmartThermostat(MyString name, MyString manufacturer, double currentTemp, double wantedTemp);
	void turnOn() override;
	void printDetails()override;
	void turnOff()override;



};
