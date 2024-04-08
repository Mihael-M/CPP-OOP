#include "Polynomial.h"
#include <iostream>

void Polynomial::copy(const Polynomial& other)
{
	this->power = other.power;
	this->coeffs = new int[other.power+1];
	for (int i = 0; i < other.power+1; i++) {
		this->coeffs[i] = other.coeffs[i];
	}

}

void Polynomial::destroy()
{
	delete[] this->coeffs;

	this->power = 0;
}

Polynomial::Polynomial(int power, const int* coeffs)
{
	setPower(power);
	setCoeffs(coeffs);

}

Polynomial::Polynomial(const Polynomial& other)
{
	copy(other);
}

Polynomial& Polynomial::operator=(const Polynomial& other)
{
	if (this != &other) {
		destroy();
		copy(other);
	}
	return *this;
}

Polynomial::~Polynomial()
{
	destroy();


}

int Polynomial::getPower() const
{
	return power;
}

void Polynomial::setPower(int power)
{
	this->power = power;
}

int* Polynomial::getCoeffs() const
{
	return coeffs;
}

void Polynomial::setCoeffs(const int* coeffs)
{
	delete[] this->coeffs;

	this->coeffs = new int[power + 1];
	for (int i = 0; i < power + 1; i++) {
		this->coeffs[i] = coeffs[i];
	}
}


Polynomial& Polynomial::operator+=(const Polynomial& other)
{
	if (power >= other.power)
	{
		for (int i = 0; i < other.power+1; i++) {
			coeffs[i] += other.coeffs[i];
		}
	}
	else {
		
		int* newcoeff = new int[other.power+1];
		for (int i = 0; i < power+1; i++) {
			newcoeff[i] = coeffs[i] + other.coeffs[i];
		}
		for (size_t i = power; i < other.power+1; i++)
		{
			newcoeff[i] = other.coeffs[i];
		}
		delete[] coeffs;
		coeffs = newcoeff;
		power = other.power;
	}

	return *this;
}
Polynomial& Polynomial::operator-=(const Polynomial& other)
{
	if (power >= other.power)
	{
		for (int i = 0; i < other.power + 1; i++) {
			coeffs[i] -= other.coeffs[i];
		}
	}
	else {

		int* newcoeff = new int[other.power + 1];
		for (int i = 0; i < power + 1; i++) {
			newcoeff[i] = coeffs[i] - other.coeffs[i];
		}
		for (size_t i = power; i < other.power + 1; i++)
		{
			newcoeff[i] = other.coeffs[i];
		}
		delete[] coeffs;
		coeffs = newcoeff;
		power = other.power;
	}

	return *this;
}
Polynomial& Polynomial::operator*=(int number)
{
	
		for (int i = 0; i < power + 1; i++) {
			coeffs[i] *= number;
		}
	
	return *this;
}
int Polynomial::operator()(int toApply) const {
	int res = 0;
	int curr = 1;
	for (int i = 0; i < power + 1; i++) {
		res += coeffs[i] * curr;
		curr *= toApply;
	}

	return res;
}
const int& Polynomial::operator[](size_t num) const
{
	return coeffs[num];
}
int& Polynomial::operator[](size_t num)
{
	 return coeffs[num];
}
const bool operator==(const Polynomial& first,const Polynomial& second) 
{
	if (first.power == second.power)
	{
		for (size_t i = 0; i < first.power+1; i++)
		{
			if (first.coeffs[i] != second.coeffs[i])
				return false;
		}
		return true;

	}
	return false;
}
const bool operator!=(const Polynomial& first, const Polynomial& second)
{
	return !operator==(first,second);
}
Polynomial operator-(const Polynomial& first,const Polynomial& second)
{
	Polynomial toReturn(first);
	toReturn -= second;

	return toReturn;
}
Polynomial operator+(Polynomial& first,Polynomial& other)
{
	if (first.power >= other.power)
	{
		for (int i = 0; i < other.power + 1; i++) {
			first.coeffs[i] += other.coeffs[i];
		}
	}
	else {

		int* newcoeff = new int[other.power + 1];
		for (int i = 0; i < first.power + 1; i++) {
			newcoeff[i] = first.coeffs[i] + other.coeffs[i];
		}
		for (size_t i = first.power + 1; i < other.power + 1; i++)
		{
			newcoeff[i] = other.coeffs[i];
		}
		delete[] first.coeffs;
		first.coeffs = newcoeff;
		first.power = other.power;
	}

	return first;
}

Polynomial operator*(Polynomial& first,int num)
{
	for (int i = 0; i < first.power + 1; i++) {
		first.coeffs[i] *= num;
	}

	return first;
}

Polynomial operator*(int num, Polynomial& first)
{
	for (int i = 0; i < first.power + 1; i++) {
		first.coeffs[i] *= num;
	}

	return first;
}

std::istream& operator>>(std::istream& is,Polynomial& poly)
{
	const int SIZE_BUFF = 30;
	int buff[SIZE_BUFF];
	int counter = 0;
	for (size_t i = 0; i < SIZE_BUFF; i++)
	{
		is >> buff[i];
		counter++;
	}
	poly.setCoeffs(buff);
	poly.setPower(counter);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& poly)
{
	for (size_t i = poly.getPower(); i > 0; i--)
	{
		os << poly.getCoeffs()[i] << "x" << "^" << i << " + ";
	}
	return os << poly.getCoeffs()[0];
}
