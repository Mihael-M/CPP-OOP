#include "ImmutableString.h"
StringPool ImmutableString:: strPool;

void ImmutableString::copy(const ImmutableString& data)
{
	this->data = strPool.getAllocatedString(data.data);
}

void ImmutableString::free()
{
	strPool.releaseString(this->data);
	this->data = nullptr;
}

ImmutableString::ImmutableString(const char* data)
{
	this->data = strPool.getAllocatedString(data);

}

ImmutableString::ImmutableString(const ImmutableString& other)
{
	copy(other);
}

ImmutableString::~ImmutableString()
{
	free();
}

size_t ImmutableString::length() const
{
	return _length;
}

char ImmutableString::operator[](size_t index) const
{
	return this->data[index];
}

const char* ImmutableString::c_str() const
{
	return this->data;
}
std::ostream& operator<<(std::ostream& os, const ImmutableString& str)
{
	return os << str.c_str();
}
bool operator<(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}

bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs)
{
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}

