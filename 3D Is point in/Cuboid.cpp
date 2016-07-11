#include "Cuboid.h"
#include <iostream>
using namespace std;


Cuboid::Cuboid()
{
}

Cuboid::Cuboid(Point newFrontDownLeftPeak, Point newBehindUpRightPeak)
{
	frontDownLeftPeak = newFrontDownLeftPeak;
	behindUpRightPeak = newBehindUpRightPeak;
	float length = behindUpRightPeak.getX() - frontDownLeftPeak.getX();
	float height = behindUpRightPeak.getY() - frontDownLeftPeak.getY();
	float width = behindUpRightPeak.getZ() - frontDownLeftPeak.getZ();

	frontDownRightPeak.setPoint(frontDownLeftPeak.getX() + length, frontDownLeftPeak.getY(), frontDownLeftPeak.getZ());
	frontUPleftPeak.setPoint(frontDownLeftPeak.getX(), frontDownLeftPeak.getY() + height, frontDownLeftPeak.getZ());
	behindDownLeftPeak.setPoint(frontDownLeftPeak.getX(), frontDownLeftPeak.getY(), frontDownLeftPeak.getZ() + width);

	behindUPleftPeak.setPoint(behindUpRightPeak.getX() - length, behindUpRightPeak.getY(), behindUpRightPeak.getZ());
	behindDownRightPeak.setPoint(behindUpRightPeak.getX(), behindUpRightPeak.getY() - height, behindUpRightPeak.getZ());
	frontUpRightPeak.setPoint(behindUpRightPeak.getX(), behindUpRightPeak.getY(), behindUpRightPeak.getZ() - width);
}

void Cuboid::setCuboid(Point newFrontDownLeftPeak, Point newBehindUpRightPeak)
{
	frontDownLeftPeak = newFrontDownLeftPeak;
	behindUpRightPeak = newBehindUpRightPeak;
	float length = behindUpRightPeak.getX() - frontDownLeftPeak.getX();
	float height = behindUpRightPeak.getY() - frontDownLeftPeak.getY();
	float width = behindUpRightPeak.getZ() - frontDownLeftPeak.getZ();
	
	frontDownRightPeak.setPoint(frontDownLeftPeak.getX() + length, frontDownLeftPeak.getY(), frontDownLeftPeak.getZ());
	frontUPleftPeak.setPoint(frontDownLeftPeak.getX(), frontDownLeftPeak.getY() + height, frontDownLeftPeak.getZ());
	behindDownLeftPeak.setPoint(frontDownLeftPeak.getX(), frontDownLeftPeak.getY(), frontDownLeftPeak.getZ() + width);

	behindUPleftPeak.setPoint(behindUpRightPeak.getX() - length, behindUpRightPeak.getY(), behindUpRightPeak.getZ());
	behindDownRightPeak.setPoint(behindUpRightPeak.getX(), behindUpRightPeak.getY() - height, behindUpRightPeak.getZ());
	frontUpRightPeak.setPoint(behindUpRightPeak.getX(), behindUpRightPeak.getY(), behindUpRightPeak.getZ() - width);
}

Cuboid::~Cuboid()
{
}

void Cuboid::printShape()const
{
	cout << "Cuboid: ";

	cout << "frontDownRightPeak = ";
	frontDownRightPeak.print();
	cout << ", frontDownLeftPeak = ";
	frontDownLeftPeak.print();
	cout << ", frontUpRightPeak = ";
	frontUpRightPeak.print();
	cout << ", frontUPleftPeak = ";
	frontUPleftPeak.print();

	cout << ", behindDownRightPeak = ";
	behindDownRightPeak.print();
	cout << ", behindDownLeftPeak = ";
	behindDownLeftPeak.print();
	cout << ", behindUpRightPeak = ";
	behindUpRightPeak.print();
	cout << ", behindUPleftPeak = ";
	behindUPleftPeak.print();
	cout << endl;

}

bool Cuboid::isIn(Point newPoint)const
{
	if (frontDownLeftPeak.getX() < newPoint.getX() && frontDownLeftPeak.getY() < newPoint.getY() && frontDownLeftPeak.getZ() < newPoint.getZ() &&
		behindUpRightPeak.getX() > newPoint.getX() && behindUpRightPeak.getY() > newPoint.getY() && behindUpRightPeak.getZ() > newPoint.getZ())
	{
		return true;
	}
	else if (frontDownLeftPeak.getX() > newPoint.getX() && frontDownLeftPeak.getY() > newPoint.getY() && frontDownLeftPeak.getZ() > newPoint.getZ() &&
		behindUpRightPeak.getX() < newPoint.getX() && behindUpRightPeak.getY() < newPoint.getY() && behindUpRightPeak.getZ() < newPoint.getZ())
	{
		return true;
	}
	return false;
}

char* Cuboid::isInstance()const
{
	char* str = "Cuboid";
	return str;
}

Point Cuboid::getFrontDownLeftPeak()const
{
	return frontDownLeftPeak;
}
Point Cuboid::getBehindUpRightPeak()const
{
	return behindUpRightPeak;
}