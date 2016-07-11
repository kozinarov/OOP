#include "Sergeant.h"
#include <iostream>
using namespace std;

Sergeant::Sergeant() : description(nullptr), soldiers(nullptr), numSoldiers(0), capSoldiers(1), Soldier() 
{	
	soldiers = new Soldier[1];
}

Sergeant::Sergeant(const char* newName, const int newAge, const int newStrenght, const int newSalary,
	const char* newDescription, const Soldier* newSoldiers, const size_t newNumSoldiers)
{
	Soldier::setName(newName);
	Soldier::setAge(newAge);
	Soldier::setStrenght(newStrenght);
	Soldier::setSalary(newSalary);
	
	description = new char[strlen(newDescription) + 1];
	strcpy_s(description, strlen(newDescription) + 1, newDescription);
	
	numSoldiers = newNumSoldiers;
	capSoldiers = newNumSoldiers * 2;
	soldiers = new Soldier[capSoldiers];
	for (size_t i = 0; i < numSoldiers; i++)
	{
		soldiers[i] = newSoldiers[i];
	}
}

Sergeant::Sergeant(const Sergeant& other)
{
	copy(other);
}

Sergeant& Sergeant::operator=(const Sergeant& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Sergeant::~Sergeant()
{
	delete[] description;
	delete[] soldiers;
}

void Sergeant::free()
{
	delete[] description;
	delete[] soldiers;
	numSoldiers = 0;
	capSoldiers = 1;
}

void Sergeant::copy(const Sergeant& other)
{
	Soldier::setName(other.getName());
	Soldier::setAge(other.getAge());
	Soldier::setStrenght(other.getStrenght());
	Soldier::setSalary(other.getSalary());

	description = new char[strlen(other.description) + 1];
	strcpy_s(description, strlen(other.description) + 1, other.description);

	soldiers = new Soldier[other.capSoldiers];
	for (size_t i = 0; i < other.numSoldiers; i++)
	{
		soldiers[i] = other.soldiers[i];
	}

	numSoldiers = other.numSoldiers;
	capSoldiers = other.capSoldiers;
}

int Sergeant::sumStrenght()const
{
	int sum = 0;
	for (size_t i = 0; i < numSoldiers; i++)
	{
		sum += soldiers[i].getStrenght();
	}
	sum += Soldier::getStrenght();
	return sum;
}

int Sergeant::sumSalary()const
{
	int sum = 0;
	for (size_t i = 0; i < numSoldiers; i++)
	{
		sum += soldiers[i].getSalary();
	}
	sum += Soldier::getSalary();
	return sum;
}

int Sergeant::getNumSoldiers()const
{
	return numSoldiers;
}