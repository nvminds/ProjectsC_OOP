#include <iostream>
#include <vector>
using namespace std;

/*
int getMax(int arr[], int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}
short getMax(short arr[], int size)
{
	short max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}
long getMax(long arr[], int size)
{
	long max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if(arr[i]>max)
		{
			max = arr[i];
		}
	}
	return max;
}
*/

template<typename T>
T getMax(T arr[], int size)
{
	T max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

template<typename T_coll, typename T_value>
class MyClass
{
	T_coll* collection;
	int size;
	T_value value;
public:
	MyClass()
	{
		collection = nullptr;
		size = 0;
		value = nullptr;
	}
	MyClass(T_coll* collection,int size, T_value value):collection(collection),size(size), value(value) {}
	~MyClass()
	{
		if(collection!=nullptr)
		{
			delete[]collection;
		}
	}
	void setCollection(T_coll* collection);
	void setValue(T_value value);
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << collection[i] << " ";
		}cout << endl;
		cout << value << endl;
	}
};
template<typename T_coll, typename T_value>
void MyClass<T_coll, T_value>::setCollection(T_coll* collection) { this->collection = collection; }

template<typename T_coll, typename T_value>
inline void MyClass<T_coll, T_value>::setValue(T_value value) { this->value = value; }

template<typename T_coord>
class Point {
	T_coord x, y;
public:
	Point()
	{
		x = y = 0;
	}
	explicit Point(T_coord value)
	{
		this->x = value;
		this->y = value;
	}
	Point(T_coord x, T_coord y)
	{
		this->x = x;
		this->y = y;
	}
	void Print()const
	{
		cout << "X : " << x << endl;
		cout << "Y : " << y << endl;
		cout << endl;
	}
	void setNewCoords(T_coord newX, T_coord newY)
	{
		this->x = newX;
		this->y = newY;
	}

};

template<typename T_x, typename T_y>
class NewPoint {
	T_x x; 
	T_y y;
public:
	NewPoint()
	{
		x = y = 0;
	}
	NewPoint(T_x x, T_y y)
	{
		this->x = x;
		this->y = y;
	}
	void Print()const
	{
		cout << "X : " << x << endl;
		cout << "Y : " << y << endl;
		cout << endl;
	}
	void setNewCoords(T_x newX, T_y newY)
	{
		this->x = newX;
		this->y = newY;
	}

};
int main()
{
	Point<int> p(5, 14);
	p.Print();
	Point<float> p2(5.2, 14.22);
	p2.Print();
	p2.setNewCoords(6.7, 4.2);
	p2.Print();
	
	NewPoint<int, float> p3(4, 6.7);
	p3.Print();
	p2.setNewCoords(6.7, 4);
	p2.Print();

	vector<int>v1 = { 1,2,3,4,5 };
	vector<string>v2 = {"aaa","vbbb","eeee"};
	vector<float>v3 = { 3.2,7.6,111.1 };

	/*
	long* long_arr = new long[5];
	for (int i = 0; i < 5; i++)
	{
		long_arr[i] = i + 1;
		cout << long_arr[i] << " ";
	}
	cout << endl;

	char* char_arr = new char[5];
	for (int i = 0; i < 5; i++)
	{
		char_arr[i] = 'a' + i;
		cout << char_arr[i] << " ";
	}
	cout << endl;

	MyClass<long, string> cl1(long_arr,5, "Class with long arr");
	MyClass<char, string> cl2(char_arr,5, "Class with char arr");
	cl1.Print();
	cl2.Print();

	//delete[]char_arr;
	//delete[]long_arr;
	*/
	/*
	const int size = 10;
	int arr[size] = {5,6,1,45,76,23,74,97,34,64};
	short arr1[size] = {5,6,1,45,76,23,74,9,34,64};
	long arr2[size] = {5,6,1,45,7,23,4,9,34,64};
	string colors[size] = {"red","orange","yellow","green","blue","cyan","purple","black","pink","grey"};
	string names[6] = {"Vlad","Oleg","Bohdan","Vasya","Oleksii","Lyoha"};
	string letters[6] = { "leter","letter","lettter","A","AA","AAA" };
	cout << "Max element : " << getMax(arr, size) << endl;
	cout << "Max element : " << getMax(arr1, size) << endl;
	cout << "Max element : " << getMax(arr2, size) << endl;
	cout << "Max element : " << getMax(colors, size) << endl;
	cout << "Max element : " << getMax(names, 6) << endl;
	cout << "Max element : " << getMax(letters, 6) << endl;
	*/
}


