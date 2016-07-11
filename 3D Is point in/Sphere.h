#pragma once
#include "Shape.h"
#include "Point.h"

class Sphere : public Shape
{
public:
	Sphere();
	Sphere(Point, float);
	void setShape(Point, float);
	void printShape()const;
	bool isIn(Point)const;
	char* isInstance()const;
	Point getCenter()const;
	float getRadius()const;
	~Sphere();
private:
	Point center;
	float radius;
};

