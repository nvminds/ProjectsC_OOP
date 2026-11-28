#include "Student.h"
int Student::counter = 0;

void Student::setId(int id) { this->id = id; }

Student::Student() :id(++counter), pib({ "none", "none", "none" }), birthday({ 0,0,0 }) {}

Student::Student(string name, string surname, string lastname, int day, int month, int year): Student(){
	setName(name);
	setSurName(surname);
	setLastName(lastname);
	setDay(day);
	setMonth(month);
	setYear(year);
}

void Student::setName(string n) {
	if (n.empty()) {
		throw length_error("Name can't be 0 letters!");
	}
	for (int i = 0; i < n.size(); i++)
	{
		if (!isalpha(n[i])) {
			throw invalid_argument("Name must be ONLY with letters!");
		}
	}
	this->pib.name = n; 
}

void Student::setSurName(string sn) {
	if (sn.empty()) {
		throw length_error("Surname can't be 0 letters!");
	}
	for (int i = 0; i < sn.size(); i++)
	{
		if (!isalpha(sn[i])) {
			throw invalid_argument("Surname must be ONLY with letters!");
		}
	}
	this->pib.surname = sn;
}
void Student::setLastName(string ln) {
	if (ln.empty()) {
		throw length_error("Lastname can't be 0 letters!");
	}
	for (int i = 0; i < ln.size(); i++)
	{
		if (!isalpha(ln[i])) {
			throw invalid_argument("Lastname must be ONLY with letters!");
		}
	}
	this->pib.lastname = ln;
}
void Student::setDay(int d) { 
	if (d > 0 and d <= 31) {
		this->birthday.day = d; 
	}
	else {
		throw invalid_argument("Day can't be less than 1 and over 31!");
	}
}

void Student::setMonth(int m) { 
	if (m > 0 and m <= 12) {
		this->birthday.month = m;
	}
	else {
		throw invalid_argument("Month can't be less than 1 and over 12!");
	}
}

void Student::setYear(int y) {
	if (y > 0 and y <= 2026) {
		this->birthday.year = y;
	}
	else {
		throw invalid_argument("Year can't be less than 0 and over 2026!");
	}
}
string Student::getName() const { return this->pib.name; }

string Student::getSurName() const { return this->pib.surname; }

string Student::getLastName() const { return this->pib.lastname; }

int Student::getDay() const { return this->birthday.day; }

int Student::getMonth() const { return this->birthday.month; }

int Student::getYear() const { return this->birthday.year; }

int Student::getId() const { return this->id; }

ostream& operator<<(ostream& os, const Student& s){
	os << "Id : " << s.id << endl;
	os << "Full name : " << s.pib.name << " " << s.pib.surname << " " << s.pib.lastname << endl;
	os << "Birthday : " << s.birthday.day << "/" << s.birthday.month << "/" << s.birthday.year << endl;
	return os;
}
ostream& saveStudent(ostream& os, const Student& s) {
	os << s.id << ";" << s.pib.name << ";" << s.pib.surname << ";" << s.pib.lastname << ";"
		<< s.birthday.day << ";" << s.birthday.month << ";" << s.birthday.year << "\n";
	return os;
}