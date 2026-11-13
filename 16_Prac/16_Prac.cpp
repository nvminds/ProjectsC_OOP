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

class Employer
{
protected:
    PIB Pib;
    Date employ_date;
public:
    Employer(): Pib({"noname", "nosurname", "nolastname"}), employ_date({0,0,0}) {}
    Employer(string name, string surname, string lastname, int day, int month, int year)
        : Pib({ name, surname, lastname }), employ_date({day,month,year}) {}
    virtual void Print() = 0;
};

class President : Employer
{
    int contracts_signed;
public:
    President() : Employer(), contracts_signed(0) {}
    President(string name, string surname, string lastname, int day, int month, int year, int bugs)
        : Employer(name, surname, lastname, day, month, year), contracts_signed(bugs) {
    }
    void Print()override
    {
        cout << "----------PRESIDENT-----------------------------" << endl;
        cout << "Personal Info : " << Pib.name << " " << Pib.surname << " " << Pib.lastname << endl;
        cout << "Date of employment : " << employ_date.day << "/" << employ_date.month << "/" << employ_date.year << endl;
        cout << "Contracts signed last month : " << contracts_signed << endl;
        cout << endl;
    }
};
class Manager : Employer
{
    int meetings_held;
public:
    Manager() : Employer(), meetings_held(0) {}
    Manager(string name, string surname, string lastname, int day, int month, int year, int bugs)
        : Employer(name, surname, lastname, day, month, year), meetings_held(bugs) {
    }
    void Print()override
    {
        cout << "----------MANAGER-----------------------" << endl;
        cout << "Personal Info : " << Pib.name << " " << Pib.surname << " " << Pib.lastname << endl;
        cout << "Date of employment : " << employ_date.day << "/" << employ_date.month << "/" << employ_date.year << endl;
        cout << "Bugs fixed last week : " << meetings_held << endl;
        cout << endl;
    }
};
class Worker : Employer
{
    int bugs_fixed;
public:
    Worker(): Employer(), bugs_fixed(0){}
    Worker(string name, string surname, string lastname, int day, int month, int year, int bugs)
        : Employer(name, surname, lastname, day, month, year), bugs_fixed(bugs){}
    void Print()override
    {
        cout << "----------WORKER------------------------" << endl;
        cout << "Personal Info : " << Pib.name << " " << Pib.surname << " " << Pib.lastname << endl;
        cout << "Date of employment : " << employ_date.day << "/" << employ_date.month << "/" << employ_date.year << endl;
        cout << "Bugs fixed last month : " << bugs_fixed << endl;
        cout << endl;
    }
};

int main()
{
    President president("Oleksandr", "Kovalchuk", "Viktorovych", 15, 5, 2010, 117);
    Manager manager("Dmytro", "Boiko", "Serhiiovych", 14, 9, 2019, 34);
    Worker worker("Vasyl", "Petrenko", "Ivanovych", 1, 11, 2026, 242);

    president.Print();
    manager.Print();
    worker.Print();
}
