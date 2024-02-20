#include <iostream>
using namespace std;
class MyException
{
    int errorno;
    char msg[40] = "This is user defined exception\n";
public:
    MyException()
    {
        this->errorno = 0;
        strcpy_s(msg, " ");
    }
    MyException(int errorno, const char* message)
    {
        this->errorno = errorno;
        strcpy_s(msg, message);
    }
    int get_error()
    {
        return errorno;
    }
    char* get_errormsg()
    {
        return msg;
    }
};
void divide(int x, int y)
{
    if (y == 0) throw new MyException(101, "divide by zero");
    double z = x / y;
}
int main()
{
    cout << "Hello World!\n";
    try
    {
        divide(1, 0);
        cout << "Division is successful\n";
    }
    catch (MyException* eobj)
    {
        cout << "Division is not possible as denominator is zero\n";
        cout << "Error no: " << eobj->get_error() << "\nMessage: " << eobj->get_errormsg();
    }
    return 0;
}
