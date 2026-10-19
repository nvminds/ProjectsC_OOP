#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class Book
{
    string author;
    string name;
    string publication;
    int year;
    int count_of_pages;
public:
    Book() : author("no author"), name("no title"), publication("no publication"), year(0), count_of_pages(0) {}
    explicit Book(string name) : Book()
    {
        this->name = name;
    }
    Book(string author, string name, string publication, int year, int count_of_pages) : Book(name)
    {
        this->author = author;
        this->publication = publication;
        this->year = year;
        this->count_of_pages = count_of_pages;
    }

    void setAuthor(string author) { this->author = author; }
    void setName(string name) { this->name = name; }
    void setPublication(string publication) { this->publication = publication; }
    void setYear(int year) { this->year = year; }
    void setPagesCount(int count_of_pages) { this->count_of_pages = count_of_pages; }

    string getAuthor()const { return author; }
    string getName()const { return name; }
    string getPublication()const { return publication; }
    int getYear()const { return year; }
    int getPagesCount()const { return count_of_pages; }

    void Print()const
    {
        cout << "Author : " << author << endl;
        cout << "Title : " << name << endl;
        cout << "Publication : " << publication << endl;
        cout << "Year of publication : " << year << endl;
        cout << "Count of pages : " << count_of_pages << endl;
        cout << endl;
    }
};
class Library
{
    Book* books;
    int count_books;
public:
    Library()
    {
        books = nullptr;
        count_books = 0;
    }
    ~Library()
    {
        if (books != nullptr) { delete[]books; }
    }
    void PrintAllBook()const
    {
        for (int i = 0; i < count_books; i++)
        {
            books[i].Print();
        }
        cout << endl;
    }
    void AddBook(Book book)
    {
        Book* temp = new Book[count_books + 1];
        for (int i = 0; i < count_books; i++)
        {
            temp[i] = books[i];
        }
        temp[count_books] = book;
        this->count_books += 1;
        delete[]books;
        books = temp;
    }
    void SearchByAuthor(const Book &book)const
    {
        for (int i = 0; i < count_books; i++)
        {
            if(books[i].getAuthor()==book.getAuthor())
            {
                books[i].Print();
            }
        }
    }
    void SearchByPublication(const Book &book)const
    {
        for (int i = 0; i < count_books; i++)
        {
            if (books[i].getPublication()==book.getPublication())
            {
                books[i].Print();
            }
        }
    }
    void SearchByYear(const Book &book)const
    {
        for (int i = 0; i < count_books; i++)
        {
            if (books[i].getYear()>=book.getYear())
            {
                books[i].Print();
            }
        }
    }

};
int main()
{
    // explicit test
    //Book book_t("1984");
    //book_t.Print();
    Book blank_book1("George Orwell", "1984", "Secker & Warburg", 1949, 328);
    Book blank_book2("J.R.R. Tolkien", "The Hobbit", "George Allen & Unwin", 1937, 310);
    Book blank_book3("George Orwell", "Animal Farm", "Secker & Warburg", 1945, 112);

    Library library;
    library.AddBook(blank_book1);
    library.AddBook(blank_book2);
    library.AddBook(blank_book3);

    Book book;
    string user_input_string;
    int user_input_int;
    int choice;

    do
    {
        system("cls");
        cout << "------------------------ Choose -----------------------" << endl;
        cout << "  Show all books                         --->     [1]" << endl;
        cout << "  Add new book                           --->     [2]" << endl;
        cout << "  Search books by Author                 --->     [3]" << endl;
        cout << "  Search books by Publication            --->     [4]" << endl;
        cout << "  Search books by year of publication    --->     [5]" << endl;
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
            library.PrintAllBook();
            break;
        case 2:
            cout << "Enter book author >> "; getline(cin, user_input_string);
            book.setAuthor(user_input_string);

            cout << "Enter book title >> "; getline(cin, user_input_string);
            book.setName(user_input_string);

            cout << "Enter publication which book is published >> "; getline(cin, user_input_string);
            book.setPublication(user_input_string);

            cout << "Enter year of book publication  >> "; cin >> user_input_int;
            book.setYear(user_input_int);

            cout << "Enter count of book pages >> "; cin >> user_input_int;
            book.setPagesCount(user_input_int);
            cin.ignore();

            book.Print();

            library.AddBook(book);
            break;
        case 3:
            cout << "Enter book author >> "; getline(cin, user_input_string);
            book.setAuthor(user_input_string);
            library.SearchByAuthor(book);
            break;
        case 4:
            cout << "Enter publication which book is published >> "; getline(cin, user_input_string);
            book.setPublication(user_input_string);
            library.SearchByPublication(book);
            break;
        case 5:
            cout << "Enter year of book publication  >> "; cin >> user_input_int;
            book.setYear(user_input_int);
            library.SearchByYear(book);
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
