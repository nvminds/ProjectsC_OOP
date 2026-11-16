//#include <iostream>
//using namespace std;
//
//class Person
//{
//    string name;
//    string spetialization;
//    int age;
//    int* marks;
//    int countMarks;
//public:
//    Person(): name("noname"), age(0), spetialization("none"), marks(nullptr), countMarks(0) {}
//    Person(string name, string spec, int age): name(name), spetialization(spec), age(age)
//    {
//        countMarks = rand() & 15 + 2;
//        marks = new int[countMarks];
//        for (int i = 0; i < countMarks; i++)
//        {
//            marks[i] = rand() % 12 + 1;
//        }
//    }
//    virtual void Print()const
//    {
//        cout << "Name : " << name << endl;
//        cout << "Age : " << age << endl;
//        cout << "Spetialization : " << spetialization << endl;
//        cout << "Marks : ";
//        for (int i = 0; i < countMarks; i++)
//        {
//            cout << marks[i] << " ";
//        }cout << endl;
//    }
//    virtual ~Person()
//    {
//        if (marks != nullptr) { delete[]marks; }
//    }
//};
//class Aspirant : public Person
//{
//    string *subject;
//    int countSubjects;
//public:
//    Aspirant():Person(), subject(nullptr), countSubjects(0) {}
//    Aspirant(string name, string spec, int age,initializer_list<string> list):Person(name, spec, age)
//    {
//        this->countSubjects = list.size();
//        subject = new string[countSubjects];
//        int i = 0;
//        for (string sub : list )
//        {
//            subject[i] = sub;
//            i++;
//        }
//    }
//    void Print()const override
//    {
//        Person::Print();
//        cout << "Subject : ";
//        for (int i = 0; i < countSubjects; i++)
//        {
//            cout << subject[i] << " ";
//        }cout << endl;
//    }
//    ~Aspirant()
//    {
//        if (subject != nullptr){ delete[]subject; }
//    }
//};
//
//int main()
//{
//    srand(time(0));
//
//    Person s("Vasya", "Programmer", 15);
//    s.Print();
//    cout << endl;
//
//    Aspirant as("Ivan", "History", 21, { "Ukrainian revolution", "UNR", "World War 2" });
//    as.Print();
//    cout << endl;
//
//    cout << "---------------------------------------" << endl;
//
//    Person* group[3]
//    {
//        new Person("Lola", "Programmer", 19),
//        new Aspirant("Petro", "History", 21, { "Ukrainian revolution", "UNR", "World War 2" }),
//        new Aspirant("Volodya", "Chemistry", 21, {"Water", "Oil", "Gasoline"}),
//    };
//
//    for (int i = 0; i < 3; i++)
//    {
//        group[i]->Print();
//        delete group[i];
//    }
//}
