#include <iostream>
#include <fstream>
using namespace std;

struct Birthdate
{
    int day;
    int month;
    int year;
    void PrintBirthdate()
    {
        cout << "Birthdate : " << day << "/" << month << "/" << year << endl;
    }
};

class Student 
{
    string name;
    string surname;
    string lastname;
    Birthdate birthdate;
    string phone;
    int* marks;
    int countMarks;
    float avgMark;
    void averageMark()
    {
        double summa = 0;
        for (int i = 0; i < countMarks; i++)
        {
            summa += marks[i];
        }
        avgMark = summa / countMarks;
    }
public:
    //ctor + TAB
    Student() //methods
    {
        cout << "Defult constructor" << endl;
        name = "Blank Name";
        surname = "Blank Surname";
        lastname = "Blank Lastname";
        birthdate = { 1 , 1, 1 };
        phone = "no = phone";
        marks = nullptr;
        countMarks = 0;
        avgMark = 0;
    }
    Student(string name, string surname, string lastname)
    {
        cout << "Parametrized constructor" << endl;
        this->name = name;
        this->surname = surname;
        this->lastname = lastname;
        birthdate = { 1 , 1, 1 };
        phone = "no = phone";
        marks = nullptr;
        countMarks = 0;
        avgMark = 0;
    }
    void Print()
    {
        cout << "Name : " << name << endl;
        cout << "Surname : " << surname << endl;
        cout << "Lastname : " << lastname << endl;
        birthdate.PrintBirthdate();
        cout << "Phone : " << phone << endl;
        cout << "Marks : ";
        for (int i = 0; i < countMarks; i++)
        {
            cout << marks[i] << " ";
        }cout << endl;
        cout << "Average mark : " << avgMark << endl;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setSurname(string surname)
    {
        this->surname = surname;
    }
    void setLastname(string lastname)
    {
        this->lastname = lastname;
    }
    void Initialization()
    {
        name = "Blank Name";
        surname = "Blank Surname";
        lastname = "Blank Lastname";
        birthdate = { 1 , 1, 1 };
        phone = "no = phone";
        marks = nullptr;
        countMarks = 0;
        avgMark = 0;
    }
    void AddMark(int mark)
    {
        int* temp = new int[countMarks + 1];
        for (int i = 0; i < countMarks; i++)
        {
            temp[i] = marks[i];
        }
        temp[countMarks] = mark;
        countMarks++;
        marks = temp;
        averageMark();
    }
    //~ + TAB destructor
    ~Student()
    {
        cout << "Destructor " << name << endl;
        if (marks != nullptr)
        {
            delete[]marks;
        }
    }
};

int main()
{
    Student student; //defult constructor
    //student.Initialization();
    student.Print();
    student.setName("Vasya");
    student.setSurname("Chigur");
    student.setLastname("Vasiluk");
    student.AddMark(2);
    student.AddMark(3);
    student.AddMark(6);
    student.AddMark(4);
    
    student.Print();

    Student s2("Gorila", "Braat", "Dwa");
    s2.AddMark(6);
    s2.AddMark(4);
    s2.AddMark(2);
    s2.AddMark(3);
    s2.Print();

}
