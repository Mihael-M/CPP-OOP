#pragma once
#include <iostream>
#include "Categories.h"
class BrokenAppliance {
public:
	categories category=telefones;
	double priceFix = 0;
	bool warranty = false;
	BrokenAppliance() = default;
	BrokenAppliance(const categories category, double priceFix, bool warranty)
	{
		
		this->category = category;
		this->priceFix = priceFix;

		this->warranty = warranty;
	}
	double getPriceFix() const
	{
		return this->priceFix;
	}
	void setPriceFix(double priceFix)
	{
		this->priceFix = priceFix;
	}

};
