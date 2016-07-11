#include "Pyramid.h"
#include <iostream>
using namespace std;


Pyramid::Pyramid()
{
	
}

Pyramid::Pyramid(Point newFirstPeak, Point newSecondPeak, Point newThirdPeak, Point newFourthPeak)
{
	firstPeak = newFirstPeak;
	secondPeak = newSecondPeak;
	thirdPeak = newThirdPeak;
	fourthPeak = newFirstPeak;
}

void Pyramid::setPyramid(Point newFirstPeak, Point newSecondPeak, Point newThirdPeak, Point newFourthPeak)
{
	firstPeak = newFirstPeak;
	secondPeak = newSecondPeak;
	thirdPeak = newThirdPeak;
	fourthPeak = newFirstPeak;
}


Pyramid::~Pyramid()
{
}


void Pyramid::printShape()const
{
	cout << "Pyramid: firstPeak = ";
	firstPeak.print();
	cout << ", secondPeak = ";
	secondPeak.print();
	cout << ", thirdPeak = ";
	thirdPeak.print();
	cout << ", fourthPeak = ";
	thirdPeak.print();
	cout << endl;
}
float Pyramid::makeEven(float number)const
{
	if (number > 0)
		return number;
	
	number *= -1;
	return number;
}

bool Pyramid::isIn(Point newPoint)const
{

	//TODO with plain and normal vector

	return true;
}
char* Pyramid::isInstance()const
{
	char* str = "Pyramid";
	return str;
} 

Point Pyramid::getFirstPeak()const
{
	return firstPeak;
}
Point Pyramid::getSecondPeak()const
{
	return secondPeak;
}
Point Pyramid::getThirdPeak()const
{
	return thirdPeak;
}
Point Pyramid::getFourthPeak()const
{
	return fourthPeak;
}