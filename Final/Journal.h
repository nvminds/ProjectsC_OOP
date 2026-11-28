#pragma once
#include "Student.h"
#include "Subject.h"
#include "Table.h"
#include "Mark.h"
#include <conio.h>
#include<windows.h>
#include <vector>
#include <fstream>
#include <sstream>
class Journal
{
	vector<Student> students;
	vector<Subject> subjects;
	vector<Mark> marks;
public:
	Journal() = default;
	int FindStudentByID(int id);
	int FindSubjectByID(int id);
	int FindMarkByID(int id);
	void addStudent(const Student& s);
	void changeStudent(int id, string name, string surname, string lastname, int day, int month, int year);
	void removeStudent(int id);
	void addSubject(const Subject& s);
	void changeSubject(int id, string name, int count);
	void removeSubject(int id);
	void addMark(const Mark& m);
	void changeMark(int id, int studentID, int subjectID, int value, MarkType type);
	void removeMark(int id);
	float averageBySubject(int subjectID);
	void showStudents();
	void showSubjects();
	void showMarks();
	void saveStudents(string filename);
	void loadStudents(string filename);
	void saveSubjects(string filename);
	void loadSubjects(string filename);
	void saveMarks(string filename);
	void loadMarks(string filename);
	void saveAll(string f1, string f2, string f3);
	void loadAll(string f1, string f2, string f3);
	void showMarksTable();
};

