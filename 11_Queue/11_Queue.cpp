#include <iostream>
#include <conio.h>
using namespace std;

class Queue
{
    //FIFO rule - first in first out
    int* arr;
    int maxSize;// 100 capacity
    int topIndex;
public:
    Queue() = default;
    Queue(int maxSize)
    {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        topIndex = 0;
    }
    ~Queue()
    {
        if(arr!=nullptr)
        {
            delete[]arr;
        }
    }
    bool isFull()const
    {
        return (topIndex == maxSize);
    }
    void Enqueue(int elem)
    {
        if (!isFull())
        {
            arr[topIndex++] = elem;
        }
    }
    bool isEmpty()const
    {
        return (topIndex == 0);
    }
    /*
    int Dequeue()
    {
        if(!isEmpty())
        {
            int first = arr[0];
            for (int i = 0; i < topIndex; i++)
            {
                arr[i] = arr[i + 1];
            }
            topIndex--;
            return first;
        }
    }
    */
    int Dequeue() // queue cycle
    {
        if (!isEmpty())
        {
            int first = arr[0];
            for (int i = 0; i < topIndex; i++)
            {
                arr[i] = arr[i + 1];
            }
            arr[topIndex-1] = first;
            return first;
        }
    }
    int getCount()const
    {
        return topIndex;
    }
    void Clear()
    {
        topIndex = 0;
    }
    void Show()const
    {
        for (int i = 0; i < topIndex; i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }
};
int main()
{
    //srand(time(0));
    Queue q(15);
    for (int i = 0; i < 10; i++)
    {
        q.Enqueue(rand() % 50);
    }
    q.Show();
    cout << "Size : " << q.getCount();
    cout << endl;  cout << endl;
    while (!q.isEmpty())
    {
        cout << "Delete element : " << q.Dequeue() << endl;
        cout << "Size : " << q.getCount();
        cout << endl; q.Show();
        cout << endl;
        _getch();
    }
}
