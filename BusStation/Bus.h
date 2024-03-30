#pragma once
#include "passenger.h"

class Bus {
private:
	char* plate = nullptr;
	unsigned seats = 0;
	unsigned priceAdults = 0;
	unsigned priceStudents = 0;
	Passenger* passengers=nullptr;
	unsigned currentPassengers = 0;
	void copy(const Bus& other);
	void free();
public:
	Bus() = default;
	Bus(const char* plate, unsigned seats, unsigned priceAdults, unsigned priceStudents,const Passenger* passengers,unsigned currentPassengers);
	Bus(const Bus& other);
	Bus& operator=(const Bus& other);
	~Bus();
	Passenger* getPassenger()const;
	void setPlate(const char* plate);
	void setSeats(unsigned seats);
	void setPriceAdults(unsigned priceAdults);
	void setPriceStudents(unsigned priceStudents);
};