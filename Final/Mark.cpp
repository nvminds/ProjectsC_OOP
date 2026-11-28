#include "Mark.h"
int Mark::counter = 0;

void Mark::setId(int id) { this->id = id; }

Mark::Mark() :id(++counter), studentId(0), subjectId(0), value(0), markType(None) {}

Mark::Mark(int studentID, int subjectID, int value, MarkType type) : Mark() {
	setStudentID(studentID);
	setSubjectID(subjectID);
	setValue(value);
	setMarkType(type);
}

void Mark::setStudentID(int studentID) {
	if (studentID < 1) {
		throw invalid_argument("Id can't be less than 1!");
	}
	this->studentId = studentID;
}

void Mark::setSubjectID(int subjectID) {
	if (subjectID < 1) {
		throw invalid_argument("Id can't be less than 1!");
	}
	this->subjectId = subjectID;
}

void Mark::setValue(int v) {
	if (v > 12 or v < 1) {
		throw invalid_argument("Invalid mark value! Mark can't be less than 1 and over 12!");
	}
	this->value = v;
}

void Mark::setMarkType(MarkType t) {
	switch (t)
	{
	case Def:
		this->markType = t;
		break;
	case Test:
		this->markType = t;
		break;
	default:
		throw invalid_argument("Invalid mark type! Enter Def or Test!!!");
		break;
	}
}

int Mark::getStudentID()const { return studentId; }

int Mark::getSubjectID()const { return subjectId; }

int Mark::getValue()const { return value; }

int Mark::getId() const { return this->id; }

MarkType Mark::getMarkType()const { return markType; }

ostream& operator<<(ostream& os, const Mark& m) {
	os << "Id : " << m.id << endl;
	os << "Student Id : " << m.studentId << endl;
	os << "Subject Id : " << m.subjectId << endl;
	os << "Mark : " << m.value << endl;
	os << "Mark type : ";
	switch (m.markType)
	{
	case None:
		os << "None" << endl;
		break;
	case Def:
		os << "Default" << endl;
		break;
	case Test:
		os << "Test" << endl;
		break;
	}
	return os;
}

ostream& saveMark(ostream& os, const Mark& s) {
	os << s.id << ";" << s.studentId << ";" << s.subjectId << ";" << s.value << ";" << s.markType << "\n";
	return os;
}
