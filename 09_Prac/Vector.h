#pragma once
#include "Point.h"
class Vector
{
	Point* points;
	int countPoint;
public:
	Vector();
	Vector(const Vector & other);
	Vector(Vector&& other);
	Vector& operator=(const Vector& other);
	~Vector();
	void PrintVect()const;
	void AddPoint(Point n); 
};

