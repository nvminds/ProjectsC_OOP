#include <iostream>
using namespace std;

enum Type{NONE, Standart, XL, XXL};
class Cartridge{
    float volume;
    string color;
    Type type;
public:
    Cartridge():volume(0), color("nocolor"), type(NONE) {}
    Cartridge(float v, string c, Type t):volume(v), color(c), type(t) {}
    void ShowInfo()const {
        cout << "Volume : " << volume << endl;
        cout << "Color : " << color << endl;
        cout << "Type : ";
        switch (type)
        {
        case NONE: cout << " NONE " << endl; break;
        case Standart: cout << " Standart " << endl; break;
        case XL: cout << " XL " << endl; break;      
        case XXL: cout << " XXL " << endl; break;   
        }
        cout << endl;
    }
};
class Scanner{
    float scanRes;
    float height;
    float width;
public:
    Scanner(): scanRes(0), height(0), width(0){}
    Scanner(float s, float h, float w): scanRes(s), height(h), width(w){}
    void ShowInfo()const{
        cout << "Scan resolution : " << scanRes << endl;
        cout << "Area : " << height << "x" << width << endl;
    }
};
class Document {
    string name;
    string format;
    int pages;
public:
    Document() :name("noname"), format("noformat"), pages(0) {}
    Document(string n, string f, int p) :name(n), format(f), pages(p) {}
    void ShowInfo()const {
        cout << "-------------------- Document --------------------" << endl;
        cout << "Title : " << name << endl;
        cout << "Format : " << format << endl;
        cout << "Pages : " << pages << endl;
        cout << endl;
    }
};
class Printer{
    string model;
    Cartridge* cartridges;
    int countCartridges;
    Scanner scanner;
    //Aggregation
    Document* doc;
public:
    Printer() :model("nomodel"), cartridges(nullptr), countCartridges(0), doc(nullptr) {}
    Printer(string model, float s, float h, float w) :model(model), scanner(s, h, w), doc(nullptr) {
        countCartridges = 4;
        cartridges = new Cartridge[countCartridges];
        cartridges[0] = Cartridge(500, "Red", Type::XL);
        cartridges[1] = Cartridge(500, "Green", Type::XL);
        cartridges[2] = Cartridge(500, "Blue", Type::XL);
        cartridges[3] = Cartridge(500, "Black", Type::XL);
    }
    ~Printer(){
        if (cartridges != nullptr) { delete[] cartridges; }
    }
    void Scan(){
        cout << "Scanning............." << endl;
    }
    void PrintDoc(){
        if (doc!=nullptr){
            cout << "Printing document..." << endl << endl;
            doc->ShowInfo();
        }
        else {
            cout << "No document" << endl;
        }
    }
    void PrintSettings(){
        for (int i = 0; i < countCartridges; i++)
        {
            cartridges[i].ShowInfo();
        }
    }
    void AddDoc(Document* doc){
        this->doc = doc;
    }
};

int main()
{
    Printer printer("Cannon LBP2900", 300, 30, 50);
    printer.PrintDoc();
    printer.Scan();
    printer.PrintSettings();

    Document document("Passport", "A5", 16);
    Document document1("C++ for beginners", "A4", 520);

    printer.AddDoc(&document);
    printer.PrintDoc();
    printer.AddDoc(&document1);
    printer.PrintDoc();
}