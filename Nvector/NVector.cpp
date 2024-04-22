#include "NVector.h"

void NVector::copy(const NVector& other)
{
	this->size = other.size;
	this->data = new int[this->size];
	for (size_t i = 0; i < other.size; i++)
	{
		this->data[i] = other.data[i];
	}
	
}

void NVector::free()
{
	delete[] data;
	size = 0;
}

NVector::NVector(size_t size) : size(size)
{
	this->data = new int[size];

	for (size_t i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}

NVector::NVector(const NVector& other)
{
	copy(other);
}

NVector& NVector::operator=(const NVector& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

NVector::~NVector()
{
	free();
}

NVector& NVector::operator+=(const NVector& other)
{
	if (this->size != other.size)
		throw "The vectors should have the same size!";

	
	for (size_t i = 0; i < other.size; i++)
	{
		this->data[i] += other.data[i];

	}
	return *this;
}

NVector& NVector::operator-=(const NVector& other)
{
	if (this->size != other.size)
		throw "The vectors should have the same size!";

	
	for (size_t i = 0; i < other.size; i++)
	{
		this->data[i] -= other.data[i];

	}
	return *this;
}

NVector& NVector::operator*=(const NVector& other)
{
	if (this->size != other.size)
		throw "The vectors should have the same size!";


	for (size_t i = 0; i < other.size; i++)
	{
		this->data[i] *= other.data[i];

	}
	return *this;
}

NVector& NVector::operator*=(size_t num)
{
	for (size_t i = 0; i < size; i++)
	{
		this->data[i] *= num;

	}
	return *this;
}

size_t NVector::operator~() const
{
	return size;
}

int& NVector::operator[](size_t index) 
{
	if (index >= size)
		throw "Invalid index";
	return this->data[index];
}

int NVector::operator[](size_t index)const 
{
	if (index >= size)
		throw "Invalid index";
	return this->data[index];
}

std::istream& operator>>(std::istream& is, NVector& vector)
{
	for (size_t i = 0; i < vector.size; i++)
	{
		is >> vector.data[i];
	}
	return is;
}

NVector operator+(const NVector& lhs, const NVector& rhs)
{	
	NVector result(lhs);
	result += rhs;
	return result;
}

NVector operator-(const NVector& lhs, const NVector& rhs)
{
	NVector result(lhs);
	result -= rhs;
	return result;
}

NVector operator*(const NVector& lhs, const NVector& rhs)
{
	NVector result(lhs);
	result *= rhs;
	return result;
}

NVector operator*(const NVector& lhs, size_t num)
{
	NVector result(lhs);
	result *= num;
	return result;
}

bool operator||(const NVector& lhs, const NVector& rhs)
{
	if (~lhs != ~rhs) {
		throw "The vectors should have the same size!";
	}
	double ratio = 0.0;
	bool ratioSet = false;
	for (size_t i = 0; i < ~lhs; i++)
	{
		if (lhs[i] == 0 && rhs[i] == 0) {
			continue;
		}
		if (lhs[i] == 0 || rhs[i] == 0)
		{
			return false;
		}
		double currentRatio = lhs[i] / rhs[i];
		if (!ratioSet)
		{
			ratio = currentRatio;
			ratioSet = true;
		}
		else if (std::abs(ratio - currentRatio) > 1e-6)
		{
			return false;
		}
	}
	return true;

}

bool operator|=(const NVector& lhs, const NVector& rhs)
{
	int sum = 0;
	
	for (size_t i = 0; i < ~lhs; i++)
	{
		int product = rhs[i] * lhs[i];
		sum += product;
	}
	return sum == 0;

}

std::ostream& operator<<(std::ostream& os, const NVector& vector)
{
	os << "[";
	for (size_t i = 0; i < ~vector-1; i++)
	{
		os << vector[i] << ",";
	}
	os << vector[~vector-1] << "]";
	return os;
}

bool operator==(const NVector& lhs, const NVector& rhs)
{
	for (size_t i = 0; i < ~lhs; i++)
	{
		if (lhs[i] != rhs[i])
			return false;
	}
	return true;
}

bool operator!=(const NVector& lhs, const NVector& rhs)
{
	return !(lhs == rhs);
}

