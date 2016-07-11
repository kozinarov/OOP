#pragma once
#ifndef __Egg_HEADER__
#define __Egg_HEADER__
#include <iostream>

class Egg
{
public:
	Egg();
	Egg(const Egg&);
	Egg& operator=(const Egg&);
	~Egg();

private:
	void clear();
	void copy(const Egg&);

public:
	void setName(const char*);
	void setSize(const int);

	char* getName()const;
	int getSize()const;

public:
	Egg& operator+=(const char*);
	Egg& operator*=(const int);
	Egg& operator/=(const int);

private:
	char* name;
	int size;
};

bool operator==(const Egg&, const Egg&);
bool operator!=(const Egg&, const Egg&);
bool operator<(const Egg&, const Egg&);
bool operator>(const Egg&, const Egg&);
Egg operator+(const Egg&, const char*);
Egg operator*(const Egg&, const int);
Egg operator/(const Egg&, const int);


#endif //__Egg_HEADER__