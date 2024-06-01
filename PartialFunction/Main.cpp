#include "FunctionCrafter.h"
// the task was done with 
// Христо Партенов -> 0MI0700220 and
// Димитър Цонев -> 72087

void runInMode1(int a,int b){
    std::ifstream ifs("func.dat", std::ios::binary);
    PartialFunction<Pair>* function = crafter(ifs);
    for(int i = a;i<b;i++){
        try{
            int value = (*function)(i).getValue();
            std::cout << "f("<<i<<")"<<" = "<<value<<std::endl;
        }
        catch(const std::exception& e){
            continue;
        }
    }
}


void runInMode2(){
    std::ifstream ifs("func.dat", std::ios::binary);
    PartialFunction<Pair>* function = crafter(ifs);
    int32_t point = 0;
    int32_t maxCount = INT32_MAX;
    while(true){
        if(function->isDefined(point)){
            std::cout<<(*function)(point).getValue()<<std::endl;
            point++;
            char buff[1024];
            std::cin >> buff;
            if(std::strcmp(buff, "next")!=0)
                break;
        }
        else{
            point++;
            if(point == maxCount)
                break;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    // Binary file for 0
    //int16_t N = 7;
    //int16_t T = 0;
    
    
    
    //std::ofstream ofs("first.dat",std::ios::binary);
    //ofs.write((const char*) &N, sizeof(int16_t));
    //ofs.write((const char*) &T,sizeof(int16_t));
    
    //int32_t points[] = {0,1,2,3,5,6,7};
    //int32_t values[] = {0,3,3,3,4,4,0};
    
    //ofs.write((const char*) points,sizeof(int32_t) * N);
    
    //ofs.write((const char*) values,sizeof(int32_t) * N);
    
    // Binary file for 1
    //int16_t N = 2;
    //int16_t T = 1;
    //std::ofstream ofs("second.dat",std::ios::binary);
    //ofs.write((const char*)&N,sizeof(int16_t));
    //ofs.write((const char*)&T,sizeof(int16_t));
    //int32_t points[] = {3,5};
    //ofs.write((const char*) &points,sizeof(int32_t) * N);
    
    //std::ifstream ifs("second.dat",std::ios::binary);
    //PartialFunction<Pair>* function = crafter(ifs);
    //std::cout<<function->operator()(7)<<std::endl;
    //std::cout<<function->operator()(2)<<std::endl;
    //std::cout<<function->isDefined(3)<<std::endl;
    //std::cout<<function->isDefined(5)<<std::endl;
    //try{
        //std::cout<<function->operator()(3)<<std::endl;
    //}
    //catch(const std::exception& e){
        //std::cout<<e.what()<<std::endl;
    //}
    
    // Binary File for 2
    //int16_t N = 4;
    //int16_t T = 2;
    //std::ofstream ofs("third.dat",std::ios::binary);
    //ofs.write((const char*)&N,sizeof(int16_t));
    //ofs.write((const char*)&T,sizeof(int16_t));
    //int32_t points[] = {0,5,6,7};
    //ofs.write((const char*) &points,sizeof(int32_t) * N);
    
    //std::ifstream ifs("third.dat",std::ios::binary);
    //PartialFunction<Pair>* function = crafter(ifs);
    //std::cout<<function->operator()(0)<<std::endl;
    //std::cout<<function->operator()(5)<<std::endl;
    //std::cout<<function->operator()(6)<<std::endl;
    //std::cout<<function->operator()(1)<<std::endl;
    
    //std::cout<<function->isDefined(7)<<std::endl;
    //std::cout<<function->isDefined(1)<<std::endl;
    //std::cout<<function->isDefined(43)<<std::endl;
    //try{
        //std::cout<<function->operator()(3)<<std::endl;
    //}
    //catch(const std::exception& e){
        //std::cout<<e.what()<<std::endl;
    //}
    
    
    
    //int16_t N = 3;
    //int16_t T = 3;
    //std::ofstream ofs("func.dat",std::ios::binary);
    //ofs.write((const char*) &N,sizeof(int16_t));
    //ofs.write((const char*) &T,sizeof(int16_t));
    
    //char fileName1[] = {"first.dat"};
    //char fileName2[] = {"second.dat"};
    //char fileName3[] = {"third.dat"};
    
    //ofs.write(fileName1, std::strlen(fileName1) + 1);
    //ofs.write(fileName2, std::strlen(fileName2) + 1);
    //ofs.write(fileName3, std::strlen(fileName3) + 1);
    
    
    //std::ifstream ifs("func.dat",std::ios::binary);
    //PartialFunction<Pair>* function = crafter(ifs);
    //std::cout<<function->operator()(6)<<std::endl;
    //std::cout<<function->operator()(0)<<std::endl;
    //std::cout<<function->operator()(5)<<std::endl;
    //std::cout<<function->operator()(6)<<std::endl;
    //std::cout<<function->operator()(1)<<std::endl;
    
    //try{
        //std::ifstream ifs("TestCaseWith3.dat", std::ios::binary);
        //PartialFunction<Pair>* arr = crafter(ifs);
        //std::cout << arr->operator()(0) << std::endl << arr->operator()(1) << std::endl << arr->operator()(2)<<std::endl;
        //std::cout<<arr->operator()(5)<<std::endl;
    //}
    //catch(const std::exception& e){
        //std::cout<<e.what()<<std::endl;
    //}
    
    
    
    // mode 1
    /*int a;
    int b;
    std::cin >> a;
    std::cin >> b;
    runInMode1(a, b);
    */
    
    // mode 2
    //runInMode2();// the last generation is slow -> expected wait time is 10-15 seconds, the generation of the values is requested by the command "next", everything else will stop the program
    
}
