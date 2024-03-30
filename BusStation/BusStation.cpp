#include "BusStation.h"

void BusStation::copy(const BusStation& other)
{
	this->trip = new char[strlen(other.trip) + 1];
	strcpy_s(this->trip, strlen(other.trip) + 1, other.trip);
	setBusses(other.busses);
	this->currentBusses = other.currentBusses;
}

void BusStation::free()
{
	delete[] trip;
	trip = nullptr;
	busses;
	currentBusses = 0;
}

BusStation::BusStation(const Bus* busses, unsigned trips,unsigned currentBusses)
{
	setBusses(busses);
	
	this->currentBusses = currentBusses;
}

BusStation::BusStation(const BusStation& other)
{
	copy(other);
}

BusStation& BusStation::operator=(const BusStation& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

BusStation::~BusStation()
{
	free();
}

bool BusStation::hasTicket(const Passenger& passenger)
{
	for (size_t i = 0; i < currentBusses; i++)
	{
		if (busses[i].getPassenger()->getName() == passenger.getName())
		{
			return true;
		}
	}
	return false;

}

void BusStation::addBus(const Bus& bus)
{
	currentBusses++;
	if (currentBusses > MAX_BUSSES)
		return;
	busses[currentBusses] = bus;
}

void BusStation::setBusses(const Bus* busses)
{
	for (size_t i = 0; i < MAX_BUSSES; i++)
	{
		this->busses[i] = busses[i];
	}
}
