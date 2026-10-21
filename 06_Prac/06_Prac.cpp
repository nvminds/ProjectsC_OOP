#include <iostream>
#include <conio.h>
#include<windows.h>
using namespace std;

class Time
{
    int hour;
    int minute;
    int second;
public:
#pragma region Constructors
    Time()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
    explicit Time(int seconds) :Time()
    {
        this->hour = seconds / 3600;
        this->minute = seconds / 60 % 60;
        this->second = seconds % 60;
    }
    Time(int hours, int minutes, int seconds) :Time()
    {
        this->hour = hours;
        this->minute = minutes;
        this->second = seconds;
    }
#pragma endregion

#pragma region Setters/Getters
    void setHour(int hour){ this->hour = hour; }
    void setMinute(int minute){ this->minute = minute; }
    void setSecond(int second){ this->second = second; }
    int getHour() { return hour; }
    int getMinute() { return minute; }
    int getSecond() { return second; }
#pragma endregion

#pragma region Methods
    void Print()const
    {
        if (0 <= hour < 10 and 0 <= minute < 10 and 0 <= second < 10) cout << "Time  0" << hour << ":0" << minute << ":0" << second << endl;
        else if (0 <= hour < 10 and 0 <= minute < 10) cout << "Time  0" << hour << ":0" << minute << ":" << second << endl;
        else if (0 <= minute < 10 and 0 <= second < 10) cout << "Time  " << hour << ":0" << minute << ":0" << second << endl;
        else if (0 <= hour < 10 and 0 <= second < 10) cout << "Time  0" << hour << ":" << minute << ":0" << second << endl;
        else if (0 <= hour < 10) cout << "Time  0" << hour << ":" << minute << ":" << second << endl;
        else if (0 <= minute < 10) cout << "Time  " << hour << ":0" << minute << ":" << second << endl;
        else if (0 <= second < 10) cout << "Time  " << hour << ":" << minute << ":0" << second << endl;
        else cout << "Time  " << hour << ":" << minute << ":" << second << endl; 
    }
    void Print2()const
    {
        if (hour < 10 and minute < 10 and second < 10) cout << "Time  0" << hour << ":0" << minute << ":0" << second;
        else if (hour < 10 and minute < 10) cout << "Time  0" << hour << ":0" << minute << ":" << second;
        else if (minute < 10 and second < 10) cout << "Time  " << hour << ":0" << minute << ":0" << second;
        else if (hour < 10 and second < 10) cout << "Time  0" << hour << ":" << minute << ":0" << second;
        else if (hour < 10) cout << "Time  0" << hour << ":" << minute << ":" << second;
        else if (minute < 10) cout << "Time  " << hour << ":0" << minute << ":" << second;
        else if (second < 10) cout << "Time  " << hour << ":" << minute << ":0" << second;
        else cout << "Time  " << hour << ":" << minute << ":" << second; 
    }
    int TotalSecond()const
    {
        int total_s = hour * 3600 + minute * 60 + second;
        return total_s;
    }
    void TimeToHMS(int total_s)
    {
        hour = total_s / 3600;
        minute = total_s / 60 % 60;
        second = total_s % 60;
    }
    void AddSecond()
    {
        int seconds = TotalSecond();
        seconds += 1;
        TimeToHMS(seconds);
    }
#pragma endregion

#pragma region Operators
    Time operator+(const Time &other)
    {
        int total_s1 = TotalSecond();
        int total_s2 = other.TotalSecond();
        int res(total_s1 + total_s2);
        Time result;
        result.TimeToHMS(res);
        return result;
    }
    Time operator -(const Time &other)
    {
        int total_s1 = TotalSecond();
        int total_s2 = other.TotalSecond();
        int res(total_s1 - total_s2);
        Time result;
        result.TimeToHMS(res);
        return result;
    }
    Time operator*(const Time &other)
    {
        int total_s1 = TotalSecond();
        int total_s2 = other.TotalSecond();
        int res(total_s1 * total_s2);
        Time result;
        result.TimeToHMS(res);
        return result;
    }
    Time operator/(const Time &other)
    {
        int total_s1 = TotalSecond();
        int total_s2 = other.TotalSecond();
        int res(total_s1 / total_s2);
        Time result;
        result.TimeToHMS(res);
        return result;
    }
    bool operator>(const Time &other)
    {
        int total_s1 = TotalSecond();
        int total_s2 = other.TotalSecond();
        return (total_s1 > total_s2);
    }
    bool operator<(const Time &other)
    {
        int total_s1 = TotalSecond();
        int total_s2 = other.TotalSecond();
        return (total_s1 < total_s2);
    }
    bool operator>=(const Time &other)
    {
        int total_s1 = TotalSecond();
        int total_s2 = other.TotalSecond();
        return (total_s1 >= total_s2);
    }
    bool operator<=(const Time &other)
    {
        int total_s1 = TotalSecond();
        int total_s2 = other.TotalSecond();
        return (total_s1 <= total_s2);
    }
    bool operator==(const Time &other)
    {
        int total_s1 = TotalSecond();
        int total_s2 = other.TotalSecond();
        return (total_s1 == total_s2);
    }
    bool operator!=(const Time &other)
    {
        int total_s1 = TotalSecond();
        int total_s2 = other.TotalSecond();
        return (total_s1 != total_s2);
    }
#pragma endregion

};

//тут ші попросив допомогти бо як це реалізувати ми ше не вчили
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

int main()
{
    Time t1;
    Time t2;
    int choice;

    do
    {
        system("cls");
        cout << "------------------------ Choose -----------------------" << endl;
        cout << "  Start programm with default values     --->     [1]" << endl;
        cout << "  Set own values                         --->     [2]" << endl;
        cout << endl;
        cout << "  Exit                                   --->     [0]" << endl;
        cout << endl;
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
            Time t1(11, 43, 35);
            Time t2(5555);
            //t1.Print();
            //t1.AddSecond();
            //t1.Print();
            cout << endl;
            Time res;
            res = t1 + t2;
            cout << "1 "; t1.Print();
            cout << "2 "; t2.Print();
            cout << "Res [+] "; res.Print(); cout << endl;

            res = t1 - t2;
            cout << "1 "; t1.Print();
            cout << "2 "; t2.Print();
            cout << "Res [-] "; res.Print(); cout << endl;

            res = t1 * t2;
            cout << "1 "; t1.Print();
            cout << "2 "; t2.Print();
            cout << "Res [*] "; res.Print(); cout << endl;

            res = t1 / t2;
            cout << "1 "; t1.Print();
            cout << "2 "; t2.Print();
            cout << "Res [/] "; res.Print(); cout << endl;

            cout << "1 "; t1.Print();
            cout << "2 "; t2.Print();
            if (t1 > t2) { cout << "Res [>] "; t1.Print(); cout << endl; }
            else { cout << "Res [>] "; t2.Print(); cout << endl; }

            cout << "1 "; t1.Print();
            cout << "2 "; t2.Print();
            if (t1 < t2) { cout << "Res [<] "; t1.Print(); cout << endl; }
            else { cout << "Res [<] "; t2.Print(); cout << endl; }

            cout << "1 "; t1.Print();
            cout << "2 "; t2.Print();
            if (t1 >= t2) { cout << "Res [>=] "; t1.Print(); cout << endl; }
            else { cout << "Res [>=] "; t2.Print(); cout << endl; }

            cout << "1 "; t1.Print();
            cout << "2 "; t2.Print();
            if (t1 <= t2) { cout << "Res [<=] "; t1.Print(); cout << endl; }
            else { cout << "Res [<=] "; t2.Print(); cout << endl; }

            cout << "1 "; t1.Print();
            cout << "2 "; t2.Print();
            if (t1 == t2) { cout << "Res [==] "; t1.Print2(); cout << " == "; t2.Print2(); cout << endl; }
            else { cout << "Res [==] "; t1.Print2(); cout << " != "; t2.Print2(); cout << endl; }cout << endl;

            cout << "1 "; t1.Print();
            cout << "2 "; t2.Print();
            if (t1 != t2) { cout << "Res [!=] "; t1.Print2(); cout << " != "; t2.Print2(); cout << endl; }
            else { cout << "Res [!=] "; t1.Print2(); cout << " == "; t2.Print2(); cout << endl; }
            break;
        }
        case 2:
        {
            int hour, minute, second;
            Time res;
            Time t1;
            cout << "Set time 1: "<< endl;
            cout << "Set hour >> "; cin >> hour;
            t1.setHour(hour);
            cout << "Set minute >> "; cin >> minute;
            t1.setMinute(minute);
            cout << "Set second >> "; cin >> second;
            t1.setSecond(second);
            cout << endl;
            Time t2;
            cout << "Set time 2: " << endl;
            cout << "Set hour >> "; cin >> hour;
            t2.setHour(hour);
            cout << "Set minute >> "; cin >> minute;
            t2.setMinute(minute);
            cout << "Set second >> "; cin >> second;
            t2.setSecond(second);
            system("cls");
            COORD menuPos = SavePos();
            int choice2;
            do
            {
                ClearFrom(menuPos);
                cout << "------------------------ Choose -----------------------" << endl;
                cout << "  Do time 1 [+] time 2                   --->     [1]" << endl;
                cout << "  Do time 1 [-] time 2                   --->     [2]" << endl;
                cout << "  Do time 1 [*] time 2                   --->     [3]" << endl;
                cout << "  Do time 1 [/] time 2                   --->     [4]" << endl;
                cout << "  Check what [>] time 1 or time 2        --->     [5]" << endl;
                cout << "  Check what [<] time 1 or time 2        --->     [6]" << endl;
                cout << "  Check what [>=] time 1 or time 2       --->     [7]" << endl;
                cout << "  Check what [<=] time 1 or time 2       --->     [8]" << endl;
                cout << "  Check time 1 [==] time 2 or [!=]       --->     [9]" << endl;
                cout << endl;
                cout << "  Exit                                   --->     [0]" << endl;
                cout << endl;
                cout << "Enter choice >> "; cin >> choice2; cout << endl;
                cout << "1 "; t1.Print();
                cout << "2 "; t2.Print();
                cin.ignore();
                switch (choice2)
                {
                case 0:
                    break;
                case 1:
                    res = t1 + t2;
                    cout << "Res [+] "; res.Print(); cout << endl;
                    break;
                case 2:
                    res = t1 - t2;
                    cout << "Res [-] "; res.Print(); cout << endl;
                    break;
                case 3:
                    res = t1 * t2;
                    cout << "Res [*] "; res.Print(); cout << endl;
                    break;
                case 4:
                    res = t1 / t2;
                    cout << "Res [/] "; res.Print(); cout << endl;
                    break;
                case 5:
                    if (t1 > t2) { cout << "Res [>] "; t1.Print(); cout << endl; }
                    else { cout << "Res [>] "; t2.Print(); cout << endl; }
                    break;
                case 6:
                    if (t1 < t2) { cout << "Res [<] "; t1.Print(); cout << endl; }
                    else { cout << "Res [<] "; t2.Print(); cout << endl; }
                    break;
                case 7:
                    if (t1 >= t2) { cout << "Res [>=] "; t1.Print(); cout << endl; }
                    else { cout << "Res [>=] "; t2.Print(); cout << endl; }
                    break;
                case 8:
                    if (t1 <= t2) { cout << "Res [<=] "; t1.Print(); cout << endl; }
                    else { cout << "Res [<=] "; t2.Print(); cout << endl; }
                    break;
                case 9:
                    if (t1 == t2) { cout << "Res [==] "; t1.Print2(); cout << " == "; t2.Print2(); cout << endl; }
                    else { cout << "Res [==] "; t1.Print2(); cout << " != "; t2.Print2(); cout << endl; }cout << endl;
                    break;
                default:
                    break;
                }
                if (choice2 != 0)
                {
                    cout << endl; cout << endl;
                    cout << "Press any key to continue...." << endl;
                    _getch();
                }
            } while (choice2 != 0);
        }
        default:
            break; 
        }
        if (choice != 0)
        {
            cout << endl; cout << endl;
            cout << "Press any key to continue...." << endl;
            _getch();
        }
    } while (choice != 0);
}
