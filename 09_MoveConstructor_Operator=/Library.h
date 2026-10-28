#pragma once
#include "Book.h"
class Library
{
	string name;
	string adress;
	Book* books;
	int count_books;
public:
	Library();
	Library(string name, string adress);
	Library(const Library& other);
	~Library();
	Library& operator = (const Library&other);
	Library(Library&&other);
	void showLibrary()const;
	void addBook(Book b);
};

