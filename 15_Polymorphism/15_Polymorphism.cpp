#include <iostream>
#include <windows.h>
using namespace std;

class Car
{
    string model;
    int year;
    float capacity;
protected:
    int speed;
public:
    Car():model("nomodel"),year(0),speed(0),capacity(0){}
    Car(string m, int y, float c):model(m), year(y), speed(0), capacity(c) {}

    void setSpeed(int s)
    {
        if (s>0)
        {
            this->speed = s;
        }
        else
        {
            this->speed = 0;
        }
    }
    virtual void Drive()const
    {
        cout << "I'm a Car. I can drive with speed : " << speed << endl;
    }
    virtual void Print()
    {
        cout << "Model : " << model << endl;
        cout << "Year : " << year << endl;
        cout << "Speed : " << speed << endl;
        cout << "Capacity : " << capacity << endl;
    }
};
class PoliceCar : public Car
{
    float sound_volume;
public:
    PoliceCar() : Car(), sound_volume(0){}
    PoliceCar(string m, int y, float c, int s): Car(m, y, c), sound_volume(s){}
    void Drive()const override
    {
        cout << "I'm a PoliceCar. I can drive with speed : "<< speed << endl;
    }
    void Print() override
    {
        Car::Print();
        cout << "Sound volume : " << sound_volume << endl;
        cout << endl;
    }
    void BeepBeep()
    {
        Beep(500, 300);
        Beep(400, 200);
        Beep(700, 400);
        Beep(500, 300);
    }
};
class SportCar : public Car
{
    float TurboSpeed;
public:
    SportCar() : Car(), TurboSpeed(0) {}
    SportCar(string m, int y, float c, int s) : Car(m, y, c), TurboSpeed(s) {}
    void Drive()const override
    {
        cout << "I'm a SportCar. I can drive with speed : " << speed << endl;
    }
    void Print() override
    {
        Car::Print();
        cout << "Turbo speed : " << TurboSpeed << endl;
        Nitro();
        cout << endl;
    }
    void Nitro()
    {
        speed += TurboSpeed;
        cout << "Nitro : " << speed << endl;
    }
};

void TestDrive(Car &car)
{
    car.setSpeed(70);
    car.Drive();
}
int main()
{
    Car car("BMW", 2025, 3.0);
    car.setSpeed(289);
    car.Drive();
    car.Print(); cout << endl;
    PoliceCar police("Ferrari", 2024, 3.5, 1000);
    police.setSpeed(300);
    police.Drive();
    police.Print();
    //police.BeepBeep();
    SportCar sportcar("Formula 1", 2026, 2.6, 100);
    sportcar.setSpeed(410);
    sportcar.Drive();
    sportcar.Print();

    TestDrive(car);
    TestDrive(police);
    TestDrive(sportcar);

    Car* cars[3]{
        new Car("BMW", 2025, 3.0),
        new PoliceCar("Ferrari", 2024, 3.5, 1000),
        new SportCar("Formula 1", 2026, 2.6, 100)
    };

    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cars[i]->Print();
        delete cars[i];
        cout << endl << endl;
    }
}
