#pragma once

#ifndef __Commander_HEADER__
#define __Commander_HEADER__

#include "Soldier.h"
#include "Wizard.h"
class Commander : public Soldier
{
public:
	Commander();
	Commander(const char*, const int, const int, const int,
		const char*, const Wizard*, const int);
	Commander(const Commander&);
	Commander& operator=(const Commander&);
	~Commander();

	int sumStrenght()const;
	int sumNumPeople()const;
	int averageStrenght()const;
	int sumMana()const;
	int averageMana()const;
	int sumSalary()const;
	
	int sumMaxSpells()const;


private:
	void free();
	void copy(const Commander&);

private:
	char* descriptionCommander;
	Wizard* wizards;
	size_t numWizards;
	size_t capWizards;
};

#endif // __Commander_HEADER__