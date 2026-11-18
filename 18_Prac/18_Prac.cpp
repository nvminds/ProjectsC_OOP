#include <iostream>
using namespace std;

enum BodyType { NONE1, Sedan, Hatchback, Coupe, Convertible};
enum LightType { NONE2, Yellow, White };
enum EngineType { NONE3, V6, V8, V10, V12 };
class Body{
    BodyType bodyType;
public:
    Body():bodyType(NONE1){}
    Body(BodyType t):bodyType(t){}
    void PrintBody()const{
        cout << "Body type : ";
        switch (bodyType)
        {
        case NONE1: cout << " None " << endl; break;
        case Sedan: cout << " Sedan " << endl; break;
        case Hatchback: cout << " Hatchback " << endl; break;
        case Coupe: cout << " Coupe " << endl; break;
        case Convertible: cout << " Convertible " << endl; break;
        }
    }
};
class Wheel{
    float wheelRadius;
public:
    Wheel():wheelRadius(0) {}
    Wheel(float r) :wheelRadius(r) {}
    void PrintWheel()const {
        cout << "   " << wheelRadius << " radius of wheel ";
    }
};
class Engine{
    EngineType engineType;
public:
    Engine():engineType(NONE3) {}
    Engine(EngineType t):engineType(t) {}
    void PrintEngine()const {
        cout << "Engine type : ";
        switch (engineType)
        {
        case NONE3: cout << " None " << endl; break;
        case V6: cout << " V6 " << endl; break;
        case V8: cout << " V8 " << endl; break;
        case V10: cout << " V10 " << endl; break;
        case V12: cout << " V12 " << endl; break;
        }
    }
};
class Door{
    bool isOpen;
public:
    Door(): isOpen(false) {}
    Door(bool b): isOpen(b) {}
    void PrintDoor()const{
        if (isOpen==false){
            cout << "Door is closed." << endl;
        }
        else {
            cout << "Door is opened." << endl;
        }
    }
};
class Headlight{
    LightType color;
public:
    Headlight():color(NONE2){}
    Headlight(LightType c):color(c){}
    void PrintLight()const {
        cout << "Headlights color : ";
        switch (color)
        {
        case NONE2: cout << " None " << endl; break;
        case Yellow: cout << " Yellow " << endl; break;
        case White: cout << " White " << endl; break;
        }
    }
};
class Driver{
    bool drunk;
public:
    Driver() : drunk(false) {}
    Driver(bool d) : drunk(d) {}
    void PrintDriver()const {
        if(drunk==true) {
            cout << "The driver is drunk." << endl;
        }
        else {
            cout << "The driver is sober." << endl;
        }
    }
};
class Car{
    Body body;
    Wheel* wheels;
    int countWheels;
    Engine engine;
    Door doors;
    Headlight headlights;
    Driver* driver;
public:
    Car():body(NONE1), wheels(nullptr), countWheels(0), engine(NONE3), doors(false), headlights(NONE2), driver(nullptr) {}
    Car(Body b, int countWheels, Wheel radius, Engine engineType, Door doorsStatus, Headlight color)
       :body(b), countWheels(countWheels), engine(engineType), doors(doorsStatus), headlights(color), driver(nullptr) {
        wheels = new Wheel[countWheels];
        for (int i = 0; i < countWheels; i++)
        {
            wheels[i] = radius;
        }
    }
    ~Car() { if (wheels != nullptr) { delete[]wheels; } }
    void PrintBody()const {
        body.PrintBody();
    }
    void PrintWheels()const{
        cout << "Count of wheels : " << countWheels << endl;
        for (int i = 0; i < countWheels; i++)
        {
            wheels[i].PrintWheel(); cout << i + 1 << endl;
        }
    }
    void PrintEngine()const {
        engine.PrintEngine();
    }
    void PrintDoor()const {
        doors.PrintDoor();
    }
    void PrintHeadlight()const {
        headlights.PrintLight();
    }
    void PrintDriver()const {
        if (driver!=nullptr){ driver->PrintDriver(); }
        else { cout << "Driver is no exists." << endl; }
    }
    void AggregateDriver(Driver* d) {
        this->driver = d;
    }
    void RemoveDriver(){
        this->driver = nullptr;
    }
};

int main()
{
    Car car(BodyType::Sedan, 4, 16, EngineType::V8, false, LightType::White);
    Driver driver(false);
    car.PrintBody();
    car.PrintWheels();
    car.PrintEngine();
    car.PrintDoor();
    car.PrintHeadlight();
    car.PrintDriver();
    car.AggregateDriver(&driver);
    car.PrintDriver();
    car.RemoveDriver();
    car.PrintDriver();
}
