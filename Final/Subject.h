#pragma once
#include "Student.h"
class Subject
{
	static int counter;
	int id;
	string subjName;
	int countOnWeek;
	void setId(int id);
	static void setCounter(int){}
public:
	Subject();
	Subject(string name, int count);
	void setSubjectName(string n);
	void setCount(int c);
	int getId() const;
	string getSubjectName() const;
	int getCount() const;
	friend ostream& operator<<(ostream& os, const Subject& s);
	friend ostream& saveSubject(ostream& os, const Subject& s);
	friend class Journal;
};

