
#include <iostream>
#include <fstream>
struct product {
	int barcode=0;
	char address[50] = "Unknown";
	unsigned int quantity = 0;
	double price = 0.0;
	product() = default;
	product(int barcode,const char* address,int quantity,double price)
	{
		this->barcode = barcode;
		std::strcpy(this->address, address);
		this->quantity = quantity;
		this->price = price;
	}
	void readproduct(std::ifstream ifs);
};
struct shop {
	char name[30]= "Unknown;";
	char address[50]="Unknown;";
	product products[100];
	int currentProducts = 0;
	double money=0.0;
	shop() = default;
	shop(const char* name, const char* address, double money)
	{
		std::strcpy(this->name, name);
		std::strcpy(this->address, address);
		this->money = money;
	}
	void loadProduct(product& pr);
};
void shop::loadProduct(product& pr)
{
	if (currentProducts < 100)
	{
		this->products[currentProducts] = pr;
	}
	else {
		std::cout << "No Space!"<<std::endl;
	}

		
}

int main()
{
   
}
