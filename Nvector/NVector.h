#pragma once
#include <iostream>

class NVector {
	int* data;
	size_t size;

	void copy(const NVector& other);
	void free();

public:
	NVector(size_t size);
	NVector(const NVector& other);
	NVector& operator=(const NVector& other);
	~NVector();

	//operators:

	NVector& operator+=(const NVector& other);
	NVector& operator-=(const NVector& other);
	NVector& operator*=(const NVector& other);

	NVector& operator*=(size_t num);

	size_t operator~() const;

	int& operator[](size_t index);
	int operator[](size_t index)const;

	friend std::istream& operator>>(std::istream& is,NVector& vector);
};
NVector operator+(const NVector& lhs, const NVector& rhs);
NVector operator-(const NVector& lhs, const NVector& rhs);
NVector operator*(const NVector& lhs, const NVector& rhs);
NVector operator*(const NVector& lhs, size_t num);

bool operator||(const NVector& lhs, const NVector& rhs);
bool operator|=(const NVector& lhs, const NVector& rhs);

std::ostream& operator<<(std::ostream& os, const NVector& vector);

bool operator==(const NVector& lhs, const NVector& rhs);
bool operator!=(const NVector& lhs, const NVector& rhs);

