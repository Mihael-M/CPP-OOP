#include "NVector.h"

int main()
{
    NVector v(4);
    std::cin >> v;

    NVector v2(4);
    std::cin >> v2;

    NVector result = v + v2;

    std::cout << result << std::endl;

    NVector v(3);
    v[2] = 10;
    NVector v2 = 3 * v;
    std::cout << v2;

}