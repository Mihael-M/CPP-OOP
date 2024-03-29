#pragma once
#include "Product.h"



class ShoppingCart {

private:
	Product* products = nullptr;
	size_t productsCount = 0;
	size_t currCount = 0;

	void copy(const ShoppingCart& other);
	void free();

public:

	ShoppingCart() = default;
	ShoppingCart(const Product* products, size_t productsCount, size_t currProducts);
	ShoppingCart(const ShoppingCart& other);
	~ShoppingCart();
	ShoppingCart& operator=(const ShoppingCart& other);


	void setProducts(const Product* products, size_t productsCount,size_t currCount);


	bool containsProduct(const Product& product) const;

	void addProduct(const Product& product);
	void removeProduct(const char* productName);
    
	int getCurrCount() const;
	bool isEmpty() const;

	double allPrice()const;
	void sortByName();
	void sortByPrice();
	void sortByQuantity();
	void safeProducts(std::ofstream& ofs);

	void printProducts() const;

};
