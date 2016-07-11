#pragma once
#ifndef __Spell_HEADER__
#define __Spell_HEADER__
class Spell
{
public:
	Spell();
	Spell(const char*, const char*, const int);
	Spell(const Spell&);
	Spell& operator=(const Spell&);
	~Spell();

public:
	char* getDescription()const;
	char* getType()const;
	int getWorth()const;

private:
	void free();
	void copy(const Spell&);

private:
	char* description;
	char* type;
	int worth;
};

#endif // __Spell_Header__
