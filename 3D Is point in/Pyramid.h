#pragma once
#include "Shape.h"
class Pyramid : public Shape
{
public:
	Pyramid();
	Pyramid(Point, Point, Point, Point);
	void setPyramid(Point, Point, Point, Point);
	void printShape()const;
	bool isIn(Point)const;
	char* isInstance()const;
		
	~Pyramid();

	Point getFirstPeak()const;
	Point getSecondPeak()const;
	Point getThirdPeak()const;
	Point getFourthPeak()const;

private:
	float makeEven(float)const;
private:
	Point firstPeak;
	Point secondPeak;
	Point thirdPeak;
	Point fourthPeak;
};

