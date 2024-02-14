#include <iostream>
#include "book.h"
#include<cstring>
using namespace std;

int main()
{
    // cout << "\t\tBOOKS" << endl;
       // cout << "\t\tBOOKS" << endl;
    Book b1;
    b1.set_name("Mathematics");
    b1.set_authors("Albert Einstein,J.J Thomson,Ernest Rutherford");
    b1.set_type("novel");
    b1.set_price(2000);
    //Date d1;
   // d1.set_date(18, 1, 2024);
    b1.set_date(12, 8, 2020);
    b1.display();
    cout << "The discount on this book is: " << b1.discount() << endl << endl;
    Book b2("Physics", "Albert Einstein,J.J Thomson,Ernest Rutherford,John Dalton,James Chadwick", "scientific", 500, 18,4,2021);
    b2.display();
    cout << "The discount on this book is: " << b2.discount() << endl << endl;
    Book b3;
    b3.accept();
    b3.display();
    cout << "The discount on this book is: " << b3.discount() << endl;
    Book b4(b3);
    b4.display();
    cout << b4.get_total_books();
    return 0;
}