#pragma once
#include "MyString.h"

class StringView {
private:
	const char* begin;
	const char* end;
public:

	StringView(const char* begin, const char* end);
	StringView(const char* str);
	StringView(const MyString& string);

	size_t length() const;
	char operator[](size_t index) const;

	StringView substr(size_t from, size_t length)const;
	friend std::ostream& operator<<(std::ostream& os, const StringView strView);



};