#include "SmartHome.h"

SmartHome& SmartHome::operator=(SmartHome&& other) noexcept
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}
	return *this;
}

SmartHome::~SmartHome()
{
	free();
}

void SmartHome::addDevice( Device* newDev)
{
	if (size == capacity)
		resize(capacity * 2);

	devices[size++] = newDev;
}

void SmartHome::removeDevice(unsigned index)
{
	if (index > size)
		return;

	delete devices[index];
	devices[index] = nullptr;
}

Device& SmartHome::operator[](unsigned index) const
{
	return *devices[index];
}

void SmartHome::copy(const SmartHome& other)
{
	size = other.size;
	capacity = other.capacity;
	devices = new Device * [capacity];
	for (size_t i = 0; i < size; i++)
	{
		*devices[i] = *other.devices[i];
	}
}

void SmartHome::move(SmartHome&& other)
{
	size = other.size;
	capacity = other.capacity;
	devices = other.devices;
	other.devices = nullptr;
}

void SmartHome::free()
{
	for (size_t i = 0; i < capacity; i++)
	{
		delete devices[i];
	}
	delete[] devices;
}

void SmartHome::resize(size_t newCap)
{
	capacity = newCap;
	Device** temp = new Device * [capacity];

	for (size_t i = 0; i < capacity; i++)
	{
		temp[i] = devices[i];
	}
	devices = temp;
	temp = nullptr;

}

SmartHome::SmartHome()
{
	devices = new Device * [10];
	size = 0;
	capacity = 10;
}

SmartHome::SmartHome(const SmartHome& other)
{
	copy(other);
}

SmartHome::SmartHome(SmartHome&& other) noexcept
{
	move(std::move(other));
}
SmartHome& SmartHome::operator=(const SmartHome& other)
{

	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}
