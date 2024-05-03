#include "SetByString.h"
#pragma warning (disable : 4996)
void SetByString::extractNumbersFromString()
{
    removeAll();
    std::stringstream myStream(str);

    while (!myStream.eof())
    {
        unsigned current;
        myStream >> current;
        add(current);
    }
}
void SetByString::copyFrom(const SetByString& other)
{
    str = new char[strlen(other.str) + 1];
    strcpy(str, other.str);
}
SetByString::SetByString(const SetByString& other) : Set(other)
{
    copyFrom(other);
}
void SetByString::moveFrom(SetByString&& other)
{
    str = other.str;
    other.str = nullptr;
}


SetByString::SetByString(SetByString&& other) : Set(std::move(other))
{
    moveFrom(std::move(other));
}

SetByString& SetByString::operator=(SetByString&& other)
{
    if (this != &other)
    {
        Set::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

SetByString& SetByString::operator=(const SetByString& other)
{
    if (this != &other)
    {
        Set::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

void SetByString::free()
{
    delete[] str;
    str = nullptr;
}
SetByString::SetByString(unsigned n, const char* data) : Set(n)
{
    str = new char[strlen(data) + 1];
    strcpy(str, data);
    extractNumbersFromString();
}


SetByString::~SetByString()
{
    free();
}
void SetByString::setAt(unsigned ind, char ch)
{
    str[ind] = ch;
    extractNumbersFromString();
}
bool SetByString::contains(int i) const
{
    return Set::contains(i);
}
void SetByString::print() const
{
    Set::print();
}


