#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

struct Coord
{
    int x_cord;
    int y_cord;
};

class Rect
{
    int height;
    int width;
    char symbol;
    Coord cords;
public:
    void setHeight(int height)
    {
        this->height = height;
    }
    void setWidht(int width)
    {
        this->width = width;
    }
    void setSymbol(char symbol)
    {
        this->symbol = symbol;
    }
    void setXCord(int x)
    {
        this->cords.x_cord = x;
    }
    void setYCord(int y)
    {
        this->cords.y_cord = y;
    }
    int getHeight()
    {
        return height;
    }
    int getWidht()
    {
        return width;
    }
    char getSymbol()
    {
        return symbol;
    }
    int getXCord()
    {
        return cords.x_cord;
    }
    int getYCord()
    {
        return cords.y_cord;
    }


    Rect()
    {
        height = 2;
        width = 2;
        symbol = '*';
        cords.x_cord = 0;
        cords.y_cord = 0;
    }
    Rect(int size)
    {
        height = size;
        width = size;
        symbol = '*';
        cords.x_cord = 0;
        cords.y_cord = 0;
    }
    Rect(int width, int height)
    {
        this->height = height;
        this->width = width;
        symbol = '*';
        cords.x_cord = 0;
        cords.y_cord = 0;
    }
    void SetPos(int x, int y)
    {
        COORD c;
        c.X = x;
        c.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
    }
    void drawFigure()
    {
        system("cls");
        for (int i = 0; i < height; i++)
        {
            SetPos(cords.x_cord, cords.y_cord+i);
            for (int j = 0; j < width; j++)
            {
                cout << symbol << " ";
            }
        }
    }
    void changeSize(int height, int width)
    {
        this->height = height;
        this->width = width;
    }
    void changeCords(int x_cord, int y_cord)
    {
        this->cords.x_cord = x_cord;
        this->cords.y_cord = y_cord;
    }
    int errorCheck(int val) 
    {
        if(val<0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};

int main()
{
    Rect c;
    int height, width, x, y;
    char symbol;
    int choice;

    do 
    {
        system("cls");
        cout << "---------- Choose what to do with figure ----------" << endl;
        cout << "         Set new figure        --->    [1]" << endl;
        cout << "         Change figure size    --->    [2]" << endl;
        cout << "         Change figure cords   --->    [3]" << endl;
        cout << endl;
        cout << "         Exit                  --->    [0]" << endl;
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
            cout << "Enter height >> "; cin >> height;
            if (c.errorCheck(height)==0)
            {
                cout << "Values cant be negative numbers!" << endl;
                break;
            }
            c.setHeight(height);
            cout << "Enter width >> "; cin >> width;
            if (c.errorCheck(width)==0)
            {
                cout << "Values cant be negative numbers!" << endl;
                break;
            }
            c.setWidht(width);
            cout << "Enter symbol >> "; cin >> symbol;
            c.setSymbol(symbol);
            cout << "Enter x coordinate >> "; cin >> x;
            if (c.errorCheck(x)==0)
            {
                cout << "Values cant be negative numbers!" << endl;
                break;
            }
            c.setXCord(x);
            cout << "Enter y coordinate >> "; cin >> y;
            if (c.errorCheck(y)==0)
            {
                cout << "Values cant be negative numbers!" << endl;
                break;
            }
            c.setYCord(y);
            c.drawFigure();
            break;
        case 2:
            cout << "Enter new height >> "; cin >> height;
            if (c.errorCheck(height) == 0)
            {
                cout << "Values cant be negative numbers!" << endl;
                break;
            }
            cout << "Enter new width >> "; cin >> width;
            if (c.errorCheck(width) == 0)
            {
                cout << "Values cant be negative numbers!" << endl;
                break;
            }
            c.changeSize(height, width);
            c.drawFigure();
            break;
        case 3:
            cout << "Enter new x coordinate >> "; cin >> x;
            if (c.errorCheck(x) == 0)
            {
                cout << "Values cant be negative numbers!" << endl;
                break;
            }
            cout << "Enter new y coordinate >> "; cin >> y;
            if (c.errorCheck(y) == 0)
            {
                cout << "Values cant be negative numbers!" << endl;
                break;
            }
            c.changeCords(x, y);
            c.drawFigure();
            break;
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

