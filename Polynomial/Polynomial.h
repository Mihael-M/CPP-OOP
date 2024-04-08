#pragma once
#include <iostream>
class Polynomial {
private:
	int power = 0;
	int* coeffs = nullptr;

	void copy(const Polynomial& other);
	void destroy();


public:
	Polynomial() = default;
	Polynomial(int power, const int* coeffs);
	Polynomial(const Polynomial& other);
	Polynomial& operator=(const Polynomial& other);
	~Polynomial();
	int getPower() const;
	void setPower(int power);
	int* getCoeffs() const;
	void setCoeffs(const int* coeffs);

	Polynomial& operator+=(const Polynomial& other);
	Polynomial& operator-=(const Polynomial& other);
	Polynomial& operator*=(int number);
	int operator()(int toApply) const;
	const int& operator[]( size_t num)const;
	int& operator[](size_t num);
	friend const bool operator==(const Polynomial& first,const Polynomial& second);
	friend const bool operator!=(const Polynomial& first, const Polynomial& second);
	friend Polynomial operator-(Polynomial& first, Polynomial& second);
	friend Polynomial operator+(Polynomial& first,Polynomial& second);	
	friend Polynomial operator*(Polynomial& first,int num);
	friend Polynomial operator*( int num, Polynomial& first);
	friend std::istream& operator>>(std::istream& is, const Polynomial& poly);
};
std::ostream& operator<<(std::ostream& os, const Polynomial& poly);
	
