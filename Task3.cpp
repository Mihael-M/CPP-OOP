// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

void copyFiles(std::ifstream& ifs, std::ofstream& ofs)
{
	if (!ifs.is_open() && !ofs.is_open())
	{
		return;
	}
	while (!ifs.eof())
	{
		char buff[1024];
		ifs.getline(buff,1024);
		ofs << buff << std::endl;
	}
}
void copyFiles(const char* firstFile, const char* copyFile)
{
	std::ifstream ifs(firstFile);
	std::ofstream ofs(copyFile);
	if (!ifs.is_open() && !ofs.is_open())
	{
		return;
	}
	copyFiles(ifs, ofs);

}

int main()
{
	copyFiles("original.txt", "copy.txt");
}

