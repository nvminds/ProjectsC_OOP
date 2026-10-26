#include <iostream>
using namespace std;

class Airplane
{
    string model;
    string type;
    int count_passagers;
    int max_passagers;
public:
#pragma region Constructors
    Airplane()
    {
        model = "no model";
        type = "no type";
        count_passagers = 0;
        max_passagers = 0;
    }
    Airplane(string model, string type, int count_passagers, int max_passagers) :Airplane()
    {
        this->model = model;
        this->type = type;
        this->count_passagers = count_passagers;
        this->max_passagers = max_passagers;
    }
#pragma endregion

    void Print()const
    {
        cout << "Model : " << model << endl;
        cout << "Type : " << type << endl;
        cout << "Count passagers : " << count_passagers << endl;
        cout << "Max passagers : " << max_passagers << endl;
        cout << endl;
    }
    friend bool operator==(const Airplane& left, const Airplane& right);
    friend bool operator>(const Airplane& left, const Airplane& right);
    Airplane operator++()
    {
        ++this->count_passagers;
        if (count_passagers<=max_passagers){ return *this; }
    }
    Airplane operator++(int)
    {
        this->count_passagers++;
        if (count_passagers <= max_passagers) { return *this; } 
    }
    Airplane operator--()
    {
        --this->count_passagers;
        if (count_passagers <= max_passagers) { return *this; }
    }
    Airplane operator--(int)
    {
        this->count_passagers--;
        if (count_passagers <= max_passagers) { return *this; }
    }
    Airplane operator()(int num)
    {
        this->count_passagers += num;
        if (count_passagers <= max_passagers) { return *this; }
    }
};
bool operator==(const Airplane& left, const Airplane& right)
{
    if (left.type == right.type) { return true; }
    else { return false; }
}
bool operator>(const Airplane& left, const Airplane& right)
{
    if (left.max_passagers > right.max_passagers) { return true; }
    else { return false; }
}
int main()
{
    Airplane plane1("ATR 72-600", "Narrow-body Jet Airliner", 45, 78);
    Airplane plane2("Boeing 737 MAX 8", "Narrow-body Jet Airliner", 162, 210);
    Airplane plane3("Airbus A350-1000", "Wide-body Long-range Jetliner", 320, 480);
    plane1.Print();
    plane2.Print();
    plane3.Print();

    if (plane1 == plane2) { cout << "Types of airplane 1 and airplane 2 are match." << endl; }
    else{ { cout << "Types of airplane 1 and airplane 2 are not match." << endl; } }

    if (plane2 == plane3) { cout << "Types of airplane 2 and airplane 3 are match." << endl; }
    else{ { cout << "Types of airplane 2 and airplane 3 are not match." << endl; } }

    cout << endl;

    plane1.Print();
    plane1++;
    plane1.Print();
    ++plane1;
    plane1.Print();
    plane1--;
    plane1.Print();

    if (plane1 > plane2) { cout << "Plane 1 can accommodate more passagers than plane 2." << endl; }
    else { { cout << "Plane 2 can accommodate more passagers than plane 1." << endl; } }

    plane1.Print();
    plane1(32);
    //plane1(33);error
    plane1.Print();
    
}

