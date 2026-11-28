#include <iostream>
#include <map>
#include <list>
using namespace std;

int main()
{
    map<string, int> m;
    //map<string, User> users;
    //map<string, list<string>> m;

    pair<string, int> p("Olya", 5);
    m.insert(p);

    m.insert(pair<string, int>("Ivan", 9));

    m.insert(make_pair("Petro", 3));
    for (auto item : m) {
        cout << "Key : " << item.first << "  .Value : " << item.second << endl;
    }
    cout << endl;
    m.insert(make_pair("Oleg", 2));
    for (auto item : m) {
        cout << "Key : " << item.first << "  .Value : " << item.second << endl;
    }
    cout << endl;
    m.insert(make_pair("Valia", 9));
    auto res = m.insert(make_pair("Oleg", 9));
    if (res.second) {
        cout << "User was added." << endl;
    }
    else {
        cout << "User wasn't added." << endl;
    }
    for (auto item : m) {
        cout << "Key : " << item.first << "  .Value : " << item.second << endl;
    }
    cout << endl;

    m["Olga"] = 15;
    m["Mukola"] = 29;
    for (auto item : m) {
        cout << "Key : " << item.first << "  .Value : " << item.second << endl;
    }
    cout << endl;

    auto it = m.find("Olga");
    if (it == m.end()) {
        cout << "Not found" << endl;
    }
    else {
        cout << "Key : " << it->first << "  .Value : " << it->second << endl;
        //it->first = "Iruna"; error
        it->second = 45;
        cout << "Key : " << it->first << "  .Value : " << it->second << endl;

    }


}
