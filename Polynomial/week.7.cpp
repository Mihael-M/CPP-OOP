// week.7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Polynomial.h"

int main()
{
    int coeffs1[] = { 1, 2, 3 }; // Представя полинома 1 + 2x + 3x^2
    int coeffs2[] = { 4, 5, 6, 7 }; // 4 + 5x + 6x^2 + 7x^3

    Polynomial f(2, coeffs1);
    Polynomial h(3, coeffs2);

     
    std::cout << "f: " << f << std::endl;
    std::cout << "h: " << h << std::endl;

    Polynomial P = f + h;
    std::cout << "p: " << P << std::endl;
    Polynomial K = h * 3;

    f -= K;

    P *= 4;

    h[2] = 10; // h(x) = 4 + 5x + 10x^2 + 7x^3

    int x = 2;
    std::cout << "Пресмятане на стойност при x=" << x << ": " << f(x) << std::endl;

    std::cout << "Сравнение за равенство: " << (f == h) << std::endl;
    std::cout << "Сравнение за неравенство: " << (f != h) << std::endl;


    std::cout << "Комутативност: " << (f * 3 == 3 * f) << std::endl;
    
}
