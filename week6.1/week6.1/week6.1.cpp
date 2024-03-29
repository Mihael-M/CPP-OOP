
#include <iostream>
#include "ShoppingCart.h"

int main()
{
    Product pr1("Mishaka", 14.50, 2);
    Product pr2("Marty", 4.50, 3);
    
    Product pr4("Alex", 56.54, 5);

    Product products[] = { pr1,pr2 };
    ShoppingCart list(products, 10, 2);
    list.addProduct(pr4);
    list.sortByPrice();
    list.printProducts();
    std::ofstream ofs("Shopping.txt", std::ios::app);
    list.safeProducts(ofs);
    std::cout << list.allPrice();
    std::cout << std::endl;
    list.removeProduct("Alex");
    std::cout << std::endl;
    list.printProducts();
}

