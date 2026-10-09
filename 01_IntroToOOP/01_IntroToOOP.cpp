#include <iostream>
using namespace std;

/*
struct Player 
{
//public by default:
    string name;
    short age;
    int games;
    int goals;
};
void printPlayer(Player &plr)
{
    cout << "Name : " << plr.name << endl;
    cout << "Age : " << plr.age << endl;
    cout << "Games : " << plr.games << endl;
    cout << "Goals : " << plr.goals << endl;
}
void initPlayer(Player& plr) 
{
    cout << "Name >> "; cin >> plr.name;
    cout << "Age >> "; cin >> plr.age;
    plr.games = 0;
    plr.goals = 0;
}
void addGameToPlayer(Player& plr, int goals=0)
{
    plr.games++;
    plr.goals += goals;
}
*/

class Player 
{
//private by default:
    string name;
    short age;
    int games;
    int goals;

public:
    void printPlayer()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "Games : " << games << endl;
        cout << "Goals : " << goals << endl;
    }
    void initPlayer()
    {
        cout << "Name >> "; cin >> name;
        cout << "Age >> "; cin >> age;
        games = 0;
        goals = 0;
    }
    void addGameToPlayer(int goals = 0)
    {
        games++;
        this->goals += goals;
    }
};

class Student 
{
    string name; //data members
    int marks[3];

public:
    //setter
    void setName(string name)
    {
        this->name = name;
    }
    void setMark(int index, int mark)
    {
        if (mark>=1 and mark<=12)
        {
            marks[index] = mark;
        }
        else
        {
            marks[index] = 0;
        }
    }
    //getter
    string getName()
    {
        return name;
    }
    int getMark(int index)
    {
        return marks[index];
    }


    double getAverege() //methods   ||   member function
    {
        double summ = 0;
        for (int i = 0; i < 3; i++)
        {
            summ += marks[i]; 
        }
        return (double)summ / 3;
    }
};
int main()
{
    Student st;
    st.setName("Ivan");
    st.setMark(0, 12);
    st.setMark(1, 3);
    st.setMark(2, 4);
    
    cout << "Name : " << st.getName() << endl;
    cout << "Mark 1 : " << st.getMark(0) << endl;
    cout << "Mark 2 : " << st.getMark(1) << endl;
    cout << "Mark 3 : " << st.getMark(2) << endl;
    cout << "Avg mark : " << st.getAverege() << endl;

    Player player;
    //initPlayer(player);
    //printPlayer(player);
    //addGameToPlayer(player, 4);
    //addGameToPlayer(player, 1);
    //addGameToPlayer(player, 2);
    //printPlayer(player);

    player.initPlayer();
    player.printPlayer();
    player.addGameToPlayer(3);
    player.printPlayer();
}
