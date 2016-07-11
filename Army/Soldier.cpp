#include "Soldier.h"
#include <iostream>
using namespace std;


Soldier::Soldier() : name(nullptr), age(0), strenght(0), salary(0)
{
}

Soldier::Soldier(const char* newName, const int newAge, const int newStrenght, const int newSalary)
{
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
	age = newAge;
	strenght = newStrenght;
	salary = newSalary;
}

Soldier::Soldier(const Soldier& other)
{
	copy(other);
}

Soldier& Soldier::operator=(const Soldier& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Soldier::~Soldier()
{
	delete[] name;
}

void Soldier::free()
{
	delete[] name;
	name = NULL;
	age = 0;
	strenght = 0;
	salary = 0;
}

void Soldier::copy(const Soldier& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy_s(name, strlen(other.name) + 1, other.name);
	age = other.age;
	strenght = other.strenght;
	salary = other.salary;
}

void Soldier::setName(const char* newName)
{
	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy_s(name, strlen(newName) + 1, newName);
}

void Soldier::setAge(const int newAge)
{
	age = newAge;
}
void Soldier::setStrenght(const int newStrenght)
{
	strenght = newStrenght;
}

void Soldier::setSalary(const int newSalary)
{
	salary = newSalary;
}

char* Soldier::getName()const
{
	return name;
}

int Soldier::getAge()const
{
	return age;
}

int Soldier::getStrenght()const
{
	return strenght;
}

int Soldier::getSalary()const
{
	return salary;
}