#pragma once
#include "User.h"
#include <fstream>
constexpr int MAX_SIZE = 20;
class Server {
private:
	User users[MAX_SIZE];
	unsigned size = 0;
	
public:
	Server() = default;
	Server(User* users,unsigned size);
	void addUser(const User& user);
	void deleteUser(const char* name);
	bool containsUser(const char* name);
	void printUsers();
	void printMostActive()const;
	void saveInBinary(std::ofstream& ofs);
	User* readUsers(std::ifstream& ifs);

};
