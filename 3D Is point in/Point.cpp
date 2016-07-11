#include "Point.h"
#include <iostream>
using namespace std;


Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}

Point::Point(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}

void Point::setPoint(float newX, float newY, float newZ)
{
	x = newX;
	y = newY;
	z = newZ;
}
Point& Point::operator=(const Point& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}
	return *this;
}

Point::~Point()
{

}

void Point::print()const
{
	cout << "( "<< x << " " << y << " " << z << " )";
}
float Point::getX()const
{
	return x;
}

float Point::getY()const
{
	return y;
}

float Point::getZ()const
{
	return z;
}
