#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> v, vector<int> v2) {
	cout << "Vector 1 : ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}cout << endl;
	cout << "Vector 2 : ";
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}cout << endl;
}

int main()
{
    vector<int>v = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int>v2 = { 11,12,13,14,15 };
	/*
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " "; 
	}cout << endl;
	v[0] = 67;
	for(auto item:v)
	{
		cout << item << " ";
		item = 0;
	}cout << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}cout << endl;
	//for (auto i = v.begin(); i != v.end(); i++)
	//{

	//}
	int a = 5;
	auto b = 6;
	auto c = 3.33;
	float d = 1.5;
	int o;
	auto p = 'c';

	PrintVector(v, v2);
	v.erase(v.begin());
	v2.erase(v2.begin()+2);
	PrintVector(v, v2);
	v.erase(v.end()-1);
	PrintVector(v, v2);

	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.erase(v.begin(), v.end() - 4);
	PrintVector(v, v2);
	
	v.insert(v.end() - 2, 67);
	PrintVector(v, v2);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.end(), {7, 8, 9, 10});
	PrintVector(v, v2);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.begin(), + 2, 2);
	PrintVector(v, v2);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	v.insert(v.end(), v2.begin() + 1, v2.end() - 2);
	PrintVector(v, v2);

	v.push_back(666);
	v.push_back(666);
	v.push_back(666);
	PrintVector(v, v2);

	v.pop_back();
	v.pop_back();
	PrintVector(v, v2);

	//v.swap(v2);
	//PrintVector(v, v2);

	cout << "First element : " << v.front() << endl;
	cout << "Last element : " << v.back() << endl;
	
	v.resize(4);
	PrintVector(v, v2);
	v.shrink_to_fit();
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	*/
	cout << "-----------------------------------" << endl;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]==6){
			v.insert(v.begin() + i, 6); i++;
		}
	}
	PrintVector(v, v2);
}
