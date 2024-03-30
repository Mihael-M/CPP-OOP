#include "Server.h"

Server::Server(User* users,unsigned size)
{
	for (size_t i = 0; i < size; i++)
	{
		this->users[i] = users[i];
	}
	this->size = size;
}

void Server::addUser(const User& user)
{
	size++;
	if (size > MAX_SIZE)
		return;
	
	users[size] = user;
	

}

void Server::deleteUser(const char* name)
{
	for (size_t i = 0; i < size; i++)
	{
		if ((strcmp(users[i].getName(), name) == 0))
		{
			for (size_t j = 0; j < size - 1; j++)
			{
				users[j] = users[i + 1];


			}
			size--;
			std::cout << "User is deleted" << std::endl;
			return;
		}
	}
}

bool Server::containsUser(const char* name)
{
	for (size_t i = 0; i < size; i++)
	{
		if ((strcmp(users[i].getName(), name) == 0))
		{
			users[i].log();
			return true;
		}
	}
	return false;
}


void Server::printUsers()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Name: " << users[i].getName() << std::endl;
		std::cout << "Password: " << users[i].getPassword() << std::endl;
		users[i].log();


	}
}

void Server::printMostActive() const
{
	int maxLog = 0;
	int maxLogIndex = 0;
	for (size_t i = 0; i < size; i++)
	{
		maxLog = users[i].getLogs();
		if (users[i].getLogs() > maxLog)
		{
			maxLog = users[i].getLogs();
			maxLogIndex = i;
		}
	}
	std::cout << "Most Active: " << users[maxLogIndex].getName() << std::endl;

}

void Server::saveInBinary(std::ofstream& ofs)
{
	if (!ofs.is_open())
	{
		std::cout << "error";
		return;
	} 
	for (size_t i = 0; i < size; i++)
	{
		users[i].saveUser(ofs);
	}
	
}

User* Server::readUsers(std::ifstream& ifs)
{
	if (!ifs.is_open())
	{
		std::cout << "error";
		return users;
	}
	for (size_t i = 0; i < size; i++)
	{
		users[i].readUser(ifs);
	}
	return users;
}


