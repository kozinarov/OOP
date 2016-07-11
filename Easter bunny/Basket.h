#pragma once
#ifndef __Basket_HEADER__
#define __Basket_HEADER__

#include "Egg.h"

class Basket
{
public:
	Basket();
	Basket(const Basket&);
	Basket& operator=(const Basket&);
	~Basket();

private:
	void clear();
	void copy(const Basket&);
	void resize();
	bool isUnique(const char*)const;

public:
	void setBasketName(const char*);
	void addEgg(const Egg&);
	void takeEgg(const char*);

	char* getBasketName()const;
	size_t getSize()const;
	size_t getCap()const;

public:
	Egg operator[](int)const;
	Egg& operator[](const char*)const;
	Basket& operator+=(const Basket&);
	Basket& operator+=(const char*);
	Basket& operator*=(const int);
	Basket& operator/=(const int);
	Basket& operator%=(const Basket&);

private:
	char* basketName;
	Egg* basket;
	size_t size;
	size_t cap;

};

Basket operator+(const Basket&, const Basket&);
Basket operator+(const Basket&, const char*);
Basket operator*(const Basket&, const int);
Basket operator/(const Basket&, const int);
Basket operator%(const Basket&, const Basket&);
bool operator==(const Basket&, const Basket&);
bool operator!=(const Basket&, const Basket&);
bool operator<(const Basket&, const Basket&);
bool operator<=(const Basket&, const Basket&);
bool operator>=(const Basket&, const Basket&);


#endif // __Basket_HEADER__