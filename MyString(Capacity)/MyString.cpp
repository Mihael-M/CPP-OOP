#include "MyString.h"
#pragma warning (disable : 4996)
static unsigned roundToPowerOfTwo(unsigned v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v++;
    return v;
}
static unsigned dataToAllocByStringLen(unsigned stringLength)
{
    return std::max(roundToPowerOfTwo(stringLength + 1), 16u);
}


void MyString::copy(const MyString& other)
{
    this->data = new char[std::strlen(other.data) + 1];
    strcpy(data, other.data);
    this->size = other.size;
    this->capacity = other.capacity;
}

void MyString::free()
{
	delete[] data;
}

void MyString::resize(unsigned newCapacity)
{
    char* newData = new char[newCapacity + 1];
    strcpy(newData, data);
    free();
    data = newData;
    capacity = newCapacity;
}

MyString::MyString() : MyString("") {}

MyString::MyString(const char* data)
{
    size_t _size = strlen(data);
    this->capacity = dataToAllocByStringLen(_size);
    this->size = _size;
    this->data = new char[_size + 1];
    strcpy(this->data, data);
   
}
MyString::MyString(size_t stringSize)
{
   
    this->capacity = dataToAllocByStringLen(stringSize);
    
    this->data = new char[this->capacity];
    this->size = 0;
    data[0] = '\0';

}

MyString::MyString(const MyString& other)
{
    copy(other);
}

MyString& MyString::operator=(const MyString& other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

MyString::~MyString()
{
    free();
}

size_t MyString::getSize()
{
    return size;
}

size_t MyString::getCapacity()
{
    return capacity;
}

const char* MyString::c_str() const
{
    return data;
}

char& MyString::operator[](size_t index) const
{
    return data[index];
}

char MyString::operator[](size_t index)
{
    return data[index];
}

MyString& MyString::operator+=(const MyString& other)
{
    size_t newSize = this->size + other.size + 1;
    if (capacity < newSize)
    { 
        capacity = dataToAllocByStringLen(newSize);
       
        this->resize(newSize);
    }
    strncat(this->data, data,other.size);

    return *this;



}

std::istream& operator>>(std::istream& is, MyString& str)
{
    char buff[1024];
    is >> buff;
   
    str.size = strlen(buff);
    if (str.size > str.capacity)
       str.resize(dataToAllocByStringLen(str.size));
    
    strcpy(str.data, buff);
    return is;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
    MyString str(lhs);
    str += rhs;
    return str;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
   return os << str.c_str();
}

bool operator==(const MyString& lhs, const MyString& rhs) 
{
    return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
    return !(lhs == rhs);
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
    return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
