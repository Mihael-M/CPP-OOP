#pragma once
#include <iostream>

class MyString {
private:
	char* data;
	size_t size;
	size_t capacity;

	void copy(const MyString& other);
	void free();
	explicit MyString(size_t stringSize);
	void resize(unsigned newCapacity);

public:

	MyString();
	MyString(const char* data);
	MyString(const MyString& other);
	MyString& operator=(const MyString& other);
	~MyString();
	size_t getSize();
	size_t getCapacity();
	
	const char* c_str()const;
	
	//operators:
	char& operator[](size_t index) const;
	char operator[](size_t index);

	MyString& operator+=(const MyString& other);
	friend std::istream& operator>>(std::istream& is, MyString& str);
	friend MyString operator+(const MyString& lhs, const MyString& rhs);
};
std::ostream& operator<<(std::ostream& os, const MyString& str);
bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
