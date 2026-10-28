#include "Library.h"

Library::Library()
{
	name = "no name";
	adress = "no adress";
	books = nullptr;
	count_books = 0;
}

Library::Library(string name, string adress)
{
	this->name = name;
	this->adress = adress;
	books = nullptr;
	count_books = 0;
}

Library::Library(const Library& other)
{
	this->name = other.name;
	this->adress = other.adress;
	this->count_books = other.count_books;
	this->books = new Book[count_books];
	for (int i = 0; i < count_books; i++)
	{
		this->books[i] = other.books[i];
	}
	cout << "Copy CTOR " << endl;
}

Library::~Library()
{
	if (books != nullptr) { delete[]books; }
}

Library& Library::operator=(const Library& other)
{
	this->name = other.name;
	this->adress = other.adress;
	this->count_books = other.count_books;
	if (books != nullptr) { delete[]books; }
	this->books = new Book[count_books];
	for (int i = 0; i < count_books; i++)
	{
		this->books[i] = other.books[i];
	}
	cout << "Operator = " << endl;
	return *this;
}

Library::Library(Library&& other)
{
	this->name = other.name;
	this->adress = other.adress;
	this->count_books = other.count_books;
	this->books = other.books;
	other.books = nullptr;
	cout << "Move CTOR" << endl;
}

void Library::showLibrary()const
{
	cout << "Name Library : " << name << endl;
	cout << "Address Library : " << adress << endl;
	for (int i = 0; i < count_books; i++)
	{
		books[i].ShowInfo();
		cout << endl;
	}
}

void Library::addBook(Book b)
{
	Book* temp = new Book[count_books+1];
	for (int i = 0; i < count_books; i++)
	{
		temp[i] = books[i];
	}
	temp[count_books] = b;
	if (books!=nullptr){ delete[]books; }
	count_books++;
	books = temp;
}
