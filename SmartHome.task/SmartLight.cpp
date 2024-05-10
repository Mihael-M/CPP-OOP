#include "SmartLight.h"

SmartLight::SmartLight(MyString name, MyString manufacturer, unsigned short brightnessLevel) : Device(name,manufacturer)
{
	this->brightnessLevel = brightnessLevel;
}

void SmartLight::turnOn()
{
	std::cout << "SmartLight is on."<< std::endl;
}
void SmartLight::printDetails()
{

	std::cout << name << " " << manufacturer << " " << brightnessLevel << std::endl;
}
void SmartLight::turnOff()
{
	std::cout << "SmartLight is off." << std::endl;
}
