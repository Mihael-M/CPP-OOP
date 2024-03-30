#pragma once
#include <iostream>
#include <fstream>

class User {
private:
	char* name = nullptr;
	char* password = nullptr;
	unsigned logs = 0;
	void copy(const User& other);
	void free();
public:
	User() = default;
	User(const char* name, const char* password);
	User(const User& other);
	User& operator=(const User& other);
	~User();
	void log();
	const unsigned getLogs()const;
	const char* getName() const;
	const char* getPassword()const;
	void setName(const char* name);
	void setPassword(const char* password);
	void saveUser(std::ofstream& ofs);
	User readUser(std::ifstream& ifs);
	
};
