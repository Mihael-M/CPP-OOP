#include "Service.h"


Technic Service::findTechnic(const Client& client) 
{
	for (size_t i = 0; i < SIZE_TEC ; i++)
	{
		if (technics[i].canFix(technics[i], client.brokenAppliance))
		{
			double moneyToReceive = client.brokenAppliance.getPriceFix();
			technics[i].setMoney(moneyToReceive);
			
			return technics[i];
		}
	}
	
}

void Service::hireTechnic(Technic& tech)
{

	if (Service::currentIndex < SIZE_TEC)
	{
		tech.setWork(true);
		technics[currentIndex] = tech;
		currentIndex++;
		tech.setTimesHired(tech.getTimesHired() + 1);
	}

}
void Service::fireTechnic(const char* EGN)
{
	for (size_t i = 0; i < SIZE_TEC; i++)
	{
		if (technics[i].getEGN() == EGN)
			technics[i].setWork(false);
	}
	

}
void Service::pay(Technic& tech, Client& client)
{
	double moneyToReceive = client.brokenAppliance.getPriceFix();
	double currMoney = tech.getMoney();
	currMoney += moneyToReceive;
	tech.setMoney(currMoney);
}


void Service::saveTechnic(std::ofstream& ofs,Technic& tech) {

	ofs << tech.getName()<<std::endl;
	ofs << tech.getEGN() << std::endl;
	ofs << tech.averageEarnings(tech) << std::endl;

}

void Service::saveAll(std::ofstream& ofs, Service& service)
{
	for (size_t i = 0; i < service.currentIndex; i++)
	{
		saveTechnic(ofs, service.technics[i]);
	}

}




