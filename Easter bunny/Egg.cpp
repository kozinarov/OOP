#include "Egg.h"

Egg::Egg():name(NULL),size(0)
{
}

Egg::Egg(const Egg& other)
{
	this->copy(other);
}

Egg& Egg::operator=(const Egg& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}
	return *this;
}

Egg::~Egg()
{
	delete[] name;
}

void Egg::clear()
{
	delete[] name;
	size = 0;
}

void Egg::copy(const Egg& other)
{	
	int sizeName = strlen(other.name) + 1;
	try
	{
		name = new char[sizeName];
	}
	catch (const std::bad_alloc& e)
	{
		std::cout << e.what() << std::endl;
		clear();
		throw;
	}
	strcpy_s(name, sizeName, other.name);

	size = other.size;
}

void Egg::setName(const char* newName)
{	
	delete[] name;
	int sizeName = strlen(newName) + 1;
	try
	{
		name = new char[sizeName];

	}
	catch (const std::bad_alloc& e)
	{
		std::cout << e.what() << std::endl;
		delete[] name;
		throw;
	}
	strcpy_s(name, sizeName, newName);

}

void Egg::setSize(const int newSize)
{
	size = newSize;
}

char* Egg::getName()const
{
	
	return name;
}

int Egg::getSize()const
{
	return size;
}

Egg& Egg::operator+=(const char* suf)
{
	int sizeNewName = strlen(name) + strlen(suf) + 1;
	char *newName = new(std::nothrow) char[sizeNewName + 1];

	strcpy_s(newName, sizeNewName + 1, name);
	strcat_s(newName, sizeNewName + 1, suf);
	this->setName(newName);
	delete[] newName;

	return *this;
}

Egg& Egg::operator*=(const int num)
{
	size *= num;

	return *this;
}

Egg& Egg::operator/=(const int num)
{
	size /= num;

	return *this;
}

bool operator==(const Egg& left, const Egg& right)
{
	if (strcmp(left.getName(), right.getName()) == 0)
		return true;
	else
		return false;
}

bool operator!=(const Egg& left, const Egg& right)
{
	return !(left == right);
}

bool operator<(const Egg& left, const Egg& right)
{
	if (strcmp(left.getName(), right.getName()) < 0)
		return false;
	else
		return true;
}

bool operator>(const Egg& left, const Egg& right)
{
	return !(left > right);
}

Egg operator+(const Egg& left, const char* suf)
{
	Egg newE;
	newE = left;
	newE += suf;

	return newE;
}

Egg operator*(const Egg& left, const int num)
{
	Egg newE;
	newE = left;
	newE *= num;

	return newE;
}

Egg operator/(const Egg& left, const int num)
{
	Egg newE;
	newE = left;
	newE /= num;

	return newE;
}