#include <iostream>
#include "Factory.h"
int main(int argc, const char * argv[]) {
    std::ifstream ifs("func.dat",std::ios::binary);
        PartialFunction* func = factory(ifs);
        try{
            std::cout<<func->operator()(7)<<std::endl;
        }
        catch(const std::exception& e){
            std::cout<<e.what()<<std::endl;
        }
    return 0;
}
