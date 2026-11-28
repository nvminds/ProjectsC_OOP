#include "Journal.h"

int Journal::FindStudentByID(int id) {
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getId() == id) {
			return i;
		}
	}
	return -1;
}

int Journal::FindSubjectByID(int id) {
	for (int i = 0; i < subjects.size(); i++)
	{
		if (subjects[i].getId() == id) {
			return i;
		}
	}
	return -1;
}

int Journal::FindMarkByID(int id) {
	for (int i = 0; i < marks.size(); i++)
	{
		if (marks[i].getId() == id) {
			return i;
		}
	}
	return -1;
}

void Journal::addStudent(const Student& s) {
	students.push_back(s);
}

void Journal::changeStudent(int id, string name, string surname, string lastname, int day, int month, int year) {
	int index = FindStudentByID(id);
	if (index != -1) {
		Student temp = students[index];
		temp.setName(name);
		temp.setSurName(surname);
		temp.setLastName(lastname);
		temp.setDay(day);
		temp.setMonth(month);
		temp.setYear(year);
		students[index] = temp;
	}
	else {
		throw invalid_argument("Student with this id not exists.");
	}
}

void Journal::removeStudent(int id) {
	int index = FindStudentByID(id);
	if (index != -1) {
		for (int i = (int)marks.size() - 1; i != -1; i--)
		{
			if (marks[i].getStudentID() == id) {
				marks.erase(marks.begin() + i);
			}
		}
		students.erase(students.begin() + index);
	}
	else {
		throw invalid_argument("Student with this id not exists.");
	}
}

void Journal::addSubject(const Subject& s) {
	subjects.push_back(s);
}

void Journal::changeSubject(int id, string name, int count) {
	int index = FindSubjectByID(id);
	if (index != -1) {
		Subject temp = subjects[index];
		temp.setSubjectName(name);
		temp.setCount(count);
		subjects[index] = temp;
	}
	else {
		throw invalid_argument("Subject with this id not exists.");
	}
}

void Journal::removeSubject(int id) {
	int index = FindSubjectByID(id);
	if (index != -1) {
		for (int i = (int)marks.size() - 1; i != -1; i--)
		{
			if (marks[i].getSubjectID() == id) {
				marks.erase(marks.begin() + i);
			}
		}
		subjects.erase(subjects.begin() + index);
	}
	else {
		throw invalid_argument("Subject with this id not exists.");
	}
}

void Journal::addMark(const Mark& m) {
	if (FindStudentByID(m.getStudentID()) == -1) {
		throw invalid_argument("Student with this id not exists.");
	}
	if (FindSubjectByID(m.getSubjectID()) == -1) {
		throw invalid_argument("Subject with this id not exists.");
	}
	marks.push_back(m);
}

void Journal::changeMark(int id, int studentID, int subjectID, int value, MarkType type) {
	int index = FindMarkByID(id);
	if (index == -1) {
		throw invalid_argument("Mark with this id not exists.");
	}
	if (FindStudentByID(studentID) == -1) {
		throw invalid_argument("Student with this id not exists.");
	}
	if (FindSubjectByID(subjectID) == -1) {
		throw invalid_argument("Subject with this id not exists.");
	}
	Mark temp = marks[index];
	temp.setStudentID(studentID);
	temp.setSubjectID(subjectID);
	temp.setValue(value);
	temp.setMarkType(type);
	marks[index] = temp;
}

void Journal::removeMark(int id) {
	int index = FindMarkByID(id);
	if (index != -1) {
		marks.erase(marks.begin() + index);
	}
	else {
		throw invalid_argument("Mark with this id not exists.");
	}
}

float Journal::averageBySubject(int subjectID) {
	if (FindSubjectByID(subjectID) == -1) {
		throw invalid_argument("Subject with this id not exists.");
	}
	float summ = 0;
	int count = 0;
	for (int i = 0; i < marks.size(); i++)
	{
		if (marks[i].getSubjectID() == subjectID) {
			summ += marks[i].getValue();
			count++;
		}
	}
	if (count == 0) {
		throw runtime_error("Marks count in this subject is 0. We can't divide by zero!!");
	}
	return summ / count;
}

void Journal::showStudents() {
	if (students.empty()) {
		throw length_error("Empty students list");
	}
	Table t({ 4, 16, 16, 16, 13 });
	t.top();
	t.row({"ID", "Name", "Surname", "Lastname", "Birthday"});
	t.middle();
	for (int i = 0; i < students.size(); i++)
	{
		string birthday = to_string(students[i].getDay()) + "/" + to_string(students[i].getMonth()) + "/" + to_string(students[i].getYear());
		t.row({ to_string(students[i].getId()), students[i].getName(), students[i].getSurName(), students[i].getLastName(), birthday });
		if (i != students.size() - 1) {
			t.middle();
		}
	}
	t.bottom();
}

void Journal::showSubjects() {
	if (subjects.empty()) {
		throw length_error("Empty subjects list");
	}
	Table t({ 4, 24, 10 });
	t.top();
	t.row({ "ID", "Name", "Lessons" });
	t.middle();
	for (int i = 0; i < subjects.size(); i++)
	{
		t.row({ to_string(subjects[i].getId()), subjects[i].getSubjectName() ,to_string(subjects[i].getCount()) });
		if (i != subjects.size() - 1) {
			t.middle();
		}
	}
	t.bottom();
}

void Journal::showMarks() {
	if (marks.empty()) {
		throw length_error("Empty marks list");
	}
	Table t({ 4, 20, 20, 6, 10 });
	t.top();
	t.row({ "ID", "Student", "Subject", "Mark", "Type" });
	t.middle();
	for (int i = 0; i < marks.size(); i++)
	{
		string studentName, studentSurname, subjectName, typeName;
		int studentID = FindStudentByID(marks[i].getStudentID());
		if (studentID == -1) {
			studentName = "?";
			studentSurname = "?";
		}
		else {
			studentName = students[studentID].getName();
			studentSurname = students[studentID].getSurName();
		}
		int subjectID = FindSubjectByID(marks[i].getSubjectID());
		if (subjectID == -1) {
			subjectName = "?";
		}
		else {
			subjectName = subjects[subjectID].getSubjectName();
		}
		if (marks[i].getMarkType() == 1) {
			typeName = "Default";
		}
		else if (marks[i].getMarkType() == 2) {
			typeName = "Test";
		}
		else {
			typeName = "None";
		}

		t.row({ to_string(marks[i].getId()), studentName + " " + studentSurname,
				subjectName, to_string(marks[i].getValue()), typeName });

		if (i != marks.size() - 1) {
			t.middle();
		}
	}
	t.bottom();
}

void Journal::saveStudents(string filename) {
	ofstream out(filename);
	if (!out.is_open()) {
		throw runtime_error("Can't open file");
	}
	for (int i = 0; i < students.size(); i++)
	{
		saveStudent(out, students[i]);
	}
	out.close();
}

void Journal::loadStudents(string filename) {
	students.clear();
	ifstream in(filename);
	if (!in.is_open()) {
		throw runtime_error("Can't open file");
	}
	string id_s, name_s, surname_s, lastname_s, day_s, mounth_s, year_s;
	string line;
	int maxId = 0;
	while (getline(in, line))
	{
		stringstream stream(line);
		if (line.empty()) continue;
		getline(stream, id_s, ';');
		getline(stream, name_s, ';');
		getline(stream, surname_s, ';');
		getline(stream, lastname_s, ';');
		getline(stream, day_s, ';');
		getline(stream, mounth_s, ';');
		getline(stream, year_s, ';');
		int id = stoi(id_s);
		int day = stoi(day_s);
		int month = stoi(mounth_s);
		int year = stoi(year_s);

		Student s(name_s, surname_s, lastname_s, day, month, year);
		s.setId(id);
		students.push_back(s);
		if (id > maxId) {
			maxId = id;
		}
	}
	Student::setCounter(maxId);
}

void Journal::saveSubjects(string filename) {
	ofstream out(filename);
	if (!out.is_open()) {
		throw runtime_error("Can't open file");
	}
	for (int i = 0; i < subjects.size(); i++)
	{
		saveSubject(out, subjects[i]);
	}
	out.close();
}

void Journal::loadSubjects(string filename) {
	subjects.clear();
	ifstream in(filename);
	if (!in.is_open()) {
		throw runtime_error("Can't open file");
	}
	string id_s, name_s, count_s;
	string line;
	int maxId = 0;
	while (getline(in, line))
	{
		stringstream stream(line);
		if (line.empty()) continue;
		getline(stream, id_s, ';');
		getline(stream, name_s, ';');
		getline(stream, count_s, ';');
		int id = stoi(id_s);
		int count = stoi(count_s);

		Subject s(name_s, count);
		s.setId(id);
		subjects.push_back(s);
		if (id > maxId) {
			maxId = id;
		}
	}
	Subject::setCounter(maxId);
}

void Journal::saveMarks(string filename) {
	ofstream out(filename);
	if (!out.is_open()) {
		throw runtime_error("Can't open file");
	}
	for (int i = 0; i < marks.size(); i++)
	{
		saveMark(out, marks[i]);
	}
	out.close();
}

void Journal::loadMarks(string filename) {
	marks.clear();
	ifstream in(filename);
	if (!in.is_open()) {
		throw runtime_error("Can't open file");
	}
	string id_s, studentID_s, subjectID_s, value_s, markType_s;
	MarkType markType;
	string line;
	int maxId = 0;
	while (getline(in, line))
	{
		stringstream stream(line);
		if (line.empty()) continue;
		getline(stream, id_s, ';');
		getline(stream, studentID_s, ';');
		getline(stream, subjectID_s, ';');
		getline(stream, value_s, ';');
		getline(stream, markType_s, ';');
		int id = stoi(id_s);
		int studentID = stoi(studentID_s);
		int subjectID = stoi(subjectID_s);
		int value = stoi(value_s);
		int typeChoice = stoi(markType_s);

		if (typeChoice == 1) {
			markType = MarkType::Def;
		}
		else if (typeChoice == 2) {
			markType = MarkType::Test;
		}
		else {
			throw invalid_argument("Wrong mark type!");
		}
		Mark s(studentID, subjectID, value, markType);
		s.setId(id);
		if (FindStudentByID(studentID) == -1) {
			throw invalid_argument("Student with this id not exists.");
		}
		if (FindSubjectByID(subjectID) == -1) {
			throw invalid_argument("Subject with this id not exists.");
		}
		marks.push_back(s);
		if (id > maxId) {
			maxId = id;
		}
	}
	Mark::setCounter(maxId);
}

void Journal::saveAll(string f1, string f2, string f3) {
	saveStudents(f1);
	saveSubjects(f2);
	saveMarks(f3);
}

void Journal::loadAll(string f1, string f2, string f3) {
	loadStudents(f1);
	loadSubjects(f2);
	loadMarks(f3);
}

void Journal::showMarksTable() {
	if (marks.empty()) throw length_error("Empty marks list");
	Table t({ 22, 20, 16, 14, 8 });
	t.top();
	t.row({ "Student", "Subject", "Default", "Test", "Avg" });
	t.middle();
	bool anyPrinted = false;
	for (int s = 0; s < students.size(); s++)
	{
		bool first = true;
		for (int l = 0; l < subjects.size(); l++)
		{
			string defMark, testMark;
			stringstream stream;
			int count = 0;
			float summ = 0;
			for (int i = 0; i < marks.size(); i++)
			{
				if (marks[i].getStudentID() == students[s].getId() and marks[i].getSubjectID() == subjects[l].getId()) {
					if (marks[i].getMarkType() == Def) {
						if (!defMark.empty()) {
							defMark += ", ";
							defMark += to_string(marks[i].getValue());
						}
						else {
							defMark += to_string(marks[i].getValue());
						}
					}
					else if (marks[i].getMarkType() == Test) {
						if (!testMark.empty()) {
							testMark += ", ";
							testMark += to_string(marks[i].getValue());
						}
						else {
							testMark += to_string(marks[i].getValue());
						}
					}
					summ += marks[i].getValue();
					count++;
				}
			}
			if (count == 0) continue;

			float avg = summ / count;
			string studentName = students[s].getName();
			string studentSurName = students[s].getSurName();
			stream << fixed << setprecision(1) << avg;
			string studentPI = studentName + " " + studentSurName;
			if (first == false) {
				studentPI = "";
			}
			if (defMark.empty()) {
				defMark = "-";
			}
			if (testMark.empty()) {
				testMark = "-";
			}
			if (first and anyPrinted)t.middle();
			t.row({ studentPI, subjects[l].getSubjectName(), defMark, testMark, stream.str() });
			first = false;
			anyPrinted = true;
		}
	}
	t.bottom();
}
