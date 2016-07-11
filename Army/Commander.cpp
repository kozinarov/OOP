#include "Commander.h"
#include <iostream>
using namespace std;


Commander::Commander() : descriptionCommander(nullptr), wizards(nullptr), numWizards(0), capWizards(1), Soldier()
{
	wizards = new Wizard[1];
}

Commander::Commander(const char* newName, const int newAge, const int newStrenght, const int newSalary,
	const char* newDCommander, const Wizard* newWizards, const int newNumWizards)
{
	Soldier::setName(newName);
	Soldier::setAge(newAge);
	Soldier::setStrenght(newStrenght);
	Soldier::setSalary(newSalary);

	descriptionCommander = new char[strlen(newDCommander) + 1];
	strcpy_s(descriptionCommander, strlen(newDCommander) + 1, newDCommander);

	wizards = new Wizard[newNumWizards * 2];
	for (size_t i = 0; i < newNumWizards; i++)
	{
		wizards[i] = newWizards[i];
	}
	numWizards = newNumWizards;
	capWizards = newNumWizards * 2;
}

Commander::Commander(const Commander& other)
{
	copy(other);
}

Commander& Commander::operator=(const Commander& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}
	
Commander::~Commander()
{
	delete[] descriptionCommander;
	delete[] wizards;
}

void Commander::free()
{
	delete[] descriptionCommander;
	delete[] wizards;
	numWizards = 0;
	capWizards = 1;
}

void Commander::copy(const Commander& other)
{

	Soldier::setName(other.getName());
	Soldier::setAge(other.getAge());
	Soldier::setStrenght(other.getStrenght());
	Soldier::setSalary(other.getSalary());

	descriptionCommander= new char[strlen(other.descriptionCommander) + 1];
	strcpy_s(descriptionCommander, strlen(other.descriptionCommander) + 1, other.descriptionCommander);

	wizards = new Wizard[other.capWizards];
	for (size_t i = 0; i < other.numWizards; i++)
	{
		wizards[i] = other.wizards[i];
	}

	numWizards = other.numWizards;
	capWizards = other.capWizards;
}

int Commander::sumStrenght()const
{
	int sum = 0;
	for (size_t i = 0; i < numWizards; i++)
	{
		sum += wizards[i].sumStrenght();
	}
	sum += Soldier::getStrenght();
	return sum;
}

int Commander::sumMana()const
{
	int sum = 0;
	for (size_t i = 0; i < numWizards; i++)
	{
		sum += wizards[i].getMana();
	}

	return sum;
}

int Commander::sumSalary()const
{
	int sum = 0;
	for (size_t i = 0; i < numWizards; i++)
	{
		sum += wizards[i].sumSalary();
	}
	sum += Soldier::getSalary();
	return sum;
}

int Commander::sumNumPeople()const
{
	int sum = 0;
	for (size_t i = 0; i < numWizards; i++)
	{
		sum += wizards[i].sumNumPeople();
	}
	//adding and hte number of wizards
	sum += numWizards;
	//this time we add and the comander
	sum += 1;

	return sum;
}

int Commander::averageStrenght()const
{	
	
	return sumStrenght() / sumNumPeople();
}

int Commander::averageMana()const
{
	return sumMana() / numWizards;
}

int Commander::sumMaxSpells()const
{
	int sum = 0;
	for (size_t i = 0; i < numWizards; i++)
	{
		sum += wizards[i].maxSpells();
	}
	return sum;
}