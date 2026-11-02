#include <iostream>
#include <conio.h>
using namespace std;

template<typename T>
struct Element
{
    T letter;
    int proirity;
    void Print()
    {
        cout << letter << " : " << proirity << "     ";
    }
};

template<typename T>
class PriorityQueue
{
    Element<T>* elements;
    int count;
public:
    PriorityQueue() : elements(nullptr), count(0) {}
    ~PriorityQueue()
    {
        if (elements != nullptr) { delete[]elements; }
    }
    void Enqueue(Element<T> el)
    {
        int index = 0;
        while (index < count && elements[index].proirity > el.proirity) index++;
        Element<T>* temp = new Element<T>[count + 1];
        for (int i = 0; i < index; i++)
        {
            temp[i] = elements[i];
        }
        temp[index] = el;
        for (int i = index; i < count; i++)
        {
            temp[i + 1] = elements[i];
        }
        if (elements != nullptr) { delete[]elements; }
        elements = temp;
        count++;
    }
    bool isEmpty()const
    {
        return (count == 0);
    }
    Element<T> Dequeue()
    {
        if (!isEmpty())
        {
            Element<T> first = elements[0];
            for (int i = 0; i < count-1; i++)
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
    int choice;
    PriorityQueue<string> prq;
    //prq.Enqueue(Element<string>{ "Director", 4 });
    //prq.Enqueue(Element<string>{ "Manager", 3 });
    //prq.Enqueue(Element<string>{ "Admin", 2 });
    //prq.Enqueue(Element<string>{ "Guest", 1 });
    //prq.Print();
    //while (!prq.isEmpty())
    //{
    //    cout << "Printing : "; prq.Dequeue().Print();
    //    cout << endl;
    //}
    do
    {
        system("cls");
        cout << "-------------------Choose-------------------" << endl;
        cout << "    Add file to printer queue   --->   [1]  " << endl;
        cout << "    Show all files queue        --->   [2]  " << endl;
        cout <<  endl;
        cout << "    Exit                        --->   [0]  " << endl;
        cout << "Your choice >> "; cin >> choice;
        cout <<  endl;
        switch (choice)
        {
        case 0:
            cout << "Goodbye!" << endl;
            break;
        case 1:
        {
            int choice1;
            string file;
            cout << "Enter file name >> "; cin >> file;
            cout << "Choose your position : [1] - Guest  [2] - Admin  [3] - Manager  [4] - Director" << endl;
            cout << "Enter your pos >> "; cin >> choice1;
            if(choice1<1 or choice1 > 4)
            {
                break;
            }
            else if (choice1==1)
            {
                prq.Enqueue(Element<string>{ file, 1 });
                break;
            }
            else if (choice1==2)
            {
                prq.Enqueue(Element<string>{ file, 2 });
                break;
            }
            else if (choice1==3)
            {
                prq.Enqueue(Element<string>{ file, 3 });
                break;
            }
            else if (choice1==4)
            {
                prq.Enqueue(Element<string>{ file, 4 });
                break;
            }
        }
        case 2:
            while (!prq.isEmpty())
            {
                cout << "Printing : "; prq.Dequeue().Print();
                cout << endl;
            }
            break;

        default:
            break;
        }
        if(choice!=0)
        {
            cout << "Press any button..." << endl;
            _getch();
        }
    } while (choice != 0);
}
