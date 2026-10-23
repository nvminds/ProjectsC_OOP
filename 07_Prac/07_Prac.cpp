#include <iostream>
using namespace std;

class Array
{
    long* arr;
    int size;
public:
#pragma region Constructors
    Array()
    {
        size = 10;
        arr = new long[size] {};
    }
    Array(int size)
    {
        this->size = size;
        arr = new long[size] {};
    }
    Array(const Array& array)
    {
        this->size = array.size;
        this->arr = new long[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = array.arr[i];
        }
    }
    ~Array()
    {
        if (arr != nullptr)
        {
            delete[]arr;
        }
    }
#pragma endregion

#pragma region Methods
    void initDefaultArray()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    void initRandArray()
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = rand() % 100;
        }
    }
    void initInputArray()
    {
        for (int i = 0; i < size; i++)
        {
            int numb;
            cout << "Enter [" << i + 1 << "] number >> "; cin >> numb;
            arr[i] = numb;
        }
    }
    void showArray()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void addToArray(int num)
    {
        long* temp = new long[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        temp[size] = num;
        if (arr != nullptr)
        {
            delete[]arr;
        }
        arr = temp;
        size++;
    }
    void removeFromArrayByVal(int value)
    {
        int istrue = 0;
        int pos;
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                pos = i;
                istrue = 1;
            }
        }
        if (istrue != 1)
        {
            cout << "Value is not found!" << endl;
            return;
        }
        long* temp = new long[size - 1];
        for (int i = 0; i < pos; i++)
        {
            temp[i] = arr[i];
        }
        for (int i = pos + 1; i < size; i++)
        {
            temp[i - 1] = arr[i];
        }
        if (arr != nullptr)
        {
            delete[]arr;
        }
        arr = temp;
        size--;

    }
    void removeFromArrayByIndex(int index)
    {
        if (index < 0 or index >= size)
        {
            cout << "Index must be positive and not over size!" << endl;
            return;
        }
        long* temp = new long[size - 1];
        for (int i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        for (int i = index + 1; i < size; i++)
        {
            temp[i - 1] = arr[i];
        }
        if (arr != nullptr)
        {
            delete[]arr;
        }
        arr = temp;
        size--;
    }
    void bubbleSortAcend()
    {
        int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j--)
            {
                if (arr[j - 1] > arr[j])
                {
                    temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    void bubbleSortDecend()
    {
        int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = size - 1; j > i; j--)
            {
                if (arr[j - 1] < arr[j])
                {
                    temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    int maxArr()
    {
        int max = arr[0];
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }
    int minArr()
    {
        int min = arr[0];
        for (int i = 0; i < size; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        return min;
    }
    float avgArr()
    {
        int summ = 0;
        for (int i = 0; i < size; i++)
        {
            summ += arr[i];
        }
        float avg = (double)summ / size;
        return avg;
    }
#pragma endregion

    int operator[](int index)
    {
        if (index >= 0 and index < size) { return arr[index]; }
    }
    void operator()(int num)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] += num;
        }
    }

};

int main()
{
    srand(time(0));

    Array array;
    array.initRandArray();
    array.showArray(); 
    cout << array[0]<< endl;
    array(20);
    array.showArray(); 
}
