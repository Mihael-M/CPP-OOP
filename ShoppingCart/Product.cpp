#include "Product.h"


void Product::copy(const Product& other)
{
	this->name = new char[std::strlen(other.name) + 1];
	strcpy_s(this->name,strlen(other.name)+1, other.name);
	
	this->price = other.price;
	this->quantity = other.quantity;
}


void Product::free()
{
	delete[] name;
	name = nullptr;
	price = 0;
	quantity = 0;
}

const char* Product::getName() const {
	return this->name;
}

double Product::getPrice() const {
	return this->price;
}

unsigned Product::getQuantity() const{
	return this->quantity;
}


void Product::setName(const char* name) {
	
	if (name == nullptr || this->name==name) {
		return;
	}

	delete[] this->name;

	this->name = new char[std::strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1,name);

}

void Product::setPrice(double price) {
	if (price < 0) {
		return;
	}

	this->price = price;
}

void Product::setQuantity(unsigned quantity) {
	if (quantity < 0)
		return;

	this->quantity = quantity;
}

void Product::safeProduct(std::ofstream& ofs)
{
	if (!ofs.is_open())
		return;
	ofs << name << std::endl;
	ofs << price << std::endl;
	ofs << quantity << std::endl;
}

void Product::printProduct() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Quantity: " << quantity << std::endl;
}

Product::Product(const char* name, double price, unsigned quantity)
{

	setName(name);
	setPrice(price);
	setQuantity(quantity);

}

Product::Product(const Product& other) {
	copy(other);
}

Product::~Product()
{
	free();
}

Product& Product::operator=(const Product& other)
{
	if (this != &other) {
		free();
		copy(other);
	}

	return *this;
}








