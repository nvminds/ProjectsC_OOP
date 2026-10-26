#include <iostream>
using namespace std;

template<typename T>
class Array
{
    T* arr;
    int size;
public:
    explicit Array(int size)
    {
        this->size = size;
        arr = new T[size] {};
    }
    Array(int size, T num)
    {
        this->size = size;
        arr = new T[size] {};
    }
    Array(initializer_list<T> list)
    {
        this->size = list.size();
        arr = new T[size];
        int i = 0;
        for (T elem : list)
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
    void Fill(initializer_list<T> list);
    void Print()const;
    T FindMax()const;
    T FindMin()const;
    Array& ChangeValue(T value, int index);
    int BinarySearch(T key);
    void BubbleSort();
};

int main()
{
    int* dynamic_arr = new int[5] {};
    //Array<int> arr1({ 5, 7, 3, 6, 1 });
    //arr1.Print();
    Array<float> arr2({ 5.3, 7.1, 2.3, 66.4, 3.1 });
    arr2.Print();
    arr2.ChangeValue(6.7, 4);
    arr2.Print();
    arr2.BubbleSort();
    arr2.Print();
    int searched = arr2.BinarySearch(5.3);
    cout << "Searched number was found by index : " << searched << endl;
    cout << "Max element : " << arr2.FindMax() << endl;
    cout << "Min element : " << arr2.FindMin() << endl;
    //Array<string> arr3({ "red", "blue", "green" });
    //arr3.Print();

    delete[]dynamic_arr;

}

template<typename T>
inline void Array<T>::Fill(initializer_list<T> list)
{
    if (arr != nullptr)
    {
        delete[]arr;
    }
    this->size = list.size();
    arr = new T[size];
    int i = 0;
    for (T elem : list)
    {
        arr[i] = elem;
        i++;
    }
}

template<typename T>
inline void Array<T>::Print() const
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }cout << endl;
}

template<typename T>
inline T Array<T>::FindMax() const
{
    T max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}

template<typename T>
inline T Array<T>::FindMin() const
{
    T min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i]<min)
        {
            min = arr[i];
        }
    }
    return min;
}

template<typename T>
Array<T>& Array<T>::ChangeValue(T value, int index)
{
    if (index >= 0 and index <= size) { arr[index] = value; };
    return *this;
}

template<typename T>
inline int Array<T>::BinarySearch(T key)
{
    int B = 0, E = size - 1;
    while (true)
    {
        int p = (B + E) / 2;
        if (key > arr[p])
        {
            B = p + 1;
        }
        else if (key < arr[p])
        {
            E = p - 1;
        }
        else if (key == arr[p])
            return p;
        if (B > E) return -1;
    }
}

template<typename T>
inline void Array<T>::BubbleSort()
{
    T temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j]) {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
