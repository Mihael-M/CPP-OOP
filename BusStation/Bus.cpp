#include "Bus.h"

void Bus::copy(const Bus& other)
{
	this->plate = new char[strlen(other.plate) + 1];
	strcpy_s(this->plate, strlen(other.plate) + 1, other.plate);
	this->passengers = new Passenger[other.currentPassengers];
	for (size_t i = 0; i < currentPassengers; i++)
	{
		this->passengers[i] = other.passengers[i];
	}
	this->seats = other.seats;
	this->priceAdults = other.priceAdults;
	this->priceStudents = other.priceStudents;

}

void Bus::free()
{
	delete[] plate;
	plate = nullptr;
	seats = 0;
	priceAdults = 0;
	priceStudents = 0;
}

Bus::Bus(const char* plate, unsigned seats, unsigned priceAdults, unsigned priceStudents,const Passenger* passengers,unsigned currentPassengers)
{
	setPlate(plate);
	setSeats(seats);
	setPriceAdults(priceAdults);
	setPriceStudents(priceStudents);
	this->passengers = new Passenger[currentPassengers];
	for (size_t i = 0; i < currentPassengers; i++)
	{
		this->passengers[i] = passengers[i];
	}
	this->currentPassengers = currentPassengers;
}

Bus::Bus(const Bus& other)
{
	copy(other);
}

Bus& Bus::operator=(const Bus& other)
{
	if (&other != this)
	{
		free();
		copy(other);
	}
	return *this;
}

Bus::~Bus()
{
	free();
}

Passenger* Bus::getPassenger() const
{
	return passengers;
}

void Bus::setPlate(const char* plate)
{
	this->plate = new char[strlen(plate) + 1];
	strcpy_s(this->plate, strlen(plate) + 1, plate);
	
}

void Bus::setSeats(unsigned seats)
{
	this->seats = seats;
	
}

void Bus::setPriceAdults(unsigned priceAdults)
{
	this->priceAdults = priceAdults;
	
}

void Bus::setPriceStudents(unsigned priceStudents)
{
	this->priceStudents = priceStudents;
}
