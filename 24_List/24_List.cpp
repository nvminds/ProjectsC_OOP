#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

void ShowList(list<int>&l1, list<int>&l2) {
	list<int>::iterator it;
	cout << "List 1 : ";
	for (it = l1.begin(); it != l1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << "List 2 : ";
	for (it = l2.begin(); it != l2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	cout << endl;
}

struct Book {
	string name;
	string author;
	int pages;
};


bool CompareBookByName(const Book& b1, const Book& b2) {
	return b1.name < b2.name;
}
bool CompareBookByAuthor(const Book& b1, const Book& b2) {
	return b1.author < b2.author;
}
bool CompareBookByPages(const Book& b1, const Book& b2) {
	return b1.pages < b2.pages;
}
int main()
{
	list<Book> library;
	library.push_back({ "name 3", "author 3", 65 });
	library.assign({ {"1984", "George Orwell", 328},{"The Great Gatsby", "F. Scott Fitzgerald", 472} });

	cout << "---------------Original lib----------------" << endl;
	for (Book b : library)
	{
		cout << setw(20) << b.name << setw(15) << b.author << setw(15) << b.pages << endl;
	}
	library.sort(CompareBookByName);
	cout << "---------------Sorted lib----------------" << endl;
	for (Book b : library)
	{
		cout << setw(20) << b.name << setw(15) << b.author << setw(15) << b.pages << endl;
	}
	library.sort(CompareBookByAuthor);
	cout << "---------------Sorted lib----------------" << endl;
	for (Book b : library)
	{
		cout << setw(20) << b.name << setw(15) << b.author << setw(15) << b.pages << endl;
	}
	library.sort(CompareBookByPages);
	cout << "---------------Sorted lib----------------" << endl;
	for (Book b : library)
	{
		cout << setw(20) << b.name << setw(15) << b.author << setw(15) << b.pages << endl;
	}




	/*
    list<int> l1, l2;
	cout << "Size :: " << l1.size() << endl;

	for (int i = 0; i < 10; i++)
	{
		l1.push_back(i);
		l2.push_front(i);
	}
	ShowList(l1, l2);

	l1.assign({ 333,67 });
	ShowList(l1, l2);

	list<int>::iterator it = l1.begin();
	it++;

	l1.erase(it);
	ShowList(l1, l2);

	l1.push_back(100);
	l1.push_front(200);
	ShowList(l1, l2);

	l1.insert(l1.begin(), 99);
	l1.insert(l1.begin(), {88,44,66,55});
	l1.insert(l1.end(), l2.begin(), l2.end());
	l1.insert(l1.begin(), 5, 777);
	ShowList(l1, l2);

	l1.remove(777);
	ShowList(l1, l2);

	l1.resize(30, 67);
	ShowList(l1, l2);

	l1.splice(l1.end(), l2, l2.begin());
	ShowList(l1, l2);

	l1.reverse();
	ShowList(l1, l2);

	l1.sort();
	l2.sort();
	ShowList(l1, l2);

	l1.merge(l2);
	ShowList(l1, l2);

	l1.unique();
	ShowList(l1, l2);

	l1.swap(l2);
	ShowList(l1, l2);
	*/

}
