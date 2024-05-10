#include "SmartThermostat.h"

SmartThermostat::SmartThermostat(MyString name, MyString manufacturer, double currentTemp, double wantedTemp) : Device(name, manufacturer)
{
	this->currentTemp = currentTemp;
	this->wantedTemp = wantedTemp;
}

void SmartThermostat::turnOn()
{
	std::cout << "SmartThermostat is on." << std::endl;
}
void SmartThermostat::printDetails()
{

	std::cout << name << " " << manufacturer << " " << currentTemp << " " << wantedTemp<< std::endl;
}
void SmartThermostat::turnOff()
{
	std::cout << "SmartThermostat is off." << std::endl;
}
