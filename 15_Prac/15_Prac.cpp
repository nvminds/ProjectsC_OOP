#include <iostream>
using namespace std;

class Shape
{
    string name;
    string type;
public:
    Shape(): name("noname"), type("notype"){}
    Shape(string n, string t) : name(n), type(t) {}
    virtual void Show()const
    {
        cout << "Name : " << name << endl;
        cout << "Type : " << type << endl;
    }
    virtual float GetArea()const = 0;
};

class Rectangle : public Shape
{
    float a;
    float b;
public:
    Rectangle(): Shape(), a(0), b(0){}
    Rectangle(string n, string t, float a, float b): Shape(n,t), a(a), b(b){}
    float GetArea()const override
    {
        return a * b;
    }
    void Show()const override
    {
        Shape::Show();
        float area = GetArea();
        cout << "Side A : " << a << endl;
        cout << "Side B : " << b << endl;
        cout << "Area : " << area << endl;
        cout << endl;
    }
};

class Triangle : public Shape
{
    float a;
    float h;
public:
    Triangle() : Shape(), a(0), h(0) {}
    Triangle(string n, string t, float a, float h) : Shape(n, t), a(a), h(h) {}
    float GetArea()const override
    {
        return (a * h) / 2;
    }
    void Show()const override
    {
        Shape::Show();
        float area = GetArea();
        cout << "Basis side A : " << a << endl;
        cout << "Height H : " << h << endl;
        cout << "Area : " << area << endl;
        cout << endl;
    }
};

class Circle : public Shape 
{
    const float Pi = 3.14;
    float R;
public:
    Circle() : Shape(), R(0) {}
    Circle(string n, string t, float r) : Shape(n, t), R(r) {}
    float GetArea()const override
    {
        return (R * R) * Pi;
    }
    void Show()const override
    {
        Shape::Show();
        float area = GetArea();
        cout << "Pi : " << Pi << endl;
        cout << "Radius : " << R << endl;
        cout << "Area : " << area << endl;
        cout << endl;
    }
};

class Trapeze : public Shape 
{
    float a;
    float b;
    float h;
public:
    Trapeze() : Shape(), a(0), h(0) {}
    Trapeze(string n, string t, float a,float b, float h) : Shape(n, t), a(a), b(b), h(h) {}
    float GetArea()const override
    {
        return ((a + b) / 2) * h;
    }
    void Show()const override
    {
        Shape::Show();
        float area = GetArea();
        cout << "Basis side A : " << a << endl;
        cout << "Basis side B : " << b << endl;
        cout << "Height H : " << h << endl;
        cout << "Area : " << area << endl;
        cout << endl;
    }
};

void TestShape(Shape& s)
{
    s.Show();
    s.GetArea();
}
int main()
{
    Rectangle rect("Rectangle", "Parallelogram", 5, 4);
    Triangle trig("Triangle", "Scalene", 15, 10);
    Circle circ("Circle", "Round", 11);
    Trapeze trap("Trapeze", "Isosceles", 10, 20, 15);

    TestShape(rect);
    TestShape(trig);
    TestShape(circ);
    TestShape(trap);
}

