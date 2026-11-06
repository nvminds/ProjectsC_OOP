#include <iostream>
using namespace std;


class List
{
    struct Node
    {
        Node* previous;
        int value;
        Node* next;
    public:
        Node(): previous(nullptr), value(0), next(nullptr){}
        Node(Node * p, int v, Node* n): previous(p), value(v), next(n) {}
    };
    Node* head;
    Node* tail;
public:
    List()
    {
        head = tail = nullptr;
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
        //Node* current = head; //int i = 0
        //while (current != nullptr) // i < 10
        //{
        //    cout << current->value << " ";
        //    current = current->next;// i++
        //}
        //cout << endl;

        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }cout << endl;
    }
    bool IsEmpty()const
    {
        return head == nullptr;
    }
    void addToHead(int val)
    {
        Node* newNode = new Node(nullptr, val, head);
        if (IsEmpty())
        {
            head = newNode;
        }
        else
        {
            head->previous = newNode;
            head = newNode;
        }
        
    }
    void addToTail(int val)
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

int main()
{
    List l;
    /*for (int i = 0; i < 10; i++)
    {
        l.addToHead(i);
    }l.Print();*/
    for (int i = 0; i < 10; i++)
    {
        l.addToTail(i);
    }l.Print();

    cout << endl;
    l.DeleteFromHead();
    l.Print();
    l.DeleteFromHead();
    l.Print();
    l.DeleteFromHead();
    l.Print();

}
