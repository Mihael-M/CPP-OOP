#pragma once
#include<iostream>
class StringPool {
private:
	struct StringRecord {
		char* data = nullptr;
		size_t refCount = 0;

	};
	StringRecord* stringRecords;
	size_t size;
	size_t capacity;

	int findString(const char* str);
	unsigned allocatedNewString(const char* str);
	void resize(unsigned newCap);
	void removeString(unsigned index);

public:

	StringPool();
	const char* getAllocatedString(const char* str);
	void releaseString(const char* str);

};