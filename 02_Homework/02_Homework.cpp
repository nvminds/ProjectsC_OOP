#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char* filename = "Students.txt";

class Student 
{
    string name;
    int age;
    int* marks;
    int countMarks;
    float avgMark;
    void setAverageMark()
    {
        double summa = 0;
        for (int i = 0; i < countMarks; i++)
        {
            summa += marks[i];
        }
        avgMark = summa / countMarks;
    }
public:
    void setName(string name)
    {
        this->name = name;
    }
    void setAge(int age)
    {
        this->age = age;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }

    Student()
    {
        name = "no name";
        age = 0;
        marks = nullptr;
        countMarks = 0;
        avgMark = 0;
    }
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
        marks = nullptr;
        countMarks = 0;
        avgMark = 0;
    }
    void Print() 
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Marks : ";
        for (int i = 0; i < countMarks; i++)
        {
            cout << marks[i] << " ";
        }cout << endl;
        cout << "Average mark : " << avgMark << endl;
        cout << endl;
    }
    void addMark(int mark)
    {
        int* temp = new int[countMarks + 1];
        for (int i = 0; i < countMarks; i++)
        {
            temp[i] = marks[i];
        }
        temp[countMarks] = mark;
        countMarks++;
        marks = temp;
        setAverageMark();
    }
    ~Student()
    {
        cout << "Destructor " << name << endl;
        if (marks != nullptr)
        {
            delete[]marks;
        }
    }
    void saveToFile()
    {
        ofstream out(filename, ios_base::app);
        out << name;
        out << ':';
        out << age;
        out << ':';
        for (int i = 0; i < countMarks-1; i++)
        {
            out << marks[i];
            out << ':';
        }
        out << marks[countMarks-1];
        out << '|';
        out.close();
    }
    //void readFromFile()
    //{
    //    ifstream in(filename, ios_base::in);
    //    string  Bmarks, Bname, Bage, temp;
    //    while (!in.eof())
    //    {
    //        countMarks = 0;
    //        getline(in, Bname, ':');
    //        if (in.eof())
    //        {
    //            break;
    //        }
    //        getline(in, Bage, ':');
    //        getline(in, Bmarks, '|');
    //        name = Bname;
    //        age = atoi((Bage).c_str());

    //        for (int i = 0; i < Bmarks.length(); i++)
    //        {
    //            if (Bmarks[i] != ':')
    //            {
    //                temp += Bmarks[i];
    //            }
    //            else
    //            {
    //                addMark(atoi(temp.c_str()));
    //                temp = "";
    //            }
    //        }
    //        addMark(atoi(temp.c_str()));
    //        temp = "";
    //    }
    //}
};

int main()
{
    Student student;
    string name;
    int age, mark;
    //student.readFromFile();
    student.Print();
    cout << "Enter student name >> "; cin >> name;
    student.setName(name);
    cout << "Enter student age >> "; cin >> age;
    student.setAge(age);
    cout << "Enter student mark 1 >> "; cin >> mark;
    student.addMark(mark);
    cout << "Enter student mark 2 >> "; cin >> mark;
    student.addMark(mark);
    cout << "Enter student mark 3 >> "; cin >> mark; cout << endl;
    student.addMark(mark);
    student.getName();
    student.getAge();
    student.Print();
    //student.saveToFile();

    
}
