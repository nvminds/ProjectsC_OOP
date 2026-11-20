#include <iostream>
using namespace std;

class Stack
{
    enum { EMPTY = -1 };
    int* arr;
    int size;
    int TopIndex = EMPTY;
public:
    Stack() = default;
    Stack(int size) 
    {
        if (size >= 0) {
            this->size = size;
            arr = new int[size];
        }
        else {
            throw invalid_argument("Size less than 0.");
        }
    }
    ~Stack()
    {
        if (arr != nullptr)
        {
            delete[]arr;
        }
    }
    bool IsFull()
    {
        return TopIndex == size - 1;
    }
    bool Push(int el)
    {
        if (!IsFull())
        {
            arr[++TopIndex] = el;
            return true;
        }
        else {
            throw exception("Stack overflow");
        }
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
        else {
            throw length_error("Stack is empty");
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
        throw length_error("Stack is empty");
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
    try
    {
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
    catch (length_error ex)
    {
        cout << ex.what() << endl;
    }
    catch (invalid_argument ex)
    {
        cout << ex.what() << endl;
    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
    }
    catch (...)
    {
        cout << "Unknown error" << endl;
    }
}