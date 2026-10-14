#include <iostream>
using namespace std;

struct Point
{
    int x;
    int y;
};
class Student
{
    string name;
    int age;
    int* marks;
    int countMarks;
public:
    Student()
    {
        name = "no name";
        age = 0;
        marks = nullptr;
        countMarks = 0;
    }
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
        marks = nullptr;
        countMarks = 0;
    }
    Student(const Student &other)
    {
        this->name = other.name;
        this->age = other.age;
        this->countMarks = other.countMarks;
        //this->marks = other.marks;
        this->marks = new int[countMarks];
        for (int i = 0; i < countMarks; i++)
        {
            marks[i] = other.marks[i];
        }
    }
    ~Student()
    {
        if (marks != nullptr)
        {
            delete[]marks;
        }

    }
    void Print()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Count marks : " << countMarks << endl;
        cout << "Marks : ";
        for (int i = 0; i < countMarks; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
        cout << endl;
    }
    void addMark(int mark)
    {
        int* temp = new int[ countMarks + 1];
        for (int i = 0; i < countMarks; i++)
        {
            temp[i] = marks[i];
        }
        temp[countMarks] = mark;
        if (marks!=nullptr)
        {
            delete[]marks;
        }
        marks = temp;
        countMarks++;
    }
};


int main()
{
    Student st;
    st.Print();

    Student st1("Vasya", 15);
    st1.Print();
    st1.addMark(5);
    st1.addMark(6);
    st1.addMark(7);

    Student copy = Student(st1);
    
    cout << "Original" << endl;
    st1.Print();
    cout << "Copy" << endl;
    copy.Print();









    /*
    Point point{15,25};
    int a;
    int* prt;
    int b = 10;
    int c = 3.33;
    //cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    int numbers[2];
    numbers[0] += 2;
    cout << numbers[0] << endl;
    cout << numbers[1] << endl;

    int number = 2;//Ініціалізація з копіюванням

    int value(2.2);//пряма ініціалізація
    int size{ 33.33 };//уніфікована ініціалізація

    cout << number << endl;
    cout << value << endl;
    cout << size << endl;

    int answer{5};
    //int answer = 5;
    const float goodTemp{ 36.6 };
    int marks[3]{ 1, 4, 6 };
    int matrix[2][2]{ {1,2}, {3,4} };
    int* dataPtr;
    */
}
