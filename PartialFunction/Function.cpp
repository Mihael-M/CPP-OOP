#include <stdio.h>
#include "Function.h"


Function::Function(const int32_t* arr,size_t size){
    this->points = new int32_t[size];
    for(int i = 0;i<size;i++){
        this->points[i] = arr[i];
    }
    this->size = size;
}

Function::Function(const Function& other){
    copy(other);
}

Function::Function(Function&& other){
    move(std::move(other));
}

Function& Function::operator=(const Function& other){
    if(this!=&other){
        free();
        copy(other);
    }
    return *this;
}

Function& Function::operator=(Function&& other){
    if(this!=&other){
        free();
        move(std::move(other));
    }
    return *this;
}




void Function::move(Function&& other){
    this->points = other.points;
    other.points = nullptr;
    this->size = other.size;
    other.size = 0;
}

void Function::copy(const Function& other){
    this->points = new int32_t[other.size];
    for(int i = 0;i<other.size;i++){
        this->points[i] = other.points[i];
    }
    this->size = other.size;
}

void Function::free(){
    delete[]points;
    points = nullptr;
}

Function::~Function(){
    free();
}
