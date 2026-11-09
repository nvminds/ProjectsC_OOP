#include <iostream>
using namespace std;

class Enemy
{
protected:
    string name;
    int health;
    float strength;
    static const int maxHealth = 100;
public:
    Enemy(): name("noname"), health(0), strength(0){}
    Enemy(string n, float s) : name(n), health(maxHealth), strength(s) {} 
    void Print()const
    {
        cout << "Name : " << name << endl;
        cout << "HP : " << health << endl;
        cout << "Strength : " << strength << endl;
    }
    void DecreaseHeal(int val)
    {
        if (health - val <= 0) { health = 0; }
        else { health -= val; }
    }
    bool IsAlive()const
    {
        return health > 0;
    }
    void Fight(int damage)
    {
        cout << "Getting damage : " << damage << endl;
        DecreaseHeal(damage);
        cout << "HP : " << health << endl;
    }
    float Attack()
    {
        cout << "Strength of attack : " << strength << endl;
        return strength;
    }
};

//class Child : [spetificator] Parent
//[spetificator] ---> public, private, protected
class Dragon : public Enemy
{
    float armor;
public:
    Dragon() : armor(0), Enemy(){}
    Dragon(string n, float s, float a) : armor(a), Enemy(n, s){}
    void Print() 
    {
        cout << "----------------Dragon----------------" << endl;
        Enemy::Print();
        cout << "Armor : " << armor << endl;
    }
    void Fight(int damage)
    {
        Enemy::Fight(damage - armor);
    }
};

class Wizard : public Enemy
{
    float magical_attack;
public:
    Wizard():magical_attack(0), Enemy() {}
    Wizard(string n, float s, float m) :magical_attack(m), Enemy(n, s){}
    void Fight(int damage)
    {
        Enemy::Fight(damage);
    }
    float MagicalAttack()
    {
        cout << "Strength of attack : " << magical_attack << endl;
        return magical_attack+strength;
    }
    void Print()
    {
        cout << "----------------Wizard----------------" << endl;
        Enemy::Print();
        cout << "Armor : " << magical_attack << endl;
    }
};

int main()
{
    Dragon dragon("Leftarion", 5, 6);
    Dragon boss("Rightarion", 7, 3);
    Wizard wizard("Dambldor", 4, 7);
    int i = 1;
  /*
    do 
    {
        cout << "---------------ROUND " << i << "--------------" << endl;
        dragon.Fight(boss.Attack());
        cout << endl;
        boss.Fight(dragon.Attack());

        dragon.Print();
        boss.Print();
        i++;
        cout << endl;
    } while (boss.IsAlive() and dragon.IsAlive());
    dragon.Print();
    boss.Print();
    */
    do
    {
        cout << "---------------ROUND " << i << "--------------" << endl;
        wizard.Fight(boss.Attack());
        cout << endl;
        boss.Fight(wizard.Attack());

        wizard.Print();
        boss.Print();
        i++;
        cout << endl;
    } while (boss.IsAlive() and wizard.IsAlive());
    cout << "--------------After game stats--------------" << endl << endl;
    wizard.Print();
    boss.Print();
}
