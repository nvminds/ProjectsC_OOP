#include <iostream>
using namespace std;


template<typename T>
class List
{
    struct Node
    {
        T value;
        Node* next;
        Node() : value(0), next(nullptr) {}
        Node(T value, Node* next) : value(value), next(next) {}
    };
    Node* head;
public:
    List()
    {
        head = nullptr;
    }
    ~List()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = current->next;
            delete current;
        }
    }
    void addToHead(T value)
    {
        Node* newNode = new Node(value, head);
        newNode->value = value;
        newNode->next = head;

        head = newNode;
    }
    void Print()const
    {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
    void addToTail(T value)
    {
        Node* newNode = new Node(value, nullptr);
        if (head == nullptr)
        {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void DeleteFromTail()
    {
        if (head == nullptr)
        {
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
        }
        else {
            Node* current = head;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }
    void DeleteFromHead()
    {
        Node* current = nullptr;
        if(head==nullptr)
        {
            return;
        }
        else
        {
            current = head;
            head = current->next;
            delete current;
        }
    }
};

class Point
{
    int x;
    int y;
public:
    Point()
    {
        x = y = 0;
    }
    Point(int value)
    {
        this->x = value;
        this->y = value;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
#pragma region OverloadedOperators
    Point operator+(const Point& other) const
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }

    Point operator-(const Point& other) const
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }

    Point operator*(const Point& other)
    {
        Point res(this->x * other.x, this->y * other.y);
        return res;
    }

    Point operator/(const Point& other)
    {
        Point res(this->x / other.x, this->y / other.y);
        return res;
    }

    Point operator+=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Point operator=(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

    Point operator-()
    {
        return Point(this->x * -1, this->y * -1);
    }

    Point operator--()
    {
        --this->x;
        --this->y;
        return *this;
    }

    Point operator++(int)
    {
        this->x++;
        this->y++;
        return *this;
    }

    Point operator--(int)
    {
        this->x--;
        this->y--;
        return *this;
    }

    Point operator!()
    {
        this->x = -x;
        this->y = -y;
        return *this;
    }

    bool operator>(const Point& other) const
    {
        return ((this->x + this->y) > (other.x + other.y));
    }

    bool operator<(const Point& other)const
    {
        return ((this->x + this->y) < (other.x + other.y));
    }

    bool operator>=(const Point& other) const
    {
        return ((this->x + this->y) >= (other.x + other.y));
    }

    bool operator==(const Point& other) const
    {
        return ((this->x == other.x) and (this->y == other.y));
    }

    bool operator!=(const Point& other) const
    {

        return !(*this == other);
    }
    friend Point operator ++(Point& point);
    friend ostream& operator<<(ostream& out, const Point& point);
    friend istream& operator>>(istream& in, Point& point);
    void Print()const
    {
        cout << "X cord : " << x << endl;
        cout << "Y cord : " << y << endl;
    }
#pragma endregion
};

ostream& operator<<(ostream& out, const Point& point)
{
    out << "X : [" << point.x << "]   " << " Y : [" << point.y << "]";
    return out;
}
istream& operator>>(istream& in, Point& point)
{
    in >> point.x;
    in >> point.y;
    return in;
}
Point operator ++(Point& point)
{
    point.x++;
    point.y++;
    return point;
}

class Vector
{
    List<Point> points;
    int size;
public:
    Vector() : size(0){}

    void ShowPoint()const
    {
        points.Print();
    }
    void addPointToTail(Point p)
    {
        points.addToTail(p);
        size++;
        cout << "Size = " << size << endl;
    }
    void addPointToHead(Point p)
    {
        points.addToHead(p);
        size++;
        cout << "Size = " << size << endl;

    }
    void deletePointFromTail()
    {
        if (size > 0) { points.DeleteFromTail(); size--;  cout << "Size = " << size << endl; }
    }
    void deletePointFromHead()
    {
        if (size > 0) { points.DeleteFromHead(); size--;  cout << "Size = " << size << endl;}
    }
};



int main()
{
    Point p1(10, 20);
    Point p2(12, 30);
    Point p3(22, 3);
    Vector v;
    v.addPointToHead(p1);
    v.ShowPoint();
    cout << endl;
    v.addPointToTail(p2);
    v.ShowPoint();
    cout << endl;
    v.addPointToTail(p3);
    v.ShowPoint();
    cout << endl;
    v.deletePointFromHead();
    v.ShowPoint();
    cout << endl;
    v.deletePointFromTail();
    v.ShowPoint();
    cout << endl;
}

