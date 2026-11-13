#include <iostream>
using namespace std;

class Transport
{
protected:
    string name;
    int speed;
    int countPassagers;
    int distance;
public:
    Transport(): name("noname"), speed(0), countPassagers(0), distance(0){}
    Transport(string n, int s, int c, int d): name(n), speed(s), countPassagers(c), distance(d){}
    virtual void Show()const
    {
        cout << "Name : " << name << endl;
        cout << "Speed : " << speed << "km/h" << endl;
        cout << "Passagers count : " << countPassagers << endl;

    }
    virtual void CalculateCost() = 0;
    void CalculateTime ()
    {
        cout << "Time of travel : " << (float)distance / speed  << " hrs" << endl;
    }
};
class Vechicle : public Transport 
{
    float costByKM;
public:
    Vechicle() : Transport(), costByKM(0) {}
    Vechicle(string n, int s, int c, int d, int cost) : Transport(n, s, c, d), costByKM(cost) {}
    void CalculateCost() override
    {
        cout << "Total cost : " << distance * speed * costByKM << endl;
    }
    void Show()const
    {
        Transport::Show();
        cout << "Cost by Km : " << costByKM << endl;
    }
};
class Bicycle : public Transport 
{
    float costByHour;
public:
    Bicycle() : Transport(), costByHour(0) {}
    Bicycle(string n, int s, int c, int d, int cost) : Transport(n, s, c, d), costByHour(cost) {}
    void CalculateCost() override
    {
        cout << "Total cost : " << (float)((distance / speed) * costByHour) << endl;
    }
    void Show()const
    {
        Transport::Show();
        cout << "Cost by Hour : " << costByHour << endl;
    }
};
class Cart : public Transport 
{
    float costByHour;
    int horses;
    const int one_horse_cost = 40;
public:
    Cart() : Transport(), costByHour(0), horses(0) {}
    Cart(string n, int c, int d, float cost, int h) : Transport(n, 0, c, d), costByHour(cost), horses(h) {}
    int CalculateCartSpeed()
    {
        speed = horses * 8;
        return speed;
    }
    void CalculateCost() override
    {
        cout << "Total cost : " << ((distance / speed) * costByHour) + (one_horse_cost*horses) << endl;
    }
    void Show()const
    {
        Transport::Show();
        cout << "One horse cost : " << one_horse_cost << endl;
        cout << "Horses count : " << horses << endl;
        cout << "Cost by Hour : " << costByHour << endl;
    }
};


int main()
{
    Vechicle v("Car", 50, 4, 40, 10);
    v.Show();
    v.CalculateTime();
    v.CalculateCost();
    cout << endl;
    
    Bicycle b("Bicycle", 8, 2, 40, 250);
    b.Show();
    b.CalculateTime();
    b.CalculateCost();
    cout << endl;

    Cart c("Cart", 6, 40, 70, 2);
    c.CalculateCartSpeed();
    c.Show();
    c.CalculateTime();
    c.CalculateCost();
    cout << endl;
}

