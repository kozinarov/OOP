#pragma once
#include "Shape.h"
#include "Sphere.h"
#include "Pyramid.h"
#include "Cuboid.h"
class Group : public Shape
{
public:
	Group();
	Group(const Group&);
	Group& operator=(const Group&);
	~Group();

	void printShape()const;
	bool isIn(Point)const;
	char* isInstance()const;
	
	void setVector(Point);
	void setScalar(float);

	void addSphere(const Sphere&);
	void addPyramid(const Pyramid&);
	void addCuboid(const Cuboid&);

	void clear();

	size_t getSize();
	size_t getCap();
private:
	Point scaling(Point);
	Point translation(Point);

private:
	void copy(const Group&);
	
	void resize();

private:
	
	Point vector;
	float scalar;
	Shape **group;
	size_t size;
	size_t cap;
	
};

