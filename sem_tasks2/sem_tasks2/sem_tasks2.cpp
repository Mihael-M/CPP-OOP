// sem_tasks2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs("sem_tasks2.cpp");
    if (!ifs.is_open())
    {
        return -1;
    }
    while (!ifs.eof())
    {
        char buff[1024];
        ifs.getline(buff, 1024);
        std::cout << buff << std::endl;
    }
    ifs.close();
   
}

