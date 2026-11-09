#include <iostream>
using namespace std;

struct PIB
{
    string name;
    string surname;
    string lastname;
};
struct Date
{
    int day;
    int month;
    int year;
};

class Student
{
    PIB pib;
    Date birthdate;
public:
    Student() : pib({ "noname", "nosurname", "nolastname" }), birthdate({ 0,0,0 }){} 
    Student(PIB p, Date d)
    {
        this->pib.name = p.name;
        this->pib.surname = p.surname;
        this->pib.lastname = p.lastname;
        this->birthdate.day = d.day;
        this->birthdate.month = d.month;
        this->birthdate.year = d.year;
    }
    void Print()const
    {
        cout << "Student Info :   " << pib.name << " " << pib.surname << " " << pib.lastname
        << "   " << birthdate.day << "/" << birthdate.month << "/" << birthdate.year << endl;
    }
};

class Aspirant : public Student
{
    string project_theme;
    int pages;
public: 
    Aspirant(): project_theme("notheme"), pages(0), Student() {}
    Aspirant(PIB pib, Date d, string th, int p) : project_theme(th), pages(p), Student(pib, d) {}
    int WriteDesertation(int plus_pages)
    {
        pages += plus_pages;
        return pages;
    }
    void Print()const
    {
        cout << "-----------------Student Desertation Protect-----------------" << endl;
        Student::Print();
        cout << "Desertation theme : " << project_theme << endl;
        cout << "Desertation pages count : " << pages << endl;
    }
};

int main()
{
    Aspirant s({"Oleg","Kravchuk","Borysovych"},{20,10,2010}, "The Impact of Remote Work on Team Trust.",80);
    s.Print();
    cout << endl;
    s.WriteDesertation(20);
    s.Print();


}
