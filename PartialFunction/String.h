#pragma once
#include <fstream>

class String{
    
private:
    char* data;
    size_t size;
    size_t allocatedData;
    
    void resize(size_t newAllocData);
    void copy(const String& other);
    void free();
    void move(String&& other);
    explicit String(size_t stringLen);
    
public:
    String();
    String(char* data);
    String(const String& other);
    String(String&& other);
    String& operator=(const String& other);
    String& operator=(String&& other);
    ~String();
    
    static size_t roundPowerOfTwo(size_t v);
    static size_t dataToAllocByStringLen(size_t stringLen);
    
    
    const char* c_str() const;
    size_t getSize()const;
    size_t getAllocData()const;
    
    
    bool contains(const String& str) const;
    
    String& operator+=(const String& other);
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
    friend std::ostream& operator<<(std::ostream& os, String& obj);
    friend std::istream& operator>>(std::istream& is, String& obj);
    friend String operator+(const String& lhs, const String& rhs);
    
    void addSymbol(char s);
    
};

bool operator==(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
