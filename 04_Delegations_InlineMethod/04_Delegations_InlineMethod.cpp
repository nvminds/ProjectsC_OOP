#include <iostream>
using namespace std;
#define Pi 3.14;

inline void Hello()
{
    cout << "Hello" << endl;
}
class Human
{
    string name;
    int age;
    float weight;
public:
    static int count_humans;
    //Human() // ініціалізація з копіюванням
    //{
    //    name = "no name";
    //    age = 0;
    //    weight = 0;
    //}

    //список ініціалізаторів
    //Human() :name{"no name"}, age{ 0 }, weight{ 0 } // уніфікована ініціалізація
    Human() :name("no name"), age(0), weight(0) { count_humans++; } // пряма ініціалізація
    Human(string name): Human()
    {
        this->name = name;
        //age = 0;
        //weight = 0;
    }
    Human(string name, int age): Human(name)
    {
        //this->name = name;
        this->age = age;
        //weight = 0;
    }
    Human(string name, int age, float weight) : Human(name, age)
    {
        //this->name = name;
        //this->age = age;
        this->weight = weight;
    }


    void Print() 
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Weight : " << weight << endl;
        cout << endl;
    }
};

int Human::count_humans = 0;
int main()
{
    cout << "Count humans : " << Human::count_humans << endl;
    Human h1;
    h1.Print();
    cout << "Count humans : " << h1.count_humans << endl;
    
    Human h2("Kolya");
    h2.Print();
    cout << "Count humans : " << h2.count_humans << endl;
    
    Human h3("Kolya", 17);
    h3.Print();
    cout << "Count humans : " << h3.count_humans << endl;
 
    Human h4("Kolya", 17, 78);
    h4.Print();
    cout << "Count humans : " << h4.count_humans << endl;

    cout << "Count humans : " << Human::count_humans << endl;




    // cout << "Hello" << endl; //Hello();
    // cout << 3.14; // cout << Pi;

}
