#include "ShoppingCart.h"

void ShoppingCart::copy(const ShoppingCart& other)
{

	this->productsCount = other.productsCount;
	this->currCount = other.currCount;
	this->products = new Product[other.productsCount];
	for (int i = 0; i < other.currCount; i++) {
		this->products[i] = other.products[i];
	}
	
}

void ShoppingCart::free() {
	delete[]products;
	products = nullptr;

	this->productsCount = 0;
	this->currCount = 0;
}

void ShoppingCart::setProducts(const Product* products, size_t productsCount,size_t currCount) {

	if (this->products == products || products == nullptr) {
		return;
	}

	delete[] this->products;

	this->products = new Product[productsCount];
	for (size_t i = 0; i < currCount; i++) {
		this->products[i] = products[i];
	}
	this->productsCount = productsCount;
	this->currCount = currCount;
}

ShoppingCart::ShoppingCart(const Product* products, size_t productsCount, size_t currCount) {

	setProducts(products, productsCount, currCount);
}

ShoppingCart::ShoppingCart(const ShoppingCart& other)
{
	copy(other);
}

ShoppingCart::~ShoppingCart()
{
	free();
}

ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other)
{
	if (this != &other) {
		free();
		copy(other);
	}

	return *this;
}


bool ShoppingCart::containsProduct(const Product& product) const
{
	for (size_t i = 0; i < currCount; i++) {
		if (products[i].getName() == product.getName()) {
			return true;
		}
	}
	return false;
}

void ShoppingCart::addProduct(const Product& product) {

	if (currCount <= productsCount && !containsProduct(product)) {

		products[currCount] = product;
		currCount++;
	}
}

void ShoppingCart::removeProduct(const char* productName) {

	for (size_t i = 0; i < currCount; i++) {
		if (std::strcmp(products[i].getName(), productName) == 0) {
			for (size_t j = i; j < currCount - 1; j++) {
				products[j] = products[j + 1];
			}
			currCount--;
			std::cout << "The product was removed!" << std::endl;
			return;
		}
	}

	

}

int ShoppingCart::getCurrCount() const {
	return this->currCount;
}

bool ShoppingCart::isEmpty() const
{
	return currCount == 0;
}

double ShoppingCart::allPrice() const
{
	double sum = 0;
	for (size_t i = 0; i < currCount; i++)
	{
		sum += products[i].getPrice();
	}
	return sum;
}

void ShoppingCart::sortByName()
{
	for (size_t i = 0; i < currCount; i++)
	{
		for (size_t j = i+1; j <currCount; j++)
		{
			if (strcmp(products[i].getName(), products[j].getName())>0)
			{
				std::swap(products[i], products[j]);
			}
		}
	}

}

void ShoppingCart::sortByPrice()
{
	for (size_t i = 0; i < currCount; i++)
	{
		for (size_t j = i + 1; j < currCount; j++)
		{
			if (products[i].getPrice() > products[j].getPrice())
			{
				std::swap(products[i], products[j]);
			}
		}
	}

}

void ShoppingCart::sortByQuantity()
{
	for (size_t i = 0; i < currCount; i++)
	{
		for (size_t j = i + 1; j < currCount; j++)
		{
			if (products[i].getQuantity() > products[j].getQuantity())
			{
				std::swap(products[i], products[j]);
			}
		}
	}

}

void ShoppingCart::safeProducts(std::ofstream& ofs)
{
	for (size_t i = 0; i < currCount; i++)
	{
		products[i].safeProduct(ofs);
	}
}

void ShoppingCart::printProducts() const {
	for (size_t i = 0; i < currCount; i++) {
		products[i].printProduct();
	}
}











