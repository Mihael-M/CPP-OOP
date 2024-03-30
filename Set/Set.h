#pragma once
#include <iostream>
constexpr int MAX = 1000 - 1;
class Set {
private:
	char* set = nullptr;
	unsigned capacity = 0;
	void setSet(const char* set);
	void setCapacity(unsigned capacity);
public:
	Set() = default;
	Set(const char* set, unsigned capacity);
	Set(const Set& other);
	Set& operator=(const Set& other);
	~Set();
	char* getSet()const;
	unsigned getCapacity();
	void free();
	void copy(const Set& other);
	void addNum(unsigned num);
	bool contains(unsigned num)const ;
};


