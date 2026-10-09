#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char* filename = "Students.txt";

struct Birthdate
{
    int day;
    int month;
    int year;
};

class Student
{
    string name;
    string surname;
    string lastname;
    Birthdate birthdate;
    string phone_numb;
    string city;
    string country;
    string school;
    string school_city;
    string school_country;
    string group_numb;

public:
    void setName(string name)
    {
        this->name = name;
    }
    void setSurname(string surname)
    {
        this->surname = surname;
    }
    void setLastname(string lastname)
    {
        this->lastname = lastname;
    }
    void setBirthdate(Birthdate birthdate) 
    {
        this->birthdate = birthdate;
    }
    void setStudentPhoneNumber(string phone_numb)
    {
        this->phone_numb = phone_numb;
    }
    void setStudentCity(string city)
    {
        this->city = city;
    }
    void setStudentCountry(string country)
    {
        this->country = country;
    }
    void setStudentSchool(string school)
    {
        this->school = school;
    }
    void setSchoolCity(string school_city)
    {
        this->school_city = school_city;
    }
    void setSchoolCountry(string school_country)
    {
        this->school_country = school_country;
    }
    void setStudentGroupNumber(string group_numb)
    {
        this->group_numb = group_numb;
    }


    string getName()
    {
        return name;
    }
    string getSurname()
    {
        return surname;
    }
    string getLastname()
    {
        return lastname;
    }
    Birthdate getBirthdate()
    {
        return birthdate;
    }
    string getStudentPhoneNumber()
    {
        return phone_numb;
    }
    string getStudentCity()
    {
        return city;
    }
    string getStudentCountry()
    {
        return country;
    }
    string getStudentSchool()
    {
        return school;
    }
    string getSchoolCity()
    {
        return school_city;
    }
    string getSchoolCountry()
    {
        return school_country;
    }
    string getStudentGroupNumber()
    {
        return group_numb;
    }

    void saveToFile()
    {
        ofstream out(filename, ios_base::app);
        out << name;
        out << ':';
        out << surname;
        out << ':';
        out << lastname;
        out << ':';
        out << birthdate.day << "/" << birthdate.month << "/" << birthdate.year;
        out << ':';
        out << phone_numb;
        out << ':';
        out << city;
        out << ':';
        out << country;
        out << ':';
        out << school;
        out << ':';
        out << school_city;
        out << ':';
        out << school_country;
        out << ':';
        out << group_numb;
        out << '|';
        out.close();
    }
    void readFromFile()
    {
        ifstream in(filename, ios_base::in);
        string Bname, Bsurname, Blastname, Bbirthdate_day, Bbirthdate_month, Bbirthdate_year, 
            Bphone_numb, Bcity, Bcountry, Bschool, Bschool_city, Bschool_country, Bgroup_numb;
        while (!in.eof())
        {
            getline(in, Bname, ':');
            if (in.eof())
            {
                break;
            }
            getline(in, Bsurname, ':');
            getline(in, Blastname, ':');
            getline(in, Bbirthdate_day, '/');
            getline(in, Bbirthdate_month, '/');
            getline(in, Bbirthdate_year, ':');
            getline(in, Bphone_numb, ':');
            getline(in, Bcity, ':');
            getline(in, Bcountry, ':');
            getline(in, Bschool, ':');
            getline(in, Bschool_city, ':');
            getline(in, Bschool_country, ':');
            getline(in, Bgroup_numb, '|');

            name = Bname;
            surname = Bsurname;
            lastname = Blastname;
            birthdate.day = atoi((Bbirthdate_day).c_str());
            birthdate.month = atoi((Bbirthdate_month).c_str());
            birthdate.year = atoi((Bbirthdate_year).c_str());
            phone_numb = Bphone_numb;
            city = Bcity;
            country = Bcountry;
            school = Bschool;
            school_city = Bschool_city;
            school_country = Bschool_country;
            group_numb = Bgroup_numb;

        }
    }
};


int main()
{
    Student st1;
    string name, surname, lastname, phone_numb, city, country, school, school_city, school_country, group_numb;
    Birthdate birthdate;
    st1.readFromFile(); 
    cout << "Enter student name >> "; getline(cin, name);
    st1.setName(name);
    cout << "Enter student surname >> "; getline(cin, surname);
    st1.setSurname(surname);
    cout << "Enter student lastname >> "; getline(cin, lastname);
    st1.setLastname(lastname);
    cout << "Enter student birthdate day >> "; cin >> birthdate.day;
    cout << "Enter student birthdate month >> "; cin >> birthdate.month;
    cout << "Enter student birthdate year >> "; cin >> birthdate.year;
    st1.setBirthdate(birthdate);
    cin.ignore();
    cout << "Enter student phone number >> "; getline(cin, phone_numb);
    st1.setStudentPhoneNumber(phone_numb);
    cout << "Enter student city >> "; getline(cin, city);
    st1.setStudentCity(city);
    cout << "Enter student country >> "; getline(cin, country);
    st1.setStudentCountry(country);
    cout << "Enter student school >> "; getline(cin, school);
    st1.setStudentSchool(school);
    cout << "Enter student school city >> "; getline(cin, school_city);
    st1.setSchoolCity(school_city);
    cout << "Enter student school country >> "; getline(cin, school_country);
    st1.setSchoolCountry(school_country);
    cout << "Enter student group number >> "; getline(cin, group_numb);
    st1.setStudentGroupNumber(group_numb);
    
    cout << "PIB : " << st1.getName() << " " << st1.getSurname() << " "<< st1.getLastname() << endl;
    cout << "Birthdate : " << st1.getBirthdate().day << "/" << st1.getBirthdate().month << "/" << st1.getBirthdate().year << endl;
    cout << "Phone number : " << st1.getStudentPhoneNumber() << endl;
    cout << "Student location : " << st1.getStudentCity() << ", " << st1.getStudentCountry() << endl;
    cout << "Member of " << st1.getStudentSchool() << " school" << endl;
    cout << "School location : " << st1.getSchoolCity() << ", " << st1.getSchoolCountry() << endl;
    cout << "Student group number : " << st1.getStudentGroupNumber() << endl;

    st1.saveToFile();
}
