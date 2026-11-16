#include <iostream>
#include <windows.h>
using namespace std;

void gotoxy(int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}
struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};
class Shape
{
protected:
    string type;
public:
    Shape() : type("notype") {}
    Shape(string t) :type(t) {}
    virtual void Print()const = 0;
    virtual ~Shape() = 0 {}
};

class Line : public Shape
{
    Point point1;
    Point point2;
public:
    Line() : point1(0, 0), point2(0, 0), Shape() {}
    Line(string type, int x1, int y1, int x2, int y2) :point1(x1, y1), point2(x2, y2), Shape(type) {}
    void Print()const override
    {
        gotoxy(0, 0); cout << type;
        gotoxy(point1.x, point1.y); cout << "*";
        gotoxy(point2.x, point2.y); cout << "*";
    }
};

class Rect : public Shape
{
    Point point1;
    int width;
    int height;
public:
    Rect() : point1(0, 0), width(0), height(0), Shape() {}
    Rect(string type ,int x1, int y1, int wid, int hei) :point1(x1, y1), width(wid), height(hei), Shape(type) {}
    void Print()const override
    {
        gotoxy(0, 0); cout << type;
        for (int i = 0; i < height; i++)
        {
            gotoxy(point1.x, point1.y + i);
            for (int i = 0; i < width; i++)
            {   
                cout << "*";
            }
        }
        
    }
};
class polyline : public Shape
{
    Point* points;
    int pointsCount;
public:
    polyline(): points(nullptr), pointsCount(0), Shape(){}
    polyline(string type, int count):pointsCount(count), Shape(type)
    {
        this->points = new Point[pointsCount];
        for (int i = 0; i < pointsCount; i++)
        {
            points[i].x = rand() % 29 + 2;
            points[i].y = rand() % 19 + 2;
        }
    }
    void Print()const override
    {
        gotoxy(0, 0); cout << type;
        for (int i = 0; i < pointsCount; i++)
        {
            gotoxy(points[i].x, points[i].y); cout << "*";
        }
    }
    ~polyline()
    {
        if (points != nullptr) { delete[] points; }
    }
};
int main()
{
    srand(time(0));
    /*Line l("Line", 1, 5, 17, 8);
    l.Print();*/

    /*Rect  r("Rectangle", 7, 3, 10, 3);
    r.Print();*/

    polyline p("Polyline", 10);
    p.Print();
}

