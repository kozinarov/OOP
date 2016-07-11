#include "SpellBook.h"


SpellBook::SpellBook() : spells(nullptr), size(0), cap(1)
{
	spells = new Spell[1];
}

SpellBook::SpellBook(const SpellBook& other)
{
	copy(other);
}

SpellBook& SpellBook::operator=(const SpellBook& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

SpellBook::~SpellBook()
{
	delete[] spells;
}

void SpellBook::free()
{
	delete[] spells;
	size = 0;
	cap = 1;
}

void SpellBook::copy(const SpellBook& other)
{
	spells = new Spell[other.cap];
	for (size_t i = 0; i < other.size; i++)
	{
		spells[i] = other.spells[i];
	}

	size = other.size;
	cap = other.cap;
}

Spell SpellBook::operator[](const int pos)const
{
	if(pos < 0 || pos > size)
		throw "Invalid position";

	return spells[pos];
}

void SpellBook::add(const Spell& newSpell)
{
	resize();
	spells[size] = newSpell;
	size++;
}


Spell SpellBook::take(const int pos)
{
	if (pos < 0 || pos > size)
		throw "Invalid position";

	
	for (size_t j = pos; j < size - 1; j++)	
	{
		spells[j] = spells[j + 1];
	}

	size--;
	resize();
	
}

void SpellBook::resize()
{
	size_t newCap;

	if (size >= cap)
	{
		newCap = size + 1;
	}
	else if (size + 1 < cap)
	{
		newCap = cap - 1;
	}
	else
		return;

	Spell* newSpells = new Spell[newCap];
	for (size_t i = 0; i < size; i++)
	{
		newSpells[i] = spells[i];
	}

	cap = newCap;
	delete[] spells;
	spells = newSpells;
	
}

size_t SpellBook::getSize()const
{
	return size;
}

int SpellBook::peekWorthPerSpell(const int idx)const
{
	if (idx < 0 || idx > size)
		throw "bad index";

	return spells[idx].getWorth();
}

//sorting the spells by their worth
void SpellBook::sort()
{
	for (int i = 0; i < size - 1; i++)

		for (int j = i + 1; j < size; j++)

			if (spells[i].getWorth() > spells[j].getWorth())
			{
				Spell tmp = spells[i];
				spells[i] = spells[j];
				spells[j] = tmp;
			}
}