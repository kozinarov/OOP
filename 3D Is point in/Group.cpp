#include "Group.h"
#include <iostream>
using namespace std;
#include "Sphere.h"
#include "Pyramid.h"
#include "Cuboid.h"


Group::Group() : group(NULL), size(0), cap(1), scalar(1)
{
	group = new Shape*[1];
}

Group::Group(const Group& other)
{
	copy(other);
}

Group& Group::operator=(const Group& other)
{
	if (this != &other)
	{
		clear();
		copy(other);
	}

	return *this;
}

void Group::clear()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] group[i];
	}
	delete[] group;
	size = 0;
	cap = 1;
	vector.setPoint(0, 0, 0);
	scalar = 1;
}

void Group::copy(const Group& other)
{	
	
	group = new Shape*[other.cap];
	for (size_t i = 0; i < other.size; i++)
	{	
		group[i] = other.group[i];
	}
	size = other.size;
	cap = other.cap;
	vector = other.vector;
	scalar = other.scalar;
}

Group::~Group()
{
	for (size_t i = 0; i < size; i++)
	{
		delete[] group[i];
	}
	delete[] group;
}


void Group::addSphere(const Sphere& newSphere)
{	
	float radius = newSphere.getRadius() * scalar;
	Point translatedPoint = translation(newSphere.getCenter());
	group[size] = new Sphere(translatedPoint, radius);
	size++;
	resize();
}

void Group::addPyramid(const Pyramid& newPyramid)
{
	Point newFirstPeak = translation(scaling(newPyramid.getFirstPeak()));
	Point newSecondPeak = translation(scaling(newPyramid.getSecondPeak()));
	Point newThirdPeak = translation(scaling(newPyramid.getThirdPeak()));
	Point newFourthPeak = translation(scaling(newPyramid.getFourthPeak()));
	group[size] = new Pyramid(newFirstPeak, newSecondPeak, newThirdPeak, newFourthPeak);
	size++;
	resize();
}

void Group::addCuboid(const Cuboid& newCuboid)
{
	Point newFrontDownLeftPeak = translation(scaling(newCuboid.getFrontDownLeftPeak()));
	Point newBehindUpRightPeak = translation(scaling(newCuboid.getBehindUpRightPeak()));
	group[size] = new Cuboid(newFrontDownLeftPeak, newBehindUpRightPeak);
	size++;
	resize();
}

Point Group::scaling(Point forScal)
{	
	Point scaled;
	scaled.setPoint(forScal.getX() * scalar, forScal.getY() * scalar, forScal.getZ() * scalar);
	return scaled;
}

Point Group::translation(Point forTransl)
{
	Point translated;
	translated.setPoint(forTransl.getX() + vector.getX(), forTransl.getY() + vector.getY(), forTransl.getZ() + vector.getZ());
	return translated;
}
void Group::resize()
{
	size_t newCap;

	if (size >= cap)
	{
		newCap = size * 2;
	}
	else
		return;
	
	Shape ** newGroup = new Shape*[newCap];
	for (size_t i = 0; i < size; i++)
	{
		newGroup[i] = group[i];
	}
	cap = newCap;
	for (size_t i = 0; i < size; i++)
	{
		delete[] group[i];
	}
	delete[] group;
	group = newGroup;
	
}


void Group::printShape()const
{	
	cout << "Group: " << endl;
	for (size_t i = 0; i < size; i++)
	{
		group[i]->printShape();
	}
	cout << endl;
}

bool Group::isIn(Point newPoint)const
{
	for (size_t i = 0; i < size; i++)
	{
		if (group[i]->isIn(newPoint) == true)
		{
			return true;
		}
	}
	return false;
}
char* Group::isInstance()const
{
	char* str = "Group";
	return str;
}

void Group::setVector(Point newVector)
{
	vector = newVector;
}

void Group::setScalar(float newScalar)
{
	scalar = newScalar;
}


size_t Group::getSize()
{
	return size;
}

size_t Group::getCap()
{
	return cap;
}
