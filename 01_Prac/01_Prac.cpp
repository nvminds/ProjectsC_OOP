#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const char* filename = "Coordinates.txt";

class Point
{
    int x_cord=0;
    int y_cord=0;
    int z_cord=0;

public:
    void Input()
    {
        cout << "Enter x >> "; cin >> x_cord;
        cout << "Enter y >> "; cin >> y_cord;
        cout << "Enter z >> "; cin >> z_cord;
    }
    void Show()
    {
        cout << "X cord : " << x_cord << endl;
        cout << "Y cord : " << y_cord << endl;
        cout << "Z cord : " << z_cord << endl;
        cout << endl;
    }

    void setX(int x)
    {
        this->x_cord = x;
    }
    void setY(int y)
    {
        this->y_cord = y;
    }
    void setZ(int z)
    {
        this->z_cord = z;
    }
    int getX()
    {
        return x_cord;
    }
    int getY()
    {
        return y_cord;
    }
    int getZ()
    {
        return z_cord;
    }

    void saveToFile()
    {
        ofstream out(filename, ios_base::out);
        out << x_cord;
        out << ':';
        out << y_cord;
        out << ':';
        out << z_cord;
        out << '|';
        out.close();
    }
    void readFromFile()
    {
        ifstream in(filename, ios_base::in);
        string Bx_cord, By_cord, Bz_cord;
        while (!in.eof())
        {
            getline(in, Bx_cord, ':');
            if (in.eof())
            {
                break;
            }
            getline(in, By_cord, ':');
            getline(in, Bz_cord, '|');
            
            x_cord = atoi((Bx_cord).c_str());
            y_cord = atoi((By_cord).c_str());
            z_cord = atoi((Bz_cord).c_str());
        }
    }
};

int main()
{
    Point cords;
    int x, y, z;
    cords.readFromFile();
    cout << "Load from file :" << endl;
    cords.Show();
    cout << endl;
    cords.Input();
    cords.Show();
    cout << "Enter new x >> "; cin >> x;
    cords.setX(x);
    cout << "Enter new y >> "; cin >> y;
    cords.setY(y);
    cout << "Enter new z >> "; cin >> z;
    cords.setZ(z);

    cout << "New x : " << cords.getX() << endl;
    cout << "New y : " << cords.getY() << endl;
    cout << "New z : " << cords.getZ() << endl;
    cords.saveToFile();
}
