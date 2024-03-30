// test-prep.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Server.h"

int main()
{
	User user1("Name1", "Pass1");
	User user2("Name2", "Pass2");
	User user3("Name3", "Pass3");
	User user4("Name4", "Pass4");
	User users[] = { user1,user2,user3,user4 };
	Server server(users,4);
	server.printUsers();
	server.printMostActive();
	std::ofstream ofs("Server.dat", std::ios::binary);
	server.saveInBinary(ofs);
}

