#pragma once
#include "Point.h"

class Shape
{
public:

	virtual void printShape()const = 0;
	virtual bool isIn(Point)const = 0;
	virtual char* isInstance()const = 0;
	Shape();
	virtual ~Shape();
};

