#include "Point.h"
#include "Vector.h"

int main()
{
    Point p(3,5);
    Point p2(6,5);
    Point p3(3,4);
    Point p4(6,7);
    Vector vect;
    vect.AddPoint(p);
    vect.AddPoint(p2);
    vect.AddPoint(p3);
    vect.AddPoint(p4);
    vect.PrintVect();

}

#pragma region global funcs
bool operator<=(const Point& left, const Point& right)
{
    return ((left.getX() + left.getY()) <= (right.getX() + right.getY()));
}
ostream& operator<<(ostream& out, const Point& point)
{
    out << "X : [" << point.x << "]   " << " Y : [" << point.y << "]";
    return out;
}
istream& operator>>(istream& in, Point& point)
{
    in >> point.x;
    in >> point.y;
    return in;
}
Point operator ++(Point& point)
{
    point.x++;
    point.y++;
    return point;
}
#pragma endregion


