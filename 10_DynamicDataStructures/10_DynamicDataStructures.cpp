#include <iostream>
using namespace std;

/*
class Stack
{
    enum {EMPTY = -1, FULL = 9};
    int arr[FULL + 1];
    int TopIndex;
public:
    //default and delete
    Stack()
    {
        TopIndex = EMPTY;
    }
    Stack(const Stack& other) = delete;
    ~Stack() = default; // can not be delete
    //void Print() = default;

    bool IsFull()
    {
        return TopIndex == FULL;
    }
    bool Push(int el)
    {
        if (!IsFull())
        {
            arr[++TopIndex] = el;
            return true;
        }
        return false;
    }
    bool IsEmpty()
    {
        return TopIndex == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
        {
            return arr[TopIndex--];
        }
    }
    int getCount()
    {
        return TopIndex + 1;
    }
    void Clear()
    {
        TopIndex = EMPTY;
    }
    int Peek()
    {
        if (!IsEmpty())
        {
            return arr[TopIndex];
        }
    }
    void Print()
    {
        for (int i = 0; i < TopIndex+1; i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }
};
*/
class Stack
{
    enum { EMPTY = -1 };
    int* arr;
    int size;
    int TopIndex = EMPTY;
public:
    Stack() = default;
    Stack(int size): size(size) 
    {
        arr = new int[size];
    }
    ~Stack()
    {
        if(arr!=nullptr)
        {
            delete[]arr;
        }
    }
    bool IsFull()
    {
        return TopIndex == size-1;
    }
    bool Push(int el)
    {
        if (!IsFull())
        {
            arr[++TopIndex] = el;
            return true;
        }
        return false;
    }
    bool IsEmpty()
    {
        return TopIndex == EMPTY;
    }
    int Pop()
    {
        if (!IsEmpty())
        {
            return arr[TopIndex--];
        }
    }
    int getCount()
    {
        return TopIndex + 1;
    }
    void Clear()
    {
        TopIndex = EMPTY;
    }
    int Peek()
    {
        if (!IsEmpty())
        {
            return arr[TopIndex];
        }
    }
    void Print()
    {
        for (int i = 0; i < TopIndex + 1; i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }
};
int main()
{
    srand(time(0));
    Stack st(15);//size 10 by default
    cout << "Size = " << st.getCount() << endl;
    for (int i = 0; i < 7; i++)
    {
        st.Push(rand() % 50);
    }

    cout << "Size = " << st.getCount() << endl;
    st.Print();
    while (!st.IsEmpty())
    {
        cout << "Delete element : " << st.Pop() << endl;
        st.Print();
    }
    cout << "Size = " << st.getCount() << endl;
    st.Print();
}

