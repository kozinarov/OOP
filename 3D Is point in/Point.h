#pragma once

class Point
{
public:
	Point();
	Point(float, float, float);
	Point& operator=(const Point&);
	void setPoint(float, float, float);
	void print()const;
	float getX()const;
	float getY()const;
	float getZ()const;
	~Point();

private:
	float x;
	float y;
	float z;

};

