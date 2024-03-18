// Task4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
void mergeFiles(std::ifstream ifs, std::ofstream ofs)
{

}

void mergeFiles(const char* fileName, const char* secondFile,const char* thirdFile)
{
    std::ifstream ifs1(fileName);
    
    std::ofstream ofs(thirdFile);
    if (!ifs1.is_open()&& !ifs2.is_open()&& !ofs.is_open())
    {
        return;
    }
     mergeFiles(ifs1, ofs);
}


int main()
{
    
}

