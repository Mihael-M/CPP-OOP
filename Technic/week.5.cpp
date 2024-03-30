// week.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Service.h"

int main()
{
	bool categories[] = { 0,1,0,0,1,1,0 };
	bool categories2[] = { 1,1,0,1,1,1,0 };
	bool categories3[] = { 1,1,0,0,1,1,0 };
	Technic tech1("Ico", "0445129514", categories, 100, 2, false);
	Technic tech2("Misho", "0362129514", categories2, 50, 1, false);
	Technic tech3("Kiril", "0445938514", categories3, 10, 1, false);
	Technic technics[30];
	Service service(technics,0);
	service.hireTechnic(tech1);

	service.hireTechnic(tech2);
	service.hireTechnic(tech3);
	std::ofstream ofs("kolbi.txt");
	service.saveAll(ofs, service);
}

