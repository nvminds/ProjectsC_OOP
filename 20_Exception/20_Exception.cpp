#include <iostream>
using namespace std;

float Divide(float a, float b){
    float res = 0;
    if (b == 0) {
        //cout << "Can't divide by zero!" << endl;
        throw exception("Can't divide by zero!");
    }
    if (b == 1) {
        throw 404;
    }
    if (b == 2) {
        throw "Can't divide by zero!";
    }
    if (b == 3) {
        throw false;
    }
    else {
        res = a / b;
        cout << "Result : " << res << endl;
        return res;
    }
}
class PasswordInvalidException : public exception{
public:
    PasswordInvalidException(const char* massage) :exception(massage) {}
};
class SmallPasswordException : public exception {
    int length;
public:
    SmallPasswordException(const char* massage, int len) :length(len), exception(massage) {}
    void Massage() {
        cout << what() << endl;
        cout << "Actual length : " << length << endl;
    }
};
void ValidateLogin(const char* login, const char* pass) {
    if (strlen(pass) < 6) {
        throw SmallPasswordException("Password is too small.", strlen(pass));
    }
    if (!islower(pass[0]) || !isalpha(pass[0])) {
        throw PasswordInvalidException("Password is invalid.");
    }
    if (!isupper(login[0]) || !isalpha(login[0])) {
        throw exception("Incorrect login");
    }
}

class MyArray
{
    int* arr;
    int size;
public:
    MyArray(int size = 20):size(size)
    {
        arr = new int[size] {};
    }
    void Print()const{
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }cout << endl;
    }
    ~MyArray() { delete[] arr; }
    int getElement(int index) {
        if (index >= 0 and index < size) {
            return arr[index];
        }
        else {
            throw out_of_range("Index is less than 0 or bigger than size!");
        }
    }
    void CheckLen(int len) {
        if (len < 0) {
            throw length_error("Lenght can't be less than 0");
        }
        cout << "Length is valid" << endl;
    }
    void SetSize(int s){
        if (s < 0) {
            throw invalid_argument("New size is less than 0.");
        }
        else {
            int* temp = new int[s];
            for (int i = 0; i < size && i < s; i++)
            {
                temp[i] = arr[i];
            }
            delete[]arr;
            arr = temp;
            size = s;
        }
    }
};
int main()
{
    // exception --> logic_error --> out_of_range & invalid_argument & length_error & ....

    MyArray arr(10);
    arr.Print();

    try
    {
        //arr.getElement(100);
        arr.CheckLen(-1);
        //arr.SetSize(-1);
    }
    catch (out_of_range ex)
    {
        cout << ex.what() << endl;
    }
    catch (invalid_argument ex)
    {
        cout << ex.what() << endl;
    }
    catch (logic_error ex)
    {
        cout << ex.what() << endl;
    }

    /*
    char login[100];
    char pass[100];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter login << "; cin >> login;
        cout << "Enter password << "; cin >> pass; 
        try
        {
            ValidateLogin(login, pass);
        }
        catch(PasswordInvalidException ex)
        {
            cout << "Invalid ...... do somethind." << endl;
            cout << "First letter must be small (a-z)" << endl;
            cout << ex.what() << endl;
        }
        catch(SmallPasswordException ex)
        {
            ex.Massage();
            cout << "Password must be more than 6 symbols" << endl;
        }
        catch (exception ex)
        {
            cout << "General error" << endl;
            cout << ex.what() << endl;
        }
        catch (...)
        {
            cout << "Unknown error" << endl;
        }
    }
    */


    /*
    //try  catch  throw
    float a, b;
    cout << "Enter a << "; cin >> a;
    cout << "Enter b << "; cin >> b;
    try
    {
        float res = Divide(a, b);
        cout << "Result in main : " << res << endl;
    }
    catch (exception ex){
        cout << ex.what();
    }
    catch (int ex){
        cout << ex;
    }
    catch (bool ex){
        cout << ex;
    }
    catch (...) {
        cout << "Unknown exeption" << endl;
    }
    */
}


