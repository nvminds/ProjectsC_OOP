#include <iostream>
using namespace std;

class Date
{
public:
    int day;
    int month;
    int year;
    void Print()const
    {
        cout << "Date : " << day << "/" << month << "/" << year << endl;
    }
    void setDay(int day)
    {
        this->day = day;
    }
    int getDay()
    {
        day += 10;
        return day;
    }
    int getDay()const
    {
        return day;
    }
};
class Account 
{
    double sum;
    const double rate;
public:
    Account(double sum, double rate): rate(rate)
    {
        this->sum = sum;
    }
    double getRate()const
    {
        return rate;
    }
    double getIncome()
    {
        return sum * rate / 100;
    }
    double getIncome()const
    {
        return sum * rate / 100;
    }
    double getSum()const
    {
        return sum;
    }
    double setSum()
    {
        sum += getIncome();
        return sum;
    }
};
void DoSomething(long number)
{
    
}
float DoSomething() // implicit(неявна)       double --> float   звужуюча
{
    return 1.5;
}

class Array 
{
    int* arr;
    int size;
public:
    //explicit забороняє implicit(неявне перетворення) 
    //explicit пишемо тількі біля конструктора з 1 параметром
    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size];
    }
    Array(int size, int num)
    {
        this->size = size;
        arr = new int[size];
    }
    ~Array()
    {
        if (arr!=nullptr)
        {
            delete[]arr;
        }
    }
    int getSize()const
    {
        return size;
    }
    int getValue(int index)const
    {
        return arr[index];
    }
    void setValue(int num, int index)
    {
        arr[index] = num;
    }
    void display(int index)const
    {
        cout << arr[index] << " ";
    }
};

void PrintArray(const Array &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.display(i);
    }
    cout << endl;
}
int main()
{
    int size = 4;
    Array arr(size);
    for (int i = 0; i < arr.getSize(); i++)
    {
        arr.setValue(size - i, i);
    }
    PrintArray(arr);
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    //Explicit
    /*
    PrintArray(8);// implicit       int ---> Array

    Array a = 100;
    PrintArray(a);

    Array r(5, 77);
    Array t = 5, 77;
    */

    /*
    int a = 3.14; // implicit(неявна)       double --> int   звужуюча
    cout << a << endl;

    double b(10);// implicit(неявна)        int --> double   розширююча
    cout << b << endl;
    
    DoSomething(5);// implicit(неявна)        int --> long   розширююча

    float pi = (float)3.14;//explicit
    */







    //Account account1(2000, 5);
    //const Account account2(5000, 8);
    //cout << "Rate 1 : " << account1.getRate() << endl;
    //cout << "Rate 2 : " << account2.getRate() << endl;

    //cout << "Sum 1 : " << account1.getSum() << endl;
    //cout << "Sum 2 : " << account2.getSum() << endl;

    //cout << "Income 1 : " << account1.getIncome() << endl;
    //cout << "Income 2 : " << account2.getIncome() << endl;

    //cout << "Sum 1 : " << account1.setSum() << endl;
    //cout << "Sum 2 : " << account2.setSum() << endl; error


    /*
    const int size = 5;
    const int month[3]{31,31,28};
    //month[0] = 45;

    Date holidays_date{ 25,10,2026 };
    holidays_date.Print();
    holidays_date.day = 31;
    holidays_date.Print();
    holidays_date.setDay(19);
    holidays_date.Print();
    holidays_date.getDay();
    holidays_date.Print();

    const Date independencyDay{ 24,8,2027 };
    //independencyDay.Print();
    //independencyDay.day = 25;
    //independencyDay.Print();
    independencyDay.getDay();
    independencyDay.Print();
    */
}
