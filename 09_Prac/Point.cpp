#include "Point.h"

Point::Point()
{
    x = y = 0;
}

Point::Point(int value)
{
    this->x = value;
    this->y = value;
} 

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::Print() const
{
    cout << "X : " << x << endl;
    cout << "Y : " << y << endl;
    cout << endl;
}

Point Point::operator+(const Point& other) const
{
    Point res(this->x + other.x, this->y + other.y);
    return res;
}

Point Point::operator-(const Point& other) const
{
    Point res(this->x - other.x, this->y - other.y);
    return res;
}

Point Point::operator*(const Point& other)
{
    Point res(this->x * other.x, this->y * other.y);
    return res;
}

Point Point::operator/(const Point& other)
{
    Point res(this->x / other.x, this->y / other.y);
    return res;
}

Point Point::operator+=(const Point& other)
{
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Point Point::operator=(const Point& other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}

Point Point::operator-()
{
    return Point(this->x * -1, this->y * -1);
}

Point Point::operator--()
{
    --this->x;
    --this->y;
    return *this;
}

Point Point::operator++(int)
{
    this->x++;
    this->y++;
    return *this;
}

Point Point::operator--(int)
{
    this->x--;
    this->y--;
    return *this;
}

Point Point::operator!()
{
    this->x = -x;
    this->y = -y;
    return *this;
}

bool Point::operator>(const Point& other) const
{
    return ((this->x + this->y) > (other.x + other.y));
}

bool Point::operator<(const Point& other)const
{
    return ((this->x + this->y) < (other.x + other.y));
}

bool Point::operator>=(const Point& other) const
{
    return ((this->x + this->y) >= (other.x + other.y));
}

bool Point::operator==(const Point& other) const
{
    return ((this->x == other.x) and (this->y == other.y));
}

bool Point::operator!=(const Point& other) const
{

    return !(*this == other);
}

void Point::Print()
{
    cout << "X cord : " << x << endl;
    cout << "Y cord : " << y << endl;
}
