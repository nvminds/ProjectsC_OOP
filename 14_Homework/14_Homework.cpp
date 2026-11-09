#include <iostream>
using namespace std;

template<typename T>
class List
{
    struct Node
    {
        Node* previous;
        T value;
        Node* next;
    public:
        Node() : previous(nullptr), value(0), next(nullptr) {}
        Node(Node* p, T v, Node* n) : previous(p), value(v), next(n) {}
    };
    Node* head;
    Node* tail;
public:
    List()
    {
        head = tail = nullptr;
    }
    List(const List& other) : head(nullptr), tail(nullptr)
    {
        for (Node* i = other.head; i != nullptr; i = i->next)
            addToTail(i->value);
    }
    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = current->next;
            delete current;
        }
    }
    void Print()
    {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }cout << endl;
    }
    bool IsEmpty()const
    {
        return head == nullptr;
    }
    void addToHead(T val)
    {
        Node* newNode = new Node(nullptr, val, head);
        if (IsEmpty())
        {
            head = tail = newNode;

        }
        else
        {
            head->previous = newNode;
            head = newNode;
        }

    }
    void addToTail(T val)
    {
        Node* newNode = new Node(tail, val, nullptr);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

    }
    void DeleteFromHead()
    {
        if (IsEmpty())return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            delete head->previous;
            head->previous = nullptr;
        }
    }
    void DeleteFromTail()
    {
        if (IsEmpty())return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            tail = tail->previous;
            delete tail->next;
            tail->next = nullptr;
        }
    }
    
};


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

class Passport
{
    PIB pib;
    Date birthdate;
public:
    Passport() : pib({ "noname", "nosurname", "nolastname" }), birthdate({ 0,0,0 }) {}
    Passport(PIB p, Date d)
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
        cout << "Passport Info :   " << pib.name << " " << pib.surname << " " << pib.lastname
            << "   " << birthdate.day << "/" << birthdate.month << "/" << birthdate.year << endl;
    }
};


class ForeignPassport : public Passport
{
    List<string> vises;
    int passport_number;
public:
    ForeignPassport(): Passport(), passport_number(0) {}
    ForeignPassport(PIB p, Date d, const List<string>& v, int num)
        : Passport(p, d), vises(v), passport_number(num) {
    }
    void Print()
    {
        Passport::Print();
        cout << "Vises : ";
        vises.Print();
    }

};

int main()
{
    List<string> vises;
    vises.addToTail("USA");
    vises.addToTail("Canada"); 
    Passport p({ { "Volodymur", "Kravchuk", "Borysovych" }, { 20, 10, 2010 } });
    p.Print();
    cout << endl;

    ForeignPassport p1({ "Oleg", "Kravchuk", "Borysovych" }, { 20, 10, 1998 }, vises, 123456);
    p1.Print();
}

