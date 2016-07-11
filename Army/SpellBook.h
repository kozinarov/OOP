#pragma once
#ifndef __SpellBook_HEADER__
#define __SpellBook_HEADER__

#include "Spell.h"

class SpellBook
{
public:
	SpellBook();
	SpellBook(const SpellBook&);
	SpellBook& operator=(const SpellBook&);
	~SpellBook();

public:
	void add(const Spell&);
	Spell take(const int);
	size_t getSize()const;

	int peekWorthPerSpell(const int)const;
	void sort();

private:
	Spell operator[](const int)const;
	void free();
	void copy(const SpellBook&);
	void resize();

private:
	Spell* spells;
	size_t size;
	size_t cap;
};

#endif // __SpellBook_HEADER__
