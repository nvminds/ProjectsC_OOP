#include "Vector.h"

Vector::Vector()
{
	points = nullptr;
	countPoint = 0;
}

Vector::Vector(const Vector& other)
{
	this->countPoint = other.countPoint;
	this->points = new Point[countPoint];
	for (int i = 0; i < countPoint; i++)
	{
		this->points[i] = other.points[i]; 
	}
}

Vector::Vector(Vector&& other)
{
	this->countPoint = other.countPoint;
	this->points = other.points;
	other.points = nullptr;
	other.countPoint = 0;
}

Vector& Vector::operator=(const Vector& other)
{
	this->countPoint = other.countPoint;
	if (points != nullptr) { delete[]points; }
	this->points = new Point[countPoint];
	for (int i = 0; i < countPoint; i++)
	{
		this->points[i] = other.points[i];
	}
	return *this;
}

Vector::~Vector()
{
	if (points != nullptr) { delete[]points; }
}

void Vector::PrintVect() const
{
	cout << "Points count : " << countPoint << endl;
	for (int i = 0; i < countPoint; i++)
	{
		cout << "Point " << i + 1 << " : " << (points[i]) << endl;
	}
}

void Vector::AddPoint(Point n)
{
	Point* temp = new Point[countPoint + 1];
	for (int i = 0; i < countPoint; i++)
	{
		temp[i] = points[i];
	}
	temp[countPoint] = n;
	if (points != nullptr) { delete[]points; }
	countPoint++;
	points = temp;
}
