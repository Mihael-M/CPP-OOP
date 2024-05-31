#include "FunctionCrafter.h"

PartialFunction<Pair>* crafter(std::ifstream& ifs){
    
    int16_t N;
    int16_t T;
    
    ifs.read((char*) &N,sizeof(int16_t));
    ifs.read((char*) &T,sizeof(int16_t));
    
    if(T == 0){
        int32_t* points = new int32_t[N];
        ifs.read((char*)points, sizeof(int32_t) * N);
        int32_t* values = new int32_t[N];
        ifs.read((char*)values,sizeof(int32_t) * N);
        FunctionWithStandartValue func(points, N, values);
        PartialFunction<Pair>* toReturn = new PartialFunctionByCriteria<FunctionWithStandartValue, Pair>(func);
        delete[]points;
        delete[]values;
        return toReturn;
    }
    else if(T == 1){
        int32_t* points = new int32_t[N];
        ifs.read((char*)points,sizeof(int32_t) * N);
        FunctionWithExcludedValues func(points, N);
        PartialFunction<Pair>* toReturn = new PartialFunctionByCriteria<FunctionWithExcludedValues, Pair>(func);
        delete[]points;
        return toReturn;
    }
    else if(T == 2){
        int32_t* points = new int32_t[N];
        ifs.read((char*)points,sizeof(int32_t) * N);
        FunctionWithConstantValues func(points, N);
        PartialFunction<Pair>* toReturn = new PartialFunctionByCriteria<FunctionWithConstantValues, Pair>(func);
        delete[]points;
        return toReturn;
    }
    else if(T == 3){
        TypeFunction<Pair>* toReturn = new MaximumFunction<Pair>();
        for(int i = 0;i<N;i++){
            char fileName[MAX_FILE_NAME_SIZE];
            ifs.getline(fileName, 1024,'\0');
            std::ifstream subIfs(fileName, std::ios::binary);
            if (!subIfs) {
                std::cout << "Unable to open stream for file: " << fileName << std::endl;
                continue;
            }
            PartialFunction<Pair>* toAdd = crafter(subIfs);
            if (toAdd != nullptr) {
                toReturn->add(toAdd);
            }
            subIfs.close();
        }
        return toReturn;
        
    }
    else if(T == 4){
        TypeFunction<Pair>* toReturn  = new MinimumFunction<Pair>();
        for(int i = 0;i<N;i++){
            char fileName[MAX_FILE_NAME_SIZE];
            ifs.getline(fileName, 1024,'\0');
            std::ifstream subIfs(fileName, std::ios::binary);
            if (!subIfs) {
                std::cout << "Unable to open stream for file: " << fileName << std::endl;
                continue;
            }
            PartialFunction<Pair>* toAdd = crafter(subIfs);
            if (toAdd != nullptr) {
                toReturn->add(toAdd);
            }
            subIfs.close();
        }
        return toReturn;
    }
    else
        throw std::logic_error("Unable to access the content of the binary file!");
}
