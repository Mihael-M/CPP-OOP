#include "SmartSpeaker.h"

SmartSpeaker::SmartSpeaker(MyString name, MyString manufacturer, double volume) : Device(name,manufacturer), volume(volume)  {}

void SmartSpeaker::turnOn()
{
	std::cout << "SmartSpeaker is on." << std::endl;
}
void SmartSpeaker::printDetails()
{
	std::cout << name << " " << manufacturer << " " << volume << std::endl;
}
void SmartSpeaker::turnOff()
{
	std::cout << "SmartSpeaker is off." << std::endl;
}

