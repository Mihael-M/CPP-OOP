#pragma once
#include <iostream>
#pragma warning(disable:4996)

const size_t BUFFER_SIZE = 1024; //size of the buffer that we are using for the redefenition of the operator >>.

class String {
private:
	char* data = nullptr;
	int size = 0;
	void copy(const String& other); //copy function used in the copy constructor.
	void free(); // destroy function which is used in the destructor.
	explicit String(int size); //constructor which allocates memory.
	bool subStr(const char* first,const char* sub);


public:
	//constructor
	String();
	String(const char* data);
	String(const String& other);
	~String();

	//setter:
	void setData(const char* data);
	const char* c_str() const; //getData()

	//operators:
	String& operator=(const String& other);
	String& operator=(char literal);
	String operator()(int times); //Duplicates the string * times
	const char& operator[](size_t index)const; //shows the symbol on this index.
	char& operator[](int index); //Shows char.
	
	
	String& operator+=(const String& other); //Unites one vector with another.
	friend std::ostream& operator<<(std::ostream& os, const String& str);
	friend std::istream& operator>>(std::istream& is, String& str);
	String& operator-=(const String& str); //Removes substring from a string.

	


	//functions:
	const int getSize() const;
	bool contains(const char* sub);
	void reverse();
	bool palindrome();
	void clear();
	//String* group();
	const int distinctCharacters()const;


};
String operator+(const String& first, const String& second); //Unites two vectors.
String operator-(const String& first, const String& second); //Removes substring from a string.
bool operator==(const String& left, const String& right);
bool operator!=(const String& left, const String& right);

