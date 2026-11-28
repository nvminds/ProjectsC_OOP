#pragma once
#include "Student.h"

enum MarkType {None, Def, Test};

class Mark
{
	static int counter;
	int id;
	int studentId;  
	int subjectId;   
	int value;
	MarkType markType;
	void setId(int id);
	static void setCounter(int) {}
public:
	Mark();
	Mark(int studentID, int subjectID, int value, MarkType type);
	void setStudentID(int studentID);
	void setSubjectID(int subjectID);
	void setValue(int v);
	void setMarkType(MarkType t);
	int getStudentID()const;
	int getSubjectID()const;
	int getValue()const;
	int getId()const;
	MarkType getMarkType()const;
	friend ostream& operator<<(ostream& os, const Mark& m);
	friend ostream& saveMark(ostream& os, const Mark& s);
	friend class Journal;
};

