#include <iostream>
using namespace std;

struct Element
{
    char letter;
    int proirity;
    void Print()
    {
        cout << letter << " : " << proirity << "  |  ";
    }
    
};

class PriorityQueue
{
    Element* elements;
    int count;
public:
    PriorityQueue() : elements(nullptr), count(0) {}
    ~PriorityQueue()
    {
        if (elements != nullptr) { delete[]elements; }
    }
    void Enqueue(Element el)
    {
        int index = 0;
        while (index < count && elements[index].proirity < el.proirity) index++;
        Element* temp = new Element[count + 1];
        for (int i = 0; i < index; i++)
        {
            temp[i] = elements[i];
        }
        temp[index] = el;
        for (int i = index; i < count; i++)
        {
            temp[i+1] = elements[i];
        }
        if (elements != nullptr) { delete[]elements; }
        elements = temp;
        count++;
    }
    bool isEmpty()const
    {
        return (count == 0);
    }
    Element Dequeue()
    {
        if (!isEmpty())
        {
            Element first = elements[0];
            for (int i = 0; i < count; i++)
            {
                elements[i] = elements[i + 1];
            }
            count--;
            return first;
        }
    }
    void Print()const
    {
        for (int i = 0; i < count; i++)
        {
            elements[i].Print();
        }cout << endl;
    }
};

int main()
{
    PriorityQueue prq;
    Element el = { 'A', 1 };
    prq.Enqueue(Element{ 'A', 1 });
    prq.Enqueue(Element{ 'B', 2 });
    prq.Enqueue(Element{ 'C', 3 });
    prq.Enqueue(Element{ 'G', 4 });
    prq.Enqueue(Element{ 'K', 7 });
    prq.Print();
    prq.Enqueue(Element{ 'D', 5 });
    prq.Print();
    prq.Enqueue(Element{ 'Q', 3 });
    prq.Print();

    while (!prq.isEmpty())
    {
        cout << "Delete element : "; prq.Dequeue().Print();
        prq.Print();
        cout << endl;
    }
}
