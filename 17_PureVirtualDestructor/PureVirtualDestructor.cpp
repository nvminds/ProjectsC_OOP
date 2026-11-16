#include <iostream>
using namespace std;

class Person
{
    string name;
public:
    Person() : name("noname"){}
    Person(string name) : name(name) {}
    virtual void Print()const
    {
        cout << "Name : " << name << endl;
        cout << endl;
    }
    virtual ~Person() = 0 {}
};
class Aspirant : public Person
{
    string* subject;
    int countSubjects;
public:
    Aspirant() :Person(), subject(nullptr), countSubjects(0) {}
    Aspirant(string name, initializer_list<string> list) :Person(name)
    {
        this->countSubjects = list.size();
        subject = new string[countSubjects];
        int i = 0;
        for (string sub : list)
        {
            subject[i] = sub;
            i++;
        }
    }
    void Print()const override
    {
        Person::Print();
        cout << "Subject : ";
        for (int i = 0; i < countSubjects; i++)
        {
            cout << subject[i] << " ";
        }cout << endl;cout << endl;
    }
    ~Aspirant()
    {
        if (subject != nullptr) { delete[]subject; }
    }
};

int main()
{
    srand(time(0));

    //Person s("Vasya");
    /*s.Print();
    cout << endl;*/

    Aspirant as("Ivan", { "Ukrainian revolution", "UNR", "World War 2" });
    as.Print();
    cout << endl;

    cout << "---------------------------------------" << endl;

    Person* group[3]
    {
        //new Person("Lola"),
        new Aspirant("Petro", { "Ukrainian revolution", "UNR", "World War 2" }),
        new Aspirant("Volodya", {"Water", "Oil", "Gasoline"}),
    };

    for (int i = 0; i < 2; i++)
    {
        group[i]->Print();
        delete group[i];
    }
}
