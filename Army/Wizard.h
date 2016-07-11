#pragma once

#ifndef __Wizard_HEADER__
#define __Wizard_HEADER__

#include "Soldier.h"
#include "Sergeant.h"
#include "SpellBook.h"

class Wizard : public Soldier
{
public:
	Wizard();
	Wizard(const char*, const int, const int, const int, 
		const char*, const Sergeant*, const int, const int, const SpellBook);
	Wizard(const Wizard&);
	Wizard& operator=(const Wizard&);
	~Wizard();

	int sumStrenght()const;
	int getMana()const;
	int sumSalary()const;

	int sumNumPeople()const;

	int maxSpells();

private:
	void free();
	void copy(const Wizard&);

private:
	char* desvriptionWizard;
	Sergeant* sergeants;
	size_t numSergeants;
	size_t capSergeants;
	int mana;
	SpellBook book;
};

#endif //__Wizard_HEADER__