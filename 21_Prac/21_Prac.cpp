#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

const char* filename = "Trains.txt";

struct Time {
    int h, m, s;
};
class Train {
    int number;
    Time departureTime;
    string destination;
public:
    Train():number(0), departureTime({0,0,0}), destination("none") {}
    Train(int num, int h, int m, int s, string dest):number(num), departureTime({h,m,s}), destination(dest) {}
    void Print()const {
        cout << "Nubmer : " << number << endl;
        cout << "Time : " << departureTime.h << ":" << departureTime.m << ":" << departureTime.s << endl;
        cout << "Destination : " << destination << endl;
    }
    int getNumber() {
        return number;
    }
    void setNewTime(int h, int m, int s) {
        this->departureTime.h = h;
        this->departureTime.m = m;
        this->departureTime.s = s;
    }
    bool operator <(const Train& t)const {
        return this->destination > t.destination;
    }
    void SaveToFile() {
        ofstream out(filename, ios_base::app);
        out << number;
        out << ";";
        out << departureTime.h;
        out << ":";
        out << departureTime.m;
        out << ":";
        out << departureTime.s;
        out << ";";
        out << destination;
        out << "|";
    }

};

class Railway {
    vector<Train> trains;
public:
    void AddTrain(Train t) {
        trains.push_back(t);
    }
    void PrintAllTrains()const {
        for (auto item:trains)
        {
            item.Print();
        }
        cout << endl;
    }
    void PrintByNumber(int num) {
        for (int i = 0; i < trains.size(); i++)
        {
            if (trains[i].getNumber() == num) {
                trains[i].Print();
            }
        }
    }
    void ChangeDepartureTime(int num, int h, int m, int s) {
        for (int i = 0; i < trains.size(); i++)
        {
            if (trains[i].getNumber() == num) {
                trains[i].setNewTime(h, m, s);
            }
        }
    }
    void SortByDestination() {
        priority_queue<Train> sortByDest;
        for (int i = 0; i < trains.size(); i++)
        {
            sortByDest.push(trains[i]);
        }
        trains.clear();
        while (!sortByDest.empty())
        {
            trains.push_back(sortByDest.top());
            sortByDest.pop();
        }
    }
    void SaveAllTrains() {
        ofstream(filename, ios_base::trunc);
        for (int i = 0; i < trains.size(); i++)
        {
            trains[i].SaveToFile();
        }
    }
    void ReadFromFile() {
        trains.clear();
        ifstream in(filename, ios_base::in);
        string read;
        while (getline(in, read, '|'))
        {
            if (read.empty()) continue;
            stringstream stream(read);
            int num, h, m, s;
            char sep;
            string dest;

            stream >> num >> sep;
            stream >> h >> sep;
            stream >> m >> sep;
            stream >> s >> sep;
            getline(stream, dest);

            trains.push_back(Train(num, h, m, s, dest));
        }
    }
};


int main()
{
    
    //Train t1(1, 8, 30, 0, "Kyiv");
    //Train t2(2, 9, 30, 0, "Lviv");
    //Train t3(3, 10, 30, 0, "Rivne");
    //Train t4(4, 11, 0, 0, "Dnipro");
    //Train t5(5, 12, 15, 0, "Odesa");
    //Train t6(6, 13, 45, 0, "Chernihiv");

    Railway r;
    r.ReadFromFile();
    //r.AddTrain(t1);
    //r.AddTrain(t2);
    //r.AddTrain(t3);
    //r.AddTrain(t4);
    //r.AddTrain(t5);
    //r.AddTrain(t6);

    /*r.PrintByNumber(3);
    r.ChangeDepartureTime(3, 18, 25, 0);
    r.PrintByNumber(3);*/
    r.PrintAllTrains();

    r.SortByDestination();
    r.PrintAllTrains();
    
    //r.SaveAllTrains();
}
