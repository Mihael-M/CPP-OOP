#pragma once
#include "SmartSpeaker.h"
#include "SmartLight.h"
#include "SmartThermostat.h"

class SmartHome {
private:
	Device** devices;
	size_t size;
	size_t capacity;

	void copy(const SmartHome& other);
	void move(SmartHome&& other);
	void free();
	void resize(size_t newCap);
public:
	SmartHome();
	SmartHome(const SmartHome& other);
	SmartHome(SmartHome&& other)noexcept;
	SmartHome& operator=(const SmartHome& other);
	SmartHome& operator=(SmartHome&& other)noexcept;
	~SmartHome();

	void addDevice(Device* newDev);
	void removeDevice(unsigned index);

	Device& operator[](unsigned index) const;


};