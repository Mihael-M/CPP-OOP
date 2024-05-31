#include <stdio.h>
#include <stdio.h>
#include "String.h"
#include <iostream>

size_t String::roundPowerOfTwo(size_t v){
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}


String::String(){
    this->allocatedData = 8;
    this->data = new char[allocatedData + 1];
    this->size = 0;
}

size_t String::dataToAllocByStringLen(size_t stringLen){
    return std::max(roundPowerOfTwo(stringLen + 1), (size_t)16u);
}


void String::copy(const String& other){
    this->allocatedData = other.allocatedData;
    this->data = new char[other.allocatedData];
    std::strcpy(this->data, other.data);
    this->size = other.size;
}

void String::free(){
    delete[] data;
    data = nullptr;
    this->size = 0;
    this->allocatedData = 0;
}

String::String(const String& other){
    copy(other);
}

String::String(size_t strLen){
    allocatedData = dataToAllocByStringLen(strLen);
    data = new char[allocatedData];
    size = 0;
    data[0] = '\0';
}

void String::resize(size_t newAllocData){
    char* newData = new char[newAllocData + 1];
    std::strcpy(newData, this->data);
    delete[]this->data;
    this->data = newData;
    allocatedData = newAllocData;
    
}

const char* String::c_str() const{
    return this->data;
}

size_t String::getSize() const{
    return this->size;
}


size_t String::getAllocData() const{
    return allocatedData - 1;
}

String::String(char* data){
    this->size = std::strlen(data);
    this->allocatedData = dataToAllocByStringLen(size);
    this->data = new char[this->allocatedData];
    std::strcpy(this->data, data);
}

void String::move(String&& other){
    this->allocatedData = other.allocatedData;
    other.allocatedData = 0;
    
    this->size = other.size;
    other.size = 0;
    
    this->data = other.data;
    other.data = nullptr;
}

String::String(String&& other){
    move(std::move(other));
}

String& String::operator=(const String& other){
    if(this!=&other){
        free();
        copy(other);
    }
    return *this;
}

String& String::operator=(String&& other){
    if(this!=&other){
        free();
        move(std::move(other));
    }
    return *this;
}

String::~String(){
    free();
}

const char& String::operator[](size_t index) const{
    if(index < 0 || index > size){
        throw std::invalid_argument("Index out of bounds!");
    }
    
    return data[index];
}

char& String::operator[](size_t index){
    if(index < 0 || index > size){
        throw std::invalid_argument("Index out of bounds!");
    }
    
    return data[index];
}

String& String::operator+=(const String& other){
    if(getSize() + other.getSize() + 1 > allocatedData){
        resize(dataToAllocByStringLen(getSize() + other.getSize()));
    }
    
    std::strncat(data, other.data, other.getSize());
    
    size = getSize() + other.getSize();
    
    return *this;
}

String operator+(const String& lhs, const String& rhs){
    
    String res(lhs.getSize() + rhs.getSize());
    res+=lhs;
    res+=rhs;
    
    return res;
}

std::ostream& operator<<(std::ostream& os, String& obj){
    os<<obj.data;
    return os;
}

std::istream& operator>>(std::istream& is, String& obj){
    char buff[1024];
    is>>buff;
    size_t buffLen = std::strlen(buff);
    
    if(buffLen > obj.getAllocData()){
        obj.resize(String::dataToAllocByStringLen(buffLen));
    }
    
    std::strcpy(obj.data,buff);
    obj.size = buffLen;
    
    return is;
}


bool operator==(const String& lhs, const String& rhs){
    return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const String& lhs, const String& rhs){
    return !(lhs==rhs);
}

bool operator<=(const String& lhs, const String& rhs){
    return std::strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const String& lhs, const String& rhs){
    return std::strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator<(const String& lhs, const String& rhs){
    return !(lhs >= rhs);
}

bool operator>(const String& lhs, const String& rhs){
    return !(lhs <= rhs);
}


bool String::contains(const String& str) const {
    
    int countMatches = 0;
    size_t origLen = std::strlen(c_str());
    size_t lenToContain = std::strlen(str.c_str());

    int indexOrig = 0;
    
    for(int i = 0;i<origLen;i++){
        if(data[indexOrig] == str.data[0]){
            for(int j = 0;j<lenToContain;j++){
                if(data[indexOrig]!=str.data[j]){
                    countMatches = 0;
                    break;
                }
                else{
                    indexOrig++;
                    countMatches++;
                    if(countMatches == lenToContain){
                        return true;
                    }
                    if(indexOrig >= origLen){
                        break;
                    }
                }
            }
        }
        else{
            indexOrig++;
            if(indexOrig>=origLen){
                break;
            }
        }
    }
    return false;
}


void String::addSymbol(char s){
    if (size + 1 >= allocatedData) {
           resize(dataToAllocByStringLen(size + 1));
       }
       data[size] = s;
       data[size + 1] = '\0';
       size++;
    
}
