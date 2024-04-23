#pragma once
#include "StringPool.h"
class ImmutableString {
private:

	static StringPool strPool;

	const char* data;
	size_t _length;
	explicit ImmutableString(size_t capacity);
	void copy(const ImmutableString& data);
	void free();

public:
	ImmutableString(const char* data);
	ImmutableString(const ImmutableString& other);
	~ImmutableString();


	size_t length() const;

	char operator[](size_t index) const;

	const char* c_str() const;
};
std::ostream& operator<<(std::ostream& os, const ImmutableString& str);

bool operator<(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator<=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>=(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator>(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator==(const ImmutableString& lhs, const ImmutableString& rhs);
bool operator!=(const ImmutableString& lhs, const ImmutableString& rhs);