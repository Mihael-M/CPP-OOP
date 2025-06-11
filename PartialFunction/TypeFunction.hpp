#include "PartialFunction.hpp"
#include "Pair.h"
#pragma once

template<class T>
class TypeFunction : public PartialFunction<T>{
protected:
    PartialFunction<T>** functions;
    size_t functionsCount;
    size_t capacity;
    
    void copy(const TypeFunction<T>& other);
    void free();
    void move(TypeFunction<T>&& other);
    void resize(size_t newCap);
    
public:
    TypeFunction();
    TypeFunction(PartialFunction<T>** funcs, size_t size);
    virtual bool isDefined(int32_t point) const override;
    virtual ~TypeFunction();
    TypeFunction(const TypeFunction<T>& other);
    TypeFunction(TypeFunction<T>&& other);
    TypeFunction<T>& operator=(const TypeFunction<T>& other);
    TypeFunction<T>& operator=(TypeFunction<T>&& other);
    void add(PartialFunction<T>* func);
    
};

template<class T>
TypeFunction<T>::TypeFunction(){
    this->capacity = 8;
    this->functions = new PartialFunction<T>*[this->capacity];
    this->functionsCount = 0;
}

template<class T>
TypeFunction<T>::TypeFunction(PartialFunction<T>** funcs,size_t size){
    this->functions = new PartialFunction<T>*[size];
    for(int i = 0;i<size;i++)
        this->functions[i] = funcs[i];
    this->functionsCount = size;
}

template<class T>
void TypeFunction<T>::copy(const TypeFunction<T>& other){
    this->functions = new PartialFunction<T>*[other.functionsCount];
    for(int i = 0;i<other.functionsCount;i++){
        this->functions[i] = other.functions[i]->clone();
    }
    this->functionsCount = other.functionsCount;
}

template<class T>
void TypeFunction<T>::free(){
    for(int i = 0;i<functionsCount;i++)
        delete functions[i];
    delete[]functions;
}


template<class T>
TypeFunction<T>& TypeFunction<T>::operator=(TypeFunction<T>&& other){
    if(this!=&other){
        free();
        move(std::move(other));
    }
    return *this;
}

template<class T>
TypeFunction<T>& TypeFunction<T>::operator=(const TypeFunction<T>& other){
    if(this!=&other){
        free();
        copy(other);
    }
    return *this;
}

template<class T>
TypeFunction<T>::TypeFunction(TypeFunction<T>&& other){
    move(std::move(other));
}

template<class T>
TypeFunction<T>::TypeFunction(const TypeFunction<T>& other){
    copy(other);
}

template<class T>
void TypeFunction<T>::move(TypeFunction<T>&& other){
    this->functions = other.functions;
    other.functions = nullptr;
    this->functionsCount = other.functionsCount;
    other.functionsCount = 0;
}



template<class T>
TypeFunction<T>::~TypeFunction(){
    free();
}


template<class T>
bool TypeFunction<T>::isDefined(int32_t point) const{
    for(int i = 0;i<functionsCount;i++){
        if(!functions[i]->isDefined(point)){
            return false;
        }
    }
    return true;
}

template<class T>
void TypeFunction<T>::resize(size_t newCap){
    PartialFunction<T>** tempArr = new PartialFunction<T>*[newCap];
    for(int i = 0;i<functionsCount;i++)
        tempArr[i] = this->functions[i]->clone();
    
    for (int i = 0; i < functionsCount; i++) {
        delete this->functions[i];
    }
    delete[] this->functions;

    this->functions = tempArr;
    this->capacity = newCap;
}

template<class T>
void TypeFunction<T>::add(PartialFunction<T>* function){
    if(functionsCount == capacity)
        resize(capacity * 2);
    functions[functionsCount] = function;
    functionsCount++;
}
