#include "Journal.h"

COORD SavePos();
void ClearFrom(COORD pos);
int readInt();

int main()
{
    int choice=-1;
    Journal j;
    do {
        system("cls");
        cout << "------------------------ Choose -----------------------" << endl;
        cout << "         Students                      --->     [1]" << endl;
        cout << "         Subjects                      --->     [2]" << endl;
        cout << "         Marks                         --->     [3]" << endl;
        cout << "         Average mark                  --->     [4]" << endl;
        cout << "         Files                         --->     [5]" << endl;
        cout << "         Marks table                   --->     [6]" << endl;
        cout << endl;
        cout << "         Exit                          --->     [0]" << endl;
        cout << endl;
        try
        {
            cout << "Enter choice >> "; cin >> choice;
            cin.ignore();
            cout << endl;
            switch (choice)
            {
            case 0:
                cout << "Goodbye!" << endl;
                break;
            case 1:
            {
                system("cls");
                COORD menuPos = SavePos();
                int choice1 = -1;
                do {
                    ClearFrom(menuPos);
                    cout << "------------------------ Choose -----------------------" << endl;
                    cout << "         Add student                   --->     [1]" << endl;
                    cout << "         Show students                 --->     [2]" << endl;
                    cout << "         Change student                --->     [3]" << endl;
                    cout << "         Remove student                --->     [4]" << endl;
                    cout << endl;
                    cout << "         Exit                          --->     [0]" << endl;
                    cout << endl;
                    try
                    {
                        cout << "Enter choice >> "; cin >> choice1;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            choice1 = -1;
                            cout << endl;
                            throw invalid_argument("Enter choice by numbers!");
                        }
                        cin.ignore();
                        cout << endl;
                        switch (choice1)
                        {
                        case 0:
                            break;
                        case 1:
                        {
                            string name, surname, lastname;
                            int day, month, year;
                            cout << "Enter name >> "; cin >> name;
                            cout << "Enter surname >> "; cin >> surname;
                            cout << "Enter lastname >> "; cin >> lastname;
                            cout << "Enter birthdate : " << endl;
                            cout << "Enter day >> "; day = readInt();
                            cout << "Enter month >> "; month = readInt();
                            cout << "Enter year >> "; year = readInt();
                            j.addStudent(Student(name, surname, lastname, day, month, year));
                            cout << endl;
                            cout << "Student added" << endl;
                            break;
                        }
                        case 2:
                            j.showStudents();
                            break;
                        case 3:
                        {
                            int id = -1;
                            cout << "Enter student id >> "; id = readInt();
                            string name, surname, lastname;
                            int day, month, year;
                            cout << "Enter new name >> "; cin >> name;
                            cout << "Enter new surname >> "; cin >> surname;
                            cout << "Enter new lastname >> "; cin >> lastname;
                            cout << "Enter new birthdate : " << endl;
                            cout << "Enter new day >> "; day = readInt();
                            cout << "Enter new month >> "; month = readInt();
                            cout << "Enter new year >> "; year = readInt();
                            j.changeStudent(id, name, surname, lastname, day, month, year);
                            cout << endl;
                            cout << "Student changed" << endl;
                            break;
                        }
                        case 4:
                        {
                            int id = -1;
                            cout << "Enter student id >> "; id = readInt();
                            j.removeStudent(id);
                            cout << endl;
                            cout << "Student removed" << endl;
                            break;
                        }
                        default:
                            throw invalid_argument("Wrong choice number!");
                            break;
                        }
                        if (choice1 != 0)
                        {
                            cout << endl; cout << endl;
                            cout << "Press any key to continue...." << endl;
                            _getch();
                        }
                    }
                    catch (length_error ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (invalid_argument ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (runtime_error ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (exception ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (...)
                    {
                        cout << "Unknown error" << endl;
                        _getch();
                    }

                } while (choice1 != 0);
            }
            break;
            case 2:
            {
                system("cls");
                COORD menuPos = SavePos();
                int choice2 = -1;
                do {
                    ClearFrom(menuPos);
                    cout << "------------------------ Choose -----------------------" << endl;
                    cout << "         Add subject                   --->     [1]" << endl;
                    cout << "         Show subjects                 --->     [2]" << endl;
                    cout << "         Change subject                --->     [3]" << endl;
                    cout << "         Remove subject                --->     [4]" << endl;
                    cout << endl;
                    cout << "         Exit                          --->     [0]" << endl;
                    cout << endl;
                    try
                    {
                        cout << "Enter choice >> "; cin >> choice2;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            choice2 = -1;
                            cout << endl;
                            throw invalid_argument("Enter choice by numbers!");
                        }
                        cin.ignore(1000, '\n');
                        cout << endl;
                        switch (choice2)
                        {
                        case 0:
                            break;
                        case 1:
                        {
                            string name;
                            int count;
                            cout << "Enter subject name >> "; getline(cin, name);
                            cout << "Enter subject count for a week >> "; count = readInt();
                            j.addSubject(Subject(name, count));
                            cout << endl;
                            cout << "Subject added" << endl;
                            break;
                        }
                        case 2:
                            j.showSubjects();
                            break;
                        case 3:
                        {
                            int id = -1;
                            cout << "Enter subject id >> "; id = readInt();
                            string name;
                            int count;
                            cout << "Enter new subject name >> "; getline(cin, name);
                            cout << "Enter new subject count for a week >> "; count = readInt();
                            j.changeSubject(id, name, count);
                            cout << endl;
                            cout << "Subject changed" << endl;
                            break;
                        }
                        case 4:
                        {
                            int id = -1;
                            cout << "Enter subject id >> "; id = readInt();
                            j.removeSubject(id);
                            cout << endl;
                            cout << "Subject removed" << endl;
                            break;
                        }
                        default:
                            throw invalid_argument("Wrong choice number!");
                            break;
                        }
                        if (choice2 != 0)
                        {
                            cout << endl; cout << endl;
                            cout << "Press any key to continue...." << endl;
                            _getch();
                        }
                    }
                    catch (length_error ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (invalid_argument ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (runtime_error ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (exception ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (...)
                    {
                        cout << "Unknown error" << endl;
                        _getch();
                    }
                } while (choice2 != 0);
            }
            break;
            case 3:
            {
                system("cls");
                COORD menuPos = SavePos();
                int choice3 = -1;
                do {
                    ClearFrom(menuPos);
                    cout << "------------------------ Choose -----------------------" << endl;
                    cout << "         Add mark                      --->     [1]" << endl;
                    cout << "         Show marks                    --->     [2]" << endl;
                    cout << "         Change mark                   --->     [3]" << endl;
                    cout << "         Remove mark                   --->     [4]" << endl;
                    cout << endl;
                    cout << "         Exit                          --->     [0]" << endl;
                    cout << endl;
                    try
                    {
                        cout << "Enter choice >> "; cin >> choice3;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            choice3 = -1;
                            cout << endl;
                            throw invalid_argument("Enter choice by numbers!");
                        }
                        cin.ignore();
                        cout << endl;
                        switch (choice3)
                        {
                        case 0:
                            break;
                        case 1:
                        {
                            int studentID = -1;
                            int subjectID = -1;
                            int mark = -1;
                            int typeChoice = 0;
                            MarkType type = None;
                            cout << endl;
                            cout << "Enter student id >> "; studentID = readInt();
                            cout << "Enter subject id >> "; subjectID = readInt();
                            cout << "Enter mark >> "; mark = readInt();
                            cout << "Enter mark type (Default - [1] or Test - [2]) >> "; typeChoice = readInt();
                            if (typeChoice == 1) {
                                type = MarkType::Def;
                            }
                            else if (typeChoice == 2) {
                                type = MarkType::Test;
                            }
                            else {
                                throw invalid_argument("Wrong mark type!");
                            }
                            j.addMark(Mark(studentID, subjectID, mark, type));
                            cout << endl;
                            cout << "Mark added" << endl;
                            break;
                        }
                        case 2:
                            j.showMarks();
                            break;
                        case 3:
                        {
                            int markID = -1;
                            int studentID = -1;
                            int subjectID = -1;
                            int mark = -1;
                            int typeChoice = 0;
                            MarkType type = None;
                            cout << endl;
                            cout << "Enter mark id >> "; markID = readInt();
                            cout << "Enter new student id >> "; studentID = readInt();
                            cout << "Enter new subject id >> "; subjectID = readInt();
                            cout << "Enter new mark >> "; mark = readInt();
                            cout << "Enter new mark type (Default - [1] or Test - [2]) >> "; typeChoice = readInt();
                            if (typeChoice == 1) {
                                type = MarkType::Def;
                            }
                            else if (typeChoice == 2) {
                                type = MarkType::Test;
                            }
                            else {
                                throw invalid_argument("Wrong mark type!");
                            }
                            j.changeMark(markID, studentID, subjectID, mark, type);
                            cout << endl;
                            cout << "Mark changed" << endl;
                            break;
                        }
                        case 4:
                        {
                            int markID = -1;
                            cout << "Enter mark id >> "; markID = readInt();
                            j.removeMark(markID);
                            cout << endl;
                            cout << "Mark removed" << endl;
                            break;
                        }
                        default:
                            throw invalid_argument("Wrong choice number!");
                            break;
                        }
                        if (choice3 != 0)
                        {
                            cout << endl; cout << endl;
                            cout << "Press any key to continue...." << endl;
                            _getch();
                        }
                    }
                    catch (length_error ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (invalid_argument ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (runtime_error ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (exception ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (...)
                    {
                        cout << "Unknown error" << endl;
                        _getch();
                    }

                } while (choice3 != 0);
            }
            break;
            case 4:
            {
                int id = -1;
                j.showSubjects();
                cout << "Enter subject id >> "; id = readInt();
                float avg = j.averageBySubject(id);
                cout << "Average mark : " << avg << endl;
            }
            break;
            case 5:
            {
                system("cls");
                COORD menuPos = SavePos();
                int choice5 = -1;
                do {
                    ClearFrom(menuPos);
                    cout << "------------------------ Choose -----------------------" << endl;
                    cout << "         Save students                 --->     [1]" << endl;
                    cout << "         Load students                 --->     [2]" << endl;
                    cout << "         Save subjects and marks       --->     [3]" << endl;
                    cout << "         Load subjects and marks       --->     [4]" << endl;
                    cout << "         Save all                      --->     [5]" << endl;
                    cout << "         Load all                      --->     [6]" << endl;
                    cout << endl;
                    cout << "         Exit                          --->     [0]" << endl;
                    cout << endl;
                    try
                    {
                        cout << "Enter choice >> "; cin >> choice5;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            choice5 = -1;
                            cout << endl;
                            throw invalid_argument("Enter choice by numbers!");
                        }
                        cin.ignore();
                        cout << endl;
                        switch (choice5)
                        {
                        case 0:
                            break;
                        case 1:
                        {
                            j.saveStudents("students.txt");
                            cout << endl;
                            cout << "Students saved" << endl;
                            break;
                        }
                        case 2:
                            j.loadStudents("students.txt");
                            cout << endl;
                            cout << "Students loaded" << endl;
                            break;
                        case 3:
                        {
                            j.saveSubjects("subjects.txt");
                            j.saveMarks("marks.txt");
                            cout << endl;
                            cout << "Subjects and marks saved" << endl;
                            break;
                        }
                        case 4:
                        {
                            j.loadSubjects("subjects.txt");
                            j.loadMarks("marks.txt");
                            cout << endl;
                            cout << "Subjects and marks loaded" << endl;
                            break;
                        }
                        case 5:
                        {
                            j.saveAll("students.txt", "subjects.txt", "marks.txt");
                            cout << endl;
                            cout << "All files saved" << endl;
                            break;
                        }
                        case 6:
                        {
                            j.loadAll("students.txt", "subjects.txt", "marks.txt");
                            cout << endl;
                            cout << "All files loaded" << endl;
                            break;
                        }
                        default:
                            throw invalid_argument("Wrong choice number!");
                            break;
                        }
                        if (choice5 != 0)
                        {
                            cout << endl; cout << endl;
                            cout << "Press any key to continue...." << endl;
                            _getch();
                        }
                    }
                    catch (length_error ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (invalid_argument ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (runtime_error ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (exception ex)
                    {
                        cout << ex.what() << endl;
                        _getch();
                    }
                    catch (...)
                    {
                        cout << "Unknown error" << endl;
                        _getch();
                    }

                } while (choice5 != 0);
            }
                break;
            case 6:
                j.showMarksTable();
                break;
            default:
                throw invalid_argument("Wrong choice number!");
                break;
            }
            if (choice != 0)
            {
                cout << endl; cout << endl;
                cout << "Press any key to continue...." << endl;
                _getch();
            }
        }
        catch (length_error ex)
        {
            cout << ex.what() << endl;
        }
        catch (invalid_argument ex)
        {
            cout << ex.what() << endl;
        }
        catch (runtime_error ex)
        {
            cout << ex.what() << endl;
        }
        catch (exception ex)
        {
            cout << ex.what() << endl;
        }
        catch (...)
        {
            cout << "Unknown error" << endl;
        }
        
    } while(choice!=0);
}

COORD SavePos()
{
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
    return info.dwCursorPosition;
}
void ClearFrom(COORD pos)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(h, &info);
    DWORD written;
    FillConsoleOutputCharacter(h, ' ', info.dwSize.X * info.dwSize.Y, pos, &written);
    SetConsoleCursorPosition(h, pos);
}
int readInt(){
    int x;
    cin >> x;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << endl;
        throw invalid_argument("Enter numbers!");
    }
    cin.ignore(1000, '\n');
    return x;
}