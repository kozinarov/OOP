#pragma once
#include "Shape.h"
class Cuboid : public Shape
{
public:
	Cuboid();
	Cuboid(Point, Point);
	void setCuboid(Point, Point);
	void printShape()const;
	bool isIn(Point)const;
	char* isInstance()const;

	Point getFrontDownLeftPeak()const;
	Point getBehindUpRightPeak()const;

	~Cuboid();
private:
	Point frontDownRightPeak;
	Point frontDownLeftPeak;
	Point frontUpRightPeak;
	Point frontUPleftPeak;

	Point behindDownRightPeak;
	Point behindDownLeftPeak;
	Point behindUpRightPeak;
	Point behindUPleftPeak;
};

