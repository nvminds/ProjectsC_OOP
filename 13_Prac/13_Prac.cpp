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



class Train
{
    struct Vagon
    {
        int vagon_num;
        int sits_count;
        int passagers_count;
        friend ostream& operator<<(ostream& out,const Vagon& v)
        {
            cout << "Vagon number : " << v.vagon_num << endl;
            cout << "Sits count : " << v.sits_count << endl;
            cout << "Passagers count  : " << v.passagers_count << endl;
            return out;
        }
    };
    string model;
    List<Vagon> vagons;
    int countVagons;
public:
    Train():model("no model"), countVagons(0){}
    Train(string m, int c):model(m), countVagons(c) {}
    Train(const Train &other)
    {
        this->model = other.model;
        this->vagons = other.vagons;
        this->countVagons = other.countVagons;
    }

    void Show() { vagons.Print(); }
    void addVagonToHead(Vagon v)
    {
        vagons.addToHead(v);
        countVagons++;
    }
    void addVagonToTail(Vagon v)
    {
        vagons.addToTail(v);
        countVagons++;
    }
    void deleteVagonFromHead()
    {
        if (countVagons == 0)return;
        vagons.DeleteFromHead();
        countVagons--;
    }
    void deleteVagonFromTail()
    {
        if (countVagons == 0)return;
        vagons.DeleteFromTail();
        countVagons--;
    }
    
};
int main()
{
    Train t("model1", 5);
    t.addVagonToHead({1, 30, 21});
    t.Show();
    t.addVagonToHead({2, 30, 13});
    t.Show();
    t.addVagonToTail({3, 30, 16});
    t.Show();
    t.deleteVagonFromHead();
    t.Show();
    t.deleteVagonFromTail();
    t.Show();
}
