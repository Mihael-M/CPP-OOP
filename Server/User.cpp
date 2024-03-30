#include "User.h"

void User::copy(const User& other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy_s(this->name, strlen(other.name) + 1, other.name);
	this->password = new char[strlen(other.password) + 1];
	strcpy_s(this->password, strlen(other.password) + 1, other.password);
	this->logs = other.logs;
}

void User::free()
{
	delete[] name;
	delete[] password;
	name = nullptr;
	password = nullptr;
	logs = 0;
}

User::User(const char* name, const char* password)
{
	setName(name);
	setPassword(password);
	
}

User::User(const User& other)
{

	copy(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

User::~User()
{
	free();
}

void User::log()
{
	this->logs++;
}

const unsigned User::getLogs() const
{
	return logs;
}


const char* User::getName() const
{
	return name;
}

const char* User::getPassword() const
{
	return password;
}

void User::setName(const char* name)
{
	if (!name || this->name==name)
		return;
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name,strlen(name) + 1, name);

}

void User::setPassword(const char* password)
{
	if (!password || this->password == password)
		return;
	delete[] this->password;
	this->password = new char[strlen(password) + 1];
	strcpy_s(this->password, strlen(password) + 1, password);
}

void User::saveUser(std::ofstream& ofs)
{
	int nameLen = strlen(name);
	ofs.write((const char*)&nameLen, sizeof(int));
	ofs.write(name, nameLen + 1);
	int passLen = strlen(password);
	ofs.write((const char*)&passLen, sizeof(int));
	ofs.write(password, passLen + 1);

}

User User::readUser(std::ifstream& ifs)
{
	User user;
	int size = 0;
	ifs.read((char*)&size, sizeof(int));
	user.name = new char[size + 1];
	ifs.read(name, size + 1);
	int sizePass = 0;
	ifs.read((char*)&sizePass, sizeof(int));
	user.password = new char[sizePass + 1];
	ifs.read(password, sizePass + 1);
	return user;
}
