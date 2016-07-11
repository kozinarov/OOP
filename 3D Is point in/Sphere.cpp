#include "Sphere.h"
#include <iostream>
using namespace std;


Sphere::Sphere()
{
	
	radius = 0;
}

Sphere::Sphere(Point newPoint, float rad)
{
	center = newPoint;
	radius = rad;
}

void Sphere::setShape(Point newPoint, float rad)
{
	center = newPoint;

	radius = rad;

}

void Sphere::printShape()const
{

	cout << "Sphere: ";
	center.print();
	cout << ", radius = " << radius << endl;
}

bool Sphere::isIn(Point newPoint)const
{
	float calc = pow((newPoint.getX() - center.getX()), 2) + pow((newPoint.getY() - center.getY()), 2) + pow((newPoint.getZ() - center.getZ()), 2);
	if (calc < pow(radius, 2))
		return true;
	return false;
}

char* Sphere::isInstance()const
{
	char* str = "Sphere";
	return str;
}

Sphere::~Sphere()
{
}

Point Sphere::getCenter()const
{
	return center;
}

float Sphere::getRadius()const
{
	return radius;
}