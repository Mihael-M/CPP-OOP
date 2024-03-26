#pragma once
#include <iostream>
#include "Technic.h"
#include "Client.h"
#include <fstream>
const int SIZE_TEC = 30;
class Service {
private:
	Technic technics[SIZE_TEC];
	int currentIndex = 0;
public:
	Service() = default;
	Service(Technic* technics, int curr)
	{
		for (size_t i = 0; i < SIZE_TEC; i++)
		{
			this->technics[i] = technics[i];
		}
		this->currentIndex = curr;
	}
	Technic findTechnic(const Client& client);
	void hireTechnic(Technic& tech);
	void fireTechnic(const char* EGN);
	void pay(Technic& tech, Client& client);
	
	void saveTechnic(std::ofstream& ofs,Technic& tech);
	void saveAll(std::ofstream& ofs, Service& service);

};
