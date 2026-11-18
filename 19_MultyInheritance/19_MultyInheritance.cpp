#include <iostream>
using namespace std;

class Car {
public:
    void Drive() {
        cout << "I drive." << endl;
    }
    void Use() {
        cout << "I drive." << endl;
    } 
};
class Airplane { 
public:
    void Fly() {
        cout << "I fly." << endl;
    }
    void Use() {
        cout << "I fly." << endl;
    }
};
class FlyCar: public Car, public Airplane {};

int main()
{
    FlyCar car;
    car.Drive();
    car.Fly();
    ((Car)car).Use();
    ((Airplane)car).Use();
}