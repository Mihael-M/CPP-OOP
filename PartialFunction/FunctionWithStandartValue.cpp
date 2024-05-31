#include <stdio.h>
#include "FunctionWithStandartValue.h"

FunctionWithStandartValue::FunctionWithStandartValue(const int32_t* points,size_t size,const int32_t* results) : Function(points, size){
    this->results = new int32_t[size];
    for(int i = 0;i<size;i++){
        this->results[i] = results[i];
    }
}

FunctionWithStandartValue::FunctionWithStandartValue(const FunctionWithStandartValue& other) : Function(other){
    copy(other);
}

FunctionWithStandartValue::FunctionWithStandartValue(FunctionWithStandartValue&& other) : Function(other){
    move(std::move(other));
}

FunctionWithStandartValue& FunctionWithStandartValue::operator=(const FunctionWithStandartValue& other){
    if(this!=&other){
        Function::operator=(other);
        free();
        copy(other);
    }
    return *this;
}


FunctionWithStandartValue& FunctionWithStandartValue::operator=(FunctionWithStandartValue&& other){
    if(this!=&other){
        Function::operator=(std::move(other));
        free();
        move(std::move(other));
    }
    return *this;
}


FunctionWithStandartValue::~FunctionWithStandartValue(){
    free();
}

void FunctionWithStandartValue::copy(const FunctionWithStandartValue& other){
    this->results = new int32_t[other.size];
    for(int i = 0;i<other.size;i++){
        this->results[i] = other.results[i];
    }
}


void FunctionWithStandartValue::move(FunctionWithStandartValue&& other){
    this->results = other.results;
    other.results = nullptr;
}


void FunctionWithStandartValue::free(){
    delete[]results;
    results = nullptr;
}

bool FunctionWithStandartValue::isPointExcluded(int32_t point) const{
    for(int i = 0;i<size;i++){
        if(points[i] == point)
            return false;
    }
    return true;
}

int32_t FunctionWithStandartValue::operator()(int32_t point) const{
    
    for(int i = 0;i<size;i++){
        if(points[i] == point){
            return results[i];
        }
    }
    throw std::invalid_argument("The point is excluded!");
}
