#include "Vector.hpp"

int main(int argc, const char * argv[]) {
    
    
    Vector<int> misho;
    misho.pushBack(2);
    misho.pushBack(1);
    misho.pushBack(6);
    misho.pushBack(2);
    
    
    misho.insert(1, 12);
    misho.print();
    
}
