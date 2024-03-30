#pragma once
#include "Bus.h"
constexpr int MAX_BUSSES = 30;
class BusStation {
private:
	Bus busses[MAX_BUSSES];
	unsigned currentBusses = 0;
	char* trip = nullptr;
	void copy(const BusStation& other);
	void free();
public:
	BusStation() = default;
	BusStation(const Bus* busses, unsigned trips,unsigned currentBusses);
	BusStation(const BusStation& other);
	BusStation& operator=(const BusStation& other);
	~BusStation();
	bool hasTicket(const Passenger& passenger);
	void addBus(const Bus& bus);
	void setBusses(const Bus* busses);
};
