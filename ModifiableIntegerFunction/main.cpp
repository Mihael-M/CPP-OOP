#include <iostream>
#include "ModifiableIntegerFunction.h"




int16_t dummy(int16_t x){
    
    
    
    return x + 2;
    
}


int16_t square(int16_t x) {
    return x * x;
}

int16_t cube(int16_t x) {
    return x * x * x;
}


int16_t surjectiveFunction(int16_t x) {
    // Just add 1 to the input value to ensure non-zero output
    return 0;
}

int16_t absoluteValueFunction(int16_t x) {
    // Return the absolute value of the input
    return abs(x);
}

int16_t polynomialFunction(int16_t x) {
    // Example: f(x) = x^2 + x + 1
    return x * x + x + 1;
}

int16_t exponentialFunction(int16_t x) {
    // Example: f(x) = 2^x for x in [-32768, 32767]
    if (x >= 0) {
        // For non-negative x, calculate 2^x
        return static_cast<int16_t>(pow(2, x));
    } else {
        // For negative x, return the minimum value of int16_t
        return std::numeric_limits<int16_t>::min();
    }
}

int16_t linearFunction(int16_t x) {
    // Scale the input x to fit within the range of int16_t
    return static_cast<int16_t>(x / 128); // Adjust the scaling factor as needed
}
int16_t cyclicFunction(int16_t x) {
    // Example: Return the input value itself, wrapping around at the limits of int16_t
    return x % (std::numeric_limits<int16_t>::max() + 1);
}


int main(int argc, const char * argv[]) {
    
    
    ModifiableIntegerFunction func(dummy);
    ModifiableIntegerFunction func2(square);
    
    
    bool flag = func.isSurjective();
    
    for(int i = 0;i<ModifiableIntegerFunction::SIZE;i++){
        if(func.isPointExcluded[i]){
            //std::cout<<i<<std::endl;
        }
        std::cout<<func.isPointExcluded[i]<<" ";
}
    
    //std::cout<<flag<<std::endl;
    
    //std::cout<<flag<<std::endl;
    
    //ModifiableIntegerFunction func3 = func - func2;
    
    //std::cout<<func3(3)<<std::endl;
    
    
    //ModifiableIntegerFunction func2(cube);
    

    
    //std::cout<<func(-3)<<std::endl;
    
    
    
    
}
