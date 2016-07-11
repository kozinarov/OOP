#pragma once
#ifndef __Soldier_HEADER__
#define __Soldier_HEADER__

class Soldier
{
public:
	Soldier();
	Soldier(const char*, const int, const int, const int);
	Soldier(const Soldier&);
	Soldier& operator=(const Soldier&);
	~Soldier();

public:
	void setName(const char*);
	void setAge(const int);
	void setStrenght(const int);
	void setSalary(const int);

	char* getName()const;
	int getAge()const;
	int getStrenght()const;
	int getSalary()const;

private:
	void free();
	void copy(const Soldier&);

private:
	char* name;
	int age;
	int strenght;
	int salary;
};

#endif //__Soldier_HEADER__