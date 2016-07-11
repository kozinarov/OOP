#include "Basket.h"
#include "math.h"
using namespace std;

Basket::Basket() : basketName(NULL), basket(NULL), size(0), cap(1)
{ 
	basket = new(nothrow) Egg[1];
}

Basket::Basket(const Basket& other)
{
	copy(other);
}

Basket& Basket::operator= (const Basket& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}

	return *this;
}

Basket::~Basket()
{
	delete[] basketName;
	delete[] basket;
}

void Basket::clear()
{
	delete[] basketName;
	delete[] basket;
	size = 0;
	cap = 1;
}

void Basket::copy(const Basket& other)
{	
	int sizeBasketName = strlen(other.basketName) + 1;
	
	try
	{
		basketName = new char[sizeBasketName];
		basket = new Egg[other.cap];
	}
	catch (const std::bad_alloc& e)
	{
		cout << e.what() << endl;
		clear();
		throw;
	}
	strcpy_s(basketName, sizeBasketName, other.basketName);

	for (size_t i = 0; i < other.size; ++i)
		basket[i] = other.basket[i];

	size = other.size;
	cap = other.cap;

}

void Basket::setBasketName(const char* name)
{
	delete[] basketName;
	int sizeBasketName = strlen(name) + 1;
	try
	{
		basketName = new char[sizeBasketName];
	}
	catch (const std::bad_alloc& e)
	{
		cout << e.what() << endl;
		delete[] basketName;
		throw;
	}
	
	strcpy_s(basketName, sizeBasketName, name);
}

void Basket::addEgg(const Egg& newEgg)
{
	if (isUnique(newEgg.getName()) == true)
	{
		this->resize();

		basket[size] = newEgg;
		size++;
	}
	else
		cout << "Name not unique" << endl;
}

void Basket::takeEgg(const char* eggName)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(basket[i].getName(), eggName) == 0)
		{
			for (size_t j = i; j < size - 1; j++)
			{
				basket[i] = basket[j + 1];
				i++;
			}
			size--;

			resize();
			break;
		}
	}
}


void Basket::resize()
{
	size_t newCap;

	if (size >= cap)
	{
		newCap = size * 2;
	}
	else if (cap / 4 > size)
	{
		newCap = cap / 2;
	}
	else
		return;

	Egg *newBasket = new(nothrow) Egg[newCap];
	for (size_t i = 0; i < size; i++)
	{
		newBasket[i] = basket[i];
	}

	cap = newCap;
	delete[] basket;
	basket = newBasket;
}

bool Basket::isUnique(const char* newName)const
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(basket[i].getName(), newName) == 0)
			return false;
	}
	return true;
}

char* Basket::getBasketName()const
{
	return basketName;
}

size_t Basket::getSize()const
{
	return size;
}

size_t Basket::getCap()const
{
	return cap;
}


Egg Basket::operator[](int pos)const
{
	if (pos < 0 || pos > size)
	{	
	
		try
		{
			throw std::out_of_range("Invalid position");
		}
		catch (const std::out_of_range& e)
		{
			cout << e.what() << endl;
			throw;
		}
	}

	return basket[pos];
}

Egg& Basket::operator[](const char* eName)const
{

	for (size_t i = 0; i < size; ++i)
		if (strcmp(basket[i].getName(), eName) == 0)
			return basket[i];
}

Basket& Basket::operator+=(const Basket& other)
{
	int sizeNewName = strlen(basketName) + strlen(other.basketName);
	char * newName = new(nothrow) char[sizeNewName + 1];
	strcpy_s(newName, sizeNewName + 1, this->basketName);
	strcat_s(newName, sizeNewName + 1, other.basketName);
	this->setBasketName(newName);
	delete[] newName;

	for (size_t i = 0; i < other.size; ++i)
		this->addEgg(other[i]);

	return *this;
}
	
Basket& Basket::operator+=(const char* suf)
{
	for (size_t i = 0; i < size; ++i)
	{	
		//here i use operator+= from Egg
		basket[i] += suf;
	}
	return *this;
}

Basket& Basket::operator*=(const int num)
{
	for (size_t i = 0; i < size; ++i)
	{
		//here i use operator*= from Egg
		basket[i] *= num;
	}
	return *this;
}

Basket& Basket::operator/=(const int num)
{
	for (size_t i = 0; i < size; ++i)
	{
		//here i use operator/= from Egg
		basket[i] /= num;
	}
	return *this;
}

Basket& Basket::operator%=(const Basket& other)
{
	bool cnt = 0;
	for (size_t i = 0; i < this->size; ++i)
	{
		for (size_t j = 0; j < other.size; ++j)
		{	
			//here i use operator= from Egg
			if (basket[i] == other.basket[j])
			{
				cnt = 1;
				break;
			}
		}
		if (cnt == 0)
		{
			this->takeEgg(basket[i].getName());
			i -= 1;
		}cnt = 0;
	}
	return *this;
}

Basket operator+(const Basket& left, const Basket& right)
{
	Basket newB;
	newB = left;
	newB += right;

	return newB;
}

Basket operator+(const Basket& left, const char* suf)
{
	Basket newB;
	newB = left;
	newB += suf;

	return newB;
}

Basket operator*(const Basket& left, const int num)
{
	Basket newB;
	newB = left;
	newB *= num;

	return newB;
}

Basket operator/(const Basket& left, const int num)
{
	Basket newB;
	newB = left;
	newB /= num;

	return newB;
}

Basket operator%(const Basket& left, const Basket& right)
{
	Basket newB;
	newB = left;
	newB %= right;

	return newB;
}


bool operator==(const Basket& left, const Basket& right)
{
	if (left.getSize() != right.getSize())
		return false;
	
	for (size_t i = 0; i < left.getSize(); i++)
	{
		//here i use operator!= from Egg
		if (left[i] != right[i])
			return false;
	}

	return true;
}

bool operator!=(const Basket& left, const Basket& right)
{
	return !(left == right);
}

bool operator<(const Basket& left, const Basket& right)
{	
	//here i use operator== from Egg
	if (left == right)
	{
		return false;
	}
	else
		//here i use operator<= from Egg
		return left <= right;
	
}

bool operator<=(const Basket& left, const Basket& right)
{
	size_t lSize = left.getSize();
	size_t rSize = right.getSize();

	if (lSize != rSize && lSize == fmin(lSize, rSize))
	{
		return true;
	}
	if (lSize == rSize)
	{
		for (size_t i = 0; i < lSize; i++)
		{
			//here i use operator< from Egg
			if (left[i] < right[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

bool operator>=(const Basket& left, const Basket& right)
{
	if (left == right)
		return true;
	else
		return !(left <= right);
}
