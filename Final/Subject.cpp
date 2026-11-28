#include "Subject.h"
int Subject::counter = 0;

void Subject::setId(int id) { this->id = id; }

Subject::Subject() :id(++counter), subjName("none"), countOnWeek(0) {}

Subject::Subject(string name, int count) :Subject(){
	setSubjectName(name);
	setCount(count);
}

void Subject::setSubjectName(string n) {
	if (n.empty()) {
		throw length_error("Subject name can't be 0 letters!");
	}
	this->subjName = n;
}

void Subject::setCount(int c) {
	if (c > 10 or c < 1) {
		throw invalid_argument("Subject can't be less than 1 and over 10 times a week!");
	}
	this->countOnWeek = c; 
}

int Subject::getId() const { return this->id; }

string Subject::getSubjectName() const { return this->subjName; }

int Subject::getCount() const { return this->countOnWeek; }

ostream& operator<<(ostream& os, const Subject& s) {
	os << "Id : " << s.id << endl;
	os << "Subject name : " << s.subjName << endl;
	os << "Subject count on week : " << s.countOnWeek << endl;
	return os;
}

ostream& saveSubject(ostream& os, const Subject& s) {
	os << s.id << ";" << s.subjName << ";" << s.countOnWeek << "\n";
	return os;
}