#include "String.h"

void String::copy(const String& other)
{
	this->data = new char[strlen(other.data) + 1];
	strcpy(data, other.data);
	this->size = other.size;
}

void String::free()
{
	delete[] data;
	data = nullptr;
	size = 0;
}

bool String::subStr(const char* first, const char* sub)
{
	for (size_t i = 0; i < strlen(sub); i++)
	{
		if (first[i] != sub[i])
			return false;
	}
	return true;
}

String::String()
{
	data = new char[1];
	*data = '\0';
	size = 0;
}

String::String(const char* data)
{
	setData(data);

}

String::String(const String& other)
{
	copy(other);
}

String::~String()
{
	free();
}

void String::setData(const char* data)
{
	if (!data || this->data == data) {

		return;
	}

	delete[] this->data;
	this->size = std::strlen(data);
	this->data = new char[this->size + 1];
	std::strcpy(this->data, data);
}

const char* String::c_str() const
{
	return this->data;
}

String& String::operator=(const String& other)
{
	if (this != &other) {
		free();
		copy(other);
	}
	return *this;
}

String& String::operator=(char literal)
{
	*(this->data) = literal;
	return *this;
}

String String::operator()(int times)
{
	size_t newSize = this->size * times;
	String str;
	str.data = new char[newSize + 1];
	str.size = newSize;
	strcpy(str.data, this->data);
	for (size_t i = 0; i < times-1; i++)
	{
		strcat(str.data, this->data);
	}
	
	return str;

}

const char& String::operator[](size_t index) const
{
	return this->data[index];
}

char& String::operator[](int index) {
	return this->data[index];
}

const int String::getSize() const
{
	return size;
}

bool String::contains(const char* str)
{
	int index = 0;

	size_t len = std::strlen(str);
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (data[i] == str[index]) {
			index++;
			count++;
			if (count == len) {
				return true;
			}
		}
		else {
			index = 0;
			count = 0;
		}
	}
	return false;
}

void String::reverse()
{
	for (size_t i = 0; i < size / 2; i++)
	{
		std::swap(data[i], data[size - i - 1]);
	}
	//strrev(str.data);
}

bool String::palindrome()
{
	for (size_t i = 0; i < size/2; i++)
	{
		if (data[i] != data[size - i - 1])
			return false;
	}
	return true;
}

String& String::operator+=(const String& other)
{
	int allSize = this->size + other.size + 1;
	char* temp = new char[allSize];
	strcpy(temp, this->data);
	strcat(temp, other.data);
	this->free();
	this->data = temp;
	this->size = allSize;
	return *this;
}

String& String::operator-=(const String& str)
{
	if (!contains(str.data) && this->size < str.size)
		return *this;

	size_t index = 0;
	size_t newSize = size - str.size;
	char* newStr = new char[newSize + 1];
	char* current = data;
	while (*data)
	{
		if (subStr(data, str.data))
		{
			data += str.size;
		}
		else {
			newStr[index++] = *data;
			data++;
		}
		
	}
	newStr[index] = '\0';
	data = current;
	delete[] current;
	data = newStr;
	this->size = newSize;
	return *this;
	

}

String operator-(const String& first,const String& second)
{
	String str(first);
	str -= second;
	return str;

}

String operator+(const String& first, const String& second)
{
	String united(first);
	united += second;
	return united;

}

void String::clear() {
	data[0] = '\0';
}

/*String* String::group()
{
	int characters = distinctCharacters();
	String* groups = new String[characters];
	size_t distinctSize = 0;
	char* distinct = new char[size];
	char* buff = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		buff[0] = data[i];
		bool flag = false;
		for (size_t j = 0; j < strlen(distinct); j++)
		{
			if (data[i] == distinct[j]) {
				flag = true;
				buff[1] = data[i];
				for (size_t k = i,buffIndex=2; k < size;buffIndex++, k++)
				{

					if (data[k] == distinct[j]) {
						buff[i] = distinct[j];
					}
					break;
				}

			}
			if (!flag)
				distinct[distinctSize++] = data[i];

		}

	}
	delete[] distinct;
}*/

const int String::distinctCharacters() const 
{
	size_t distinctSize = 0;
	char* distinct = new char[size];
	for (size_t i = 0; i < size; i++)
	{
		bool flag = false;
		for (size_t j = 0; j < strlen(distinct); j++)
		{
			if (data[i] == distinct[j]) {
				flag = true;
				break;
			}

		}
		if (!flag)
			distinct[distinctSize++] = data[i];



	}
	delete[] distinct;
	return distinctSize;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{

	return os << str.c_str();
	/*for (size_t i = 0; i < str.size; i++)
	{
		os << str.data[i];
	}
	return os*/
}

std::istream& operator>>(std::istream& is, String& str)
{

	char buff[BUFFER_SIZE];
	is.getline(buff, BUFFER_SIZE);
	str.free();
	str.setData(buff);
	return is;
}

bool operator==(const String& left, const String& right)
{
	if (left.getSize() == right.getSize())
	{
		if (strcmp(left.c_str(), right.c_str()) == 0)
		{
			return true;
		}
	}
	return false;
}

bool operator!=(const String& left, const String& right)
{
	return !(left == right);
}
