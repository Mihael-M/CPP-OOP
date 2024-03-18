// sem_tasks2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

unsigned getCharCount(std::ifstream& ifs,char ch)
{
	if (!ifs.is_open())
	{
		return 0;
	}
	unsigned int count = 0;
	while (true)
	{
		char current = ifs.get();
		if (ifs.eof())
		{
			break;
		}
		if (current == ch)
		{
			count++;
		}
	}
	return count;
}

unsigned count(const char* fileName)
{
	std::ifstream ifs(fileName);
	if (!ifs.is_open())
	{
		return 0;
	}

	return getCharCount(ifs, '\n')+1;
}
		
	

int main()
{
	std::cout << count("sem_tasks2.2.cpp");
}
