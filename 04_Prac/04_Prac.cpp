#include <iostream>
#include <string>
using namespace std;

struct PIB
{
    string name;
    string surname;
    string lastname;
};

class Abonent
{
    PIB pib;
    string home_phone;
    string work_phone;
    string personal_phone;
    string contact_info;
public:
    static int count_abonents;
    Abonent() :pib{ "no name", "no surname", "no lastname" }, home_phone("+000000000000"),
        work_phone("+000000000000"), personal_phone("+000000000000"), contact_info("usermail@gmail.com") {count_abonents++;}
    Abonent(string name, string surname, string lastname, string home_phone, string work_phone, string personal_phone, string contact_info): Abonent()
    {
        this->pib.name = name;
        this->pib.surname = surname;
        this->pib.lastname = lastname;
        this->home_phone = home_phone;
        this->work_phone = work_phone;
        this->personal_phone = personal_phone;
        this->contact_info = contact_info;
    }
    void Print()
    {
        cout << endl;
        cout << "Name : " << pib.name << endl;
        cout << "Surname : " << pib.surname << endl;
        cout << "Lastname : " << pib.lastname << endl;
        cout << "Home phone : " << home_phone << endl;
        cout << "Work phone : " << work_phone << endl;
        cout << "Personal phone : " << personal_phone << endl;
        cout << "Contact info : " << contact_info << endl;
    }

    void setName(string name) { this->pib.name = name; }
    void setSurname(string surname) { this->pib.surname = surname; }
    void setLastname(string lastname) { this->pib.lastname = lastname; }
    void setHomePhone(string home_phone) { this->home_phone = home_phone; }
    void setWorkPhone(string work_phone) { this->work_phone = work_phone; }
    void setPersonalPhone(string personal_phone) { this->personal_phone = personal_phone; }
    void setContactInfo(string contact_info) { this->contact_info = contact_info; }

    string getName() { return pib.name; }
    string getSurname() { return pib.surname; }
    string getLastname() { return pib.lastname; }
    string getHomePhone() { return home_phone; }
    string getWorkPhone() { return work_phone; }
    string getPersonalPhone() { return personal_phone; }
    string getContactInfo() { return contact_info; }
};

int Abonent::count_abonents = 0;
int main()
{
    string name, surname, lastname, home_phone, work_phone, personal_phone, contact_info;

    cout << "Count abonents : " << Abonent::count_abonents << endl;

    Abonent ab;
    ab.Print();
    cout << "Count abonents : " << ab.count_abonents << endl;

    Abonent ab1("Petro", "Kravchuk", "Vasilyovich", "+380674951283", "+380938126407", "+380503547918", "petro.dev.2026@gmail.com");
    ab1.Print();
    cout << "Count abonents : " << ab1.count_abonents << endl; cout << endl;

    Abonent ab2;
    cout << "Enter name >> "; getline(cin, name);
    ab2.setName(name);
    cout << "Enter surname >> "; getline(cin, surname);
    ab2.setSurname(surname);
    cout << "Enter lastname >> "; getline(cin, lastname);
    ab2.setLastname(lastname);
    cout << "Enter home phone >> "; getline(cin, home_phone);
    ab2.setHomePhone(home_phone);
    cout << "Enter work phone >> "; getline(cin, work_phone);
    ab2.setWorkPhone(work_phone);
    cout << "Enter personal phone >> "; getline(cin, personal_phone);
    ab2.setPersonalPhone(personal_phone);
    cout << "Enter contact info >> "; getline(cin, contact_info);
    ab2.setContactInfo(contact_info);
    
    ab2.getName();
    ab2.getSurname();
    ab2.getLastname();
    ab2.getHomePhone();
    ab2.getWorkPhone();
    ab2.getPersonalPhone();
    ab2.getContactInfo();
    
    ab2.Print();
    cout << "Count abonents : " << ab2.count_abonents << endl; cout << endl;
}

