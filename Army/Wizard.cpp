#include "Wizard.h"
#include <iostream>
using namespace std;



Wizard::Wizard() : desvriptionWizard(nullptr), sergeants(nullptr), numSergeants(0), capSergeants(1), mana(0), Soldier(), book()
{
	sergeants = new Sergeant[1];
}

Wizard::Wizard(const char* newName, const int newAge, const int newStrenght, const int newSalary,
	const char* newDWizard, const Sergeant* newSergeants, const int newNumSergeants, const int newMana, const SpellBook newBook)
{
	Soldier::setName(newName);
	Soldier::setAge(newAge);
	Soldier::setStrenght(newStrenght);
	Soldier::setSalary(newSalary);

	desvriptionWizard = new char[strlen(newDWizard) + 1];
	strcpy_s(desvriptionWizard, strlen(newDWizard) + 1, newDWizard);
	sergeants = new Sergeant[newNumSergeants * 2];
	for (size_t i = 0; i < newNumSergeants; i++)
	{	
		sergeants[i] = newSergeants[i];
	}
	numSergeants = newNumSergeants;
	capSergeants = newNumSergeants * 2;
	mana = newMana;
	book = newBook;
}

Wizard::Wizard(const Wizard& other)
{
	copy(other);
}

Wizard& Wizard::operator=(const Wizard& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Wizard::~Wizard()
{
	delete[] desvriptionWizard;
	delete[] sergeants;
}

void Wizard::free()
{
	delete[] desvriptionWizard;
	delete[] sergeants;
	numSergeants = 0;
	capSergeants = 1;
}

void Wizard::copy(const Wizard& other)
{

	Soldier::setName(other.getName());
	Soldier::setAge(other.getAge());
	Soldier::setStrenght(other.getStrenght());
	Soldier::setSalary(other.getSalary());

	desvriptionWizard = new char[strlen(other.desvriptionWizard) + 1];
	strcpy_s(desvriptionWizard, strlen(other.desvriptionWizard) + 1, other.desvriptionWizard);

	sergeants = new Sergeant[other.capSergeants];
	for (size_t i = 0; i < other.numSergeants; i++)
	{
		sergeants[i] = other.sergeants[i];
	}

	numSergeants = other.numSergeants;
	capSergeants = other.capSergeants;
	mana = other.mana;
	book = other.book;
}

int Wizard::sumStrenght()const
{
	int sum = 0;
	for (size_t i = 0; i < numSergeants; i++)
	{
		sum += sergeants[i].sumStrenght();
	}
	sum += Soldier::getStrenght();
	return sum;
}

int Wizard::getMana()const
{
	return mana;
}

int Wizard::sumSalary()const
{
	int sum = 0;
	for (size_t i = 0; i < numSergeants; i++)
	{
		sum += sergeants[i].sumSalary();
	}
	sum += Soldier::getSalary();
	return sum;
}

int Wizard::sumNumPeople()const
{
	int sum = 0;
	for (size_t i = 0; i < numSergeants; i++)
	{
		sum += sergeants[i].getNumSoldiers();
	}
	//add and the number of the segeants
	sum += numSergeants;
	return sum;
}

int Wizard::maxSpells()
{	
	book.sort();
	int cnt = 0;
	for (size_t i = 0; i < book.getSize(); i++)
	{
		if (mana < book.peekWorthPerSpell(i))
		{
			break;
		}
		cnt++;
		mana -= book.peekWorthPerSpell(i);
	}

	return cnt;
}