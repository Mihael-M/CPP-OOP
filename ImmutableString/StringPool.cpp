#include "StringPool.h"
#pragma warning (disable : 4996)
int StringPool::findString(const char* str)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(str, stringRecords[i].data) == 0)
		{
			return i;
		}
	}
	return -1;
}

unsigned StringPool::allocatedNewString(const char* str)
{
	if (capacity == size)
		resize(capacity * 2);
	size_t firstFreeIndex = size++;
	stringRecords[firstFreeIndex].data = new char[strlen(str) + 1];
	strcpy(stringRecords[firstFreeIndex].data, str);
	stringRecords[firstFreeIndex].refCount = 0;
	return firstFreeIndex;
}

void StringPool::resize(unsigned newCap)
{
	StringRecord* newRecords = new StringRecord[newCap];
	for (size_t i = 0; i < newCap; i++)
	{
		newRecords[i] = stringRecords[i];
	}
	delete[] stringRecords;
	stringRecords = newRecords;

}

void StringPool::removeString(unsigned index)
{
	std::swap(stringRecords[index], stringRecords[size - 1]);
	delete[] stringRecords[size - 1].data;
	
}

StringPool::StringPool()
{
	capacity = 8;
	size = 0;
	stringRecords = new StringRecord[capacity];

}

const char* StringPool::getAllocatedString(const char* str)
{
	int index = findString(str);
	if (index != -1) 
	{
		stringRecords[index].refCount++;

		
		std::cout << "String found in cache, ref count: " << stringRecords[index].refCount << std::endl;
		

		return stringRecords[index].data;
	}
	else 
	{
		std::cout << "String NOT found in cache. Allocating.." << std::endl;
		

		unsigned index = allocatedNewString(str);
		stringRecords[index].refCount++;
		return stringRecords[index].data;
	}
}

void StringPool::releaseString(const char* str)
{
	int index = findString(str);
	stringRecords[index].refCount--;
	if (stringRecords[index].refCount == 0)
	{
		std::cout << "Removing record: " << stringRecords[index].data << " (No more refs)" << std::endl;
		removeString(index);
	}
}
