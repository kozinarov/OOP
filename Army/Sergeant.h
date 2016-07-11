#pragma once
#ifndef __Sergeant_HEADER__
#define __Sergeant_HEADER__

#include "Soldier.h"
class Sergeant : public Soldier
{
public:
	Sergeant();
	Sergeant(const char*, const int, const int, const int, const char*, const Soldier*, const size_t);
	Sergeant(const Sergeant&);
	Sergeant& operator=(const Sergeant&);
	~Sergeant();

	int sumStrenght()const;
	int sumSalary()const;
	int getNumSoldiers()const;

private:
	void free();
	void copy(const Sergeant&);

private:
	char* description;
	Soldier* soldiers;
	size_t numSoldiers;
	size_t capSoldiers;
};

#endif // __Sergeant_HEADER__