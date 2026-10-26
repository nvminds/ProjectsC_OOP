#include <iostream>
using namespace std;

class Array
{
    int* arr;
    int size;
public:
    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size] {};
    }
    Array(int size, int num)
    {
        this->size = size;
        arr = new int[size] {};
    }
    Array(initializer_list<int> list)
    {
        this->size = list.size();
        arr = new int[size];
        int i = 0;
        for (int elem : list)
        {
            arr[i] = elem;
            i++;
        }
    }
    ~Array()
    {
        if (arr != nullptr)
        {
            delete[]arr;
        }
    }
    void Fill(initializer_list<int> list)
    {
        if (arr != nullptr)
        {
            delete[]arr;
        }
        this->size = list.size();
        arr = new int[size];
        int i = 0;
        for (int elem : list)
        {
            arr[i] = elem;
            i++;
        }
    }
    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }
};

int main()
{
    int static_arr[5] = { 1,2,3,4,5 };
    int* dynamic_arr = new int[5] {5, 4, 3, 2, 1};

    Array arr(10);
    arr.Print();

    Array arr2({ 5, 7, 3, 6, 1 });
    arr2.Print();
    arr2.Fill({ 4, 4, 4, 4 });
    arr2.Print();


    delete[]dynamic_arr;

}
