#include <iostream>
using namespace std;

class Animal //abstract class
{
    string name;
    string place;
    float weight;
public:
    Animal() : name("noname"), place("noplace"), weight(0) {}
    Animal(string n, string p, float w) : name(n), place(p)
    {
        //if (w > 0) { weight = w; }
        //else { weight = 0; }
        weight = (w > 0) ? w : 0;
    }

    void Show()
    {
        cout << "Name : " << name << endl;
        cout << "Place : " << place << endl;
        cout << "Weight : " << weight << endl;
    }
    virtual void makeSound() = 0;//pure virtual function
    virtual void Move() = 0;
};
class Dog : public Animal
{
    string breed;
public:
    Dog() : breed("nobreed"), Animal() {}
    Dog(string n, string p, float w, string b) : breed(b), Animal(n, p, w) {}
    void makeSound()override
    {
        cout << "Woof Woof!" << endl;
    }
    void Move()override
    {
        cout << "I am running and jumping." << endl;
    }
};
class Parrot : public Animal
{
    float flyHeight;
    bool canSpeak;
public:
    Parrot() : flyHeight(0), canSpeak(false), Animal() {}
    Parrot(string n, string p, float w, float f, bool s) : flyHeight(f), canSpeak(s), Animal(n, p, w) {}
    void makeSound()override
    {
        cout << "Ko-Ko-Ko!" << endl;
    }
    void Move()override
    {
        cout << "I am flying up to " << flyHeight << "m and I can speak or not : " << canSpeak << endl;
    }
    void Show()
    {
        Animal::Show();
        cout << "Fly height : " << flyHeight << endl;
        if (canSpeak == 1) { cout << "Can speak : Yes" << endl; }
        else { cout << "Can speak : No" << endl; }

    }
};
class Amphibian : public Animal
{
protected:
    float swimDeep;
public:
    Amphibian() : swimDeep(0), Animal() {}
    Amphibian(string n, string p, float w, float s) : swimDeep(s), Animal(n, p, w) {}
    void Move()override
    {
        cout << "I am swiming down " << swimDeep << "." << endl;
    }
    void Show()
    {
        Animal::Show();
        cout << "Swim deep : " << swimDeep << endl;
    }
};
class Frog : public Amphibian
{
public:
    Frog() : Amphibian() {}
    Frog(string n, string p, float w, float s) :Amphibian(n, p, w, s) {}

    void makeSound()override
    {
        cout << "Kwa Kwa Kwa" << endl;
    }
    void Move()override
    {
        cout << "I am swiming down " << swimDeep << "m " << endl;
    }
};

void RollColl(Animal& a)
{
    a.Move();
    a.makeSound();
}
int main()
{
    /* Animal animal("Tom", "Flat", 12);
     animal.Move();
     animal.Show();
     animal.makeSound();*/

    Dog dog("Chloe", "Home", 17, "Beagle");
    dog.Show();
    dog.makeSound();
    dog.Move();
    cout << endl;

    Parrot parrot("Kesha", "Home", 0.5, 5, true);
    parrot.Show();
    parrot.makeSound();
    parrot.Move();
    cout << endl;

    Frog frog("Crazy Frog", "Lake", 0.2, 2);
    frog.Show();
    frog.makeSound();
    frog.Move();
    cout << endl;

    cout << endl;
    RollColl(dog);
    RollColl(parrot);
    RollColl(frog);
}
