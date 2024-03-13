// pract.2.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
void writeInBinFile(std::ostream& ofs, const int* arr, unsigned size)
{
    ofs.write((char*)arr, size * sizeof(int));
}

void writeInBinFile(const char* fileName, const int* arr, unsigned size)
{
    std::ofstream ofs(fileName, std::ios::binary);

    if (!ofs.is_open())
    {
      return;
    }
    writeInBinFile(ofs, arr, size);
}

unsigned fileSize(std::ifstream& ifs,int* arr,unsigned& size)
{
    if (!ifs.is_open())
    {
        return 0;
    }
    unsigned current = ifs.tellg();
    ifs.seekg(0,std::ios::end);
    size = ifs.tellg();
    ifs.seekg(current,std::ios::beg);
    ifs.clear();
    return size;
}
int* readFromBinFile(std::ifstream& ifs, unsigned& size)
{
    ifs.read()
}

int* readFromBinFile(const char* fileName, unsigned size)
{
    std::ofstream ofs(fileName, std::ios::binary);

    if (!ofs.is_open())
    {
        return;
    }
    writeInBinFile(ofs, size);
}


int main()
{
    
}