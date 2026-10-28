#include "Book.h"
#include "Library.h"

int main()
{
    Book book("Smile", 1960, "Rey Bredberry", 250,Genre::Fantasy);
    book.ShowInfo();
    Library lib("Youngth Library", "Kyivska 16");
    lib.addBook(Book("The Twelve Chairs", 1928, "I. Ilf, Y. Petrov", 400, Comedy));
    lib.addBook(Book("The Adventures of Tom Sawyer", 1876, "Mark Twain", 275, Comedy));
    lib.addBook(Book("Shadows of Forgotten Ancestors", 1911, "Mykhailo Kotsiubynskyi", 120, Drama));
    lib.addBook(Book("Harry Potter and the Philosopher's Stone", 1997, "J. K. Rowling", 332, Fantasy));
    lib.addBook(Book("Dune", 1965, "Frank Herbert", 896, Sci_Fi));
    lib.addBook(Book("Sherlock Holmes", 1892, "Arthur Conan Doyle", 307, Fantasy));
    lib.addBook(Book("The Aeneid", 1798, "Ivan Kotliarevskyi", 350, Comedy)); 
    lib.addBook(Book("The City", 1928, "Valerian Pidmohylnyi", 300, Drama));
    lib.addBook(Book("The Hitchhiker's Guide to the Galaxy", 1979, "Douglas Adams", 224, Comedy));
    lib.addBook(Book("1984", 1949, "George Orwell", 328, Sci_Fi));
    lib.showLibrary();

    Library lib_copy(lib);
    cout << "================COPY=================" << endl;
    lib_copy.showLibrary();

    Library newLib = lib_copy;
    cout << "================NEW LIB=================" << endl;
    newLib.showLibrary();

    lib = lib_copy = newLib;
}
