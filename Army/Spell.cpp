#include "Spell.h"

#include <iostream>
using namespace std;

Spell::Spell() : description(nullptr), type(nullptr), worth(0)
{
}

Spell::Spell(const char* newDescription, const char* newType, const int newWorth)
{
	description = new char[strlen(newDescription) + 1];
	strcpy_s(description, strlen(newDescription) + 1, newDescription);

	type = new char[strlen(newType) + 1];
	strcpy_s(type, strlen(newType) + 1, newType);
	
	worth = newWorth;
}


Spell::Spell(const Spell& other)
{
	copy(other);
}

Spell& Spell::operator=(const Spell& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Spell::~Spell()
{
	delete[] description;
	delete[] type;
}

void Spell::free()
{
	delete[] description;
	description = NULL;
	delete[] type;
	type = NULL;
	worth = 0;
}

void Spell::copy(const Spell& other)
{
	description = new char[strlen(other.description) + 1];
	strcpy_s(description, strlen(other.description) + 1, other.description);
	
	type = new char[strlen(other.type) + 1];
	strcpy_s(type, strlen(other.type) + 1, other.type);

	worth = other.worth;
}

char* Spell::getDescription()const
{
	return description;
}


char* Spell::getType()const
{
	return type;
}

int Spell::getWorth()const
{
	return worth;
}




