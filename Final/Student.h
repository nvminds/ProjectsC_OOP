#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student
{
	struct PIB{
		string name;
		string surname;
		string lastname;
	};
	struct Date {
		int day;
		int month;
		int year;
	};
	static int counter;
	int id;
	PIB pib;
	Date birthday;
	void setId(int id);
	static void setCounter(int){}
public:
	Student();
	Student(string name, string surname, string lastname, int day, int month, int year);
	void setName(string n);
	void setSurName(string sn);
	void setLastName(string ln);
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	string getName() const;
	string getSurName() const;
	string getLastName() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	int getId()const;
	friend ostream& operator<<(ostream& os, const Student& s);
	friend ostream& saveStudent(ostream& os, const Student& s);
	friend class Journal;
};

