#pragma once
#include <iostream>
#include <fstream>


class Product {
private:
	char* name = nullptr;
	double price = 0;
	unsigned quantity = 0;
	void copy(const Product& other);
	void free();
public:
	Product() =default;
	Product(const char* name, double price, unsigned quantity);
	Product(const Product& other);
	~Product();
	Product& operator= (const Product& other);


	const char* getName() const;
	double getPrice() const;
	unsigned getQuantity() const;

	void setName(const char* name);
	void setPrice(double price);
	void setQuantity(unsigned quantity);
	void safeProduct(std::ofstream& ofs);


	void printProduct() const;

	

};
