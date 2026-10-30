#include <iostream>
using namespace std;

/*
//1
class Stack
{
    enum {EMPTY = -1, FULL = 9};
    char arr[FULL + 1];
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
    bool Push(char el)
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
    char Pop()
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
    char Peek()
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
//2 & 3
template<typename T>
class Stack
{
    enum { EMPTY = -1 };
    T* arr;
    int size;
    int TopIndex = EMPTY;
public:
    Stack():arr(nullptr),size(0){}
    Stack(int size) : size(size)
    {
        arr = new T[size];
    }
    Stack(initializer_list<T> list)
    {
        this->size = list.size();
        arr = new T[size];
        for (T elem : list)
        {
            arr[++TopIndex] = elem;
        }
    }
    ~Stack()
    {
        if (arr != nullptr)
        {
            delete[]arr;
        }
    }
    void Resize()
    {
        T* temp = new T[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[]arr;
        size++;
        arr = temp;
    }
    bool IsFull()
    {
        return TopIndex == size - 1;
    }
    bool Push(T el)
    {
        if (IsFull())
        {
            Resize();
        }
        arr[++TopIndex] = el;
        return true;
    }
    bool IsEmpty()
    {
        return TopIndex == EMPTY;
    }
    T Pop()
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
    T Peek()
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

    /*
    //1
    cout << "-----------------Task 1-----------------" << endl;
    Stack st;//size 10 by default
    cout << "Size = " << st.getCount() << endl;
    st.Push('!');
    st.Push('@');
    st.Push('#');
    st.Push('$');
    st.Push('%');

    cout << "Size = " << st.getCount() << endl;
    st.Print();
    while (!st.IsEmpty())
    {
        cout << "Delete element : " << st.Pop() << endl;
        st.Print();
    }
    cout << "Size = " << st.getCount() << endl;
    st.Print();
    */

    /*
    //2
    cout << "-----------------Task 2-----------------" << endl;
    Stack<char> st(3);
    cout << "Size = " << st.getCount() << endl;
    for (int i = 0; i < 10; i++)
    {
        st.Push(rand() % ('z' - 'A' + 1) + 'A');
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
    */

    cout << endl;
    cout << "-----------------Task 3-----------------" << endl;
    Stack<char> st({'H','e','l','l','o','!'});
    cout << "Size = " << st.getCount() << endl;

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


