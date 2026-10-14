#include <iostream>
using namespace std;

class Array 
{
    long* arr;
    int size;
public:
    Array()
    {
        size = 10;
        arr = new long[size]{};
    }
    Array(int size)
    {
        this->size = size;
        arr = new long[size]{};
    }
    Array(const Array &array)
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
            cout << "Enter [" << i+1 << "] number >> "; cin >> numb;
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
        long* temp = new long[size+1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        temp[size] = num;
        if (arr!=nullptr)
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
            if (arr[i]==value)
            {
                pos = i;
                istrue = 1;
            }
        }
        if (istrue!=1)
        {
            cout << "Value is not found!" << endl;
            return;
        }
        long* temp = new long[size - 1];
        for (int i = 0; i < pos; i++)
        {
            temp[i] = arr[i];
        }
        for (int i = pos+1; i < size; i++)
        {
            temp[i-1] = arr[i];
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
        if (index<0 or index>= size)
        {
            cout << "Index must be positive and not over size!" << endl;
            return;
        }
        long* temp = new long[size - 1];
        for (int i = 0; i < index; i++)
        {
            temp[i] = arr[i];
        }
        for (int i = index+1; i < size; i++)
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
            if (arr[i]>max)
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

};

int main()
{
    srand(time(0));
    Array array;
    int number;
    cout << "Default array by ctor : "; array.showArray(); cout << endl;
    
    array.initDefaultArray();
    cout << "Default array by method : "; array.showArray();
    
    cout << endl; array.initInputArray();
    cout << "Inputed array : "; array.showArray(); cout << endl;
    
    array.initRandArray();
    cout << "Random array : "; array.showArray(); cout << endl;

    cout << "Enter new array element >> "; cin >> number;
    array.addToArray(number); array.showArray(); cout << endl;

    cout << "Remove element by value >> "; cin >> number;
    array.removeFromArrayByVal(number); array.showArray(); cout << endl;

    cout << "Remove element by index >> "; cin >> number;
    array.removeFromArrayByIndex(number); array.showArray(); cout << endl;

    cout << "Array sorted by ascend : "; 
    array.bubbleSortAcend(); array.showArray(); cout << endl;

    cout << "Array sorted by descend : "; 
    array.bubbleSortDecend(); array.showArray(); cout << endl;

    int Max = array.maxArr();
    int Min = array.minArr();
    float Avg = array.avgArr();

    cout << "Max value in array : " << Max << endl;
    cout << "Min value in array : " << Min << endl;
    cout << "Average of values in array : " << Avg << endl;

    cout << endl;

    Array array2 = Array(array);
    cout << "Original : ";
    array.showArray();
    cout << "Copy : ";
    array2.showArray();

}

