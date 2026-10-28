#pragma once
#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point();
    explicit Point(int value);
    Point(int x, int y);
    void Print()const;
#pragma region Математичні оператори
    Point operator +(const Point& other)const;
    Point operator -(const Point& other)const;
    Point operator *(const Point& other);
    Point operator /(const Point& other);
#pragma endregion

#pragma region Binary Operators
    Point operator+=(const Point& other);
    Point operator=(const Point& other);

#pragma endregion

#pragma region Uno Operators
    Point operator -();
    Point operator --();
    Point operator ++(int);
    Point operator --(int);
    Point operator!();
#pragma endregion

#pragma region Logic Operators < ? > <= >= ! == !=
    bool operator>(const Point& other)const;
    bool operator<(const Point& other)const;
    bool operator>=(const Point& other)const;
    bool operator==(const Point& other)const;
    bool operator!=(const Point& other)const;
#pragma endregion

    void setX(int newX) { this->x = newX; }
    void setY(int newY) { this->y = newY; }
    int getX()const { return x; }
    int getY()const { return y; }

    friend Point operator ++(Point& point);
    friend ostream& operator<<(ostream& out, const Point& point);
    friend istream& operator>>(istream& in, Point& point);

    void Print();
};


