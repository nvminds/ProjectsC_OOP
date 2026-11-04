#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node*next;
    Node(): value(0), next(nullptr){}
    Node(int value, Node *next) : value(value), next(next) {}
};

class List
{
    Node* head;
public:
    List()
    {
        head = nullptr;
    }
    ~List()
    {
        Node* current = nullptr;
        while(head!=nullptr)
        {
            current = head;
            head = current->next;
            delete current;
        }
    }
    void addToHead(int value)
    {
        Node* newNode = new Node(value, head);
        newNode->value = value;
        newNode->next = head;

        head = newNode;
    }
    void Print()
    {
        Node* current = head;
        while(current!=nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
    void addToTail(int value)
    {
        Node* newNode = new Node(value, nullptr);
        if(head==nullptr)
        {
            head = newNode;
        }
        else{
            Node* current = head;
            while(current->next!=nullptr)
            {
                current = current->next;
            }
             current->next = newNode;
            }
    }
    void DeleteFromTail()
    {
        if(head==nullptr)
        {
            return;
        }
        if(head->next==nullptr)
        {
            delete head;
            head = nullptr;
        }
        else{
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }
};


int main()
{
    List l;
    //for (int i = 0; i < 10; i++)
    //{
    //    l.addToHead(i);
    //}
    //l.Print();
    l.addToTail(100);
    l.addToTail(200);
    l.addToTail(300);
    l.Print();
    l.DeleteFromTail();
    l.Print();
    l.DeleteFromTail();
    l.Print();
    l.DeleteFromTail();
    l.Print();
}
