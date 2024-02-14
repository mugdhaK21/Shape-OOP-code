#ifndef BOOK_CPP
#define BOOK_CPP
#include<iostream>
#include<cstring>
#include "book.h"
int Book::total_books = 0;

using namespace std;
Date::Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int d, int m, int y) {
	day = d;
	year = y;
	month = m;
}
void Date::display() {
	cout << "Date / month / year : " << day << "/" << month << "/" << year << endl;

}

void Date::setDate(int d, int m, int y) {
	if (y > 1600 && y < 2024) {
		if (m > 0 && m < 13) {
			if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
				if (d > 0 && d <= 31) {
					day = d;
					month = m;
					year = y;
				}
			}
			else if (m == 4 || m == 6 || m == 9 || m == 11) {
				if (d > 0 && d < 31) {
					day = d;
					month = m;
					year = y;

				}
			}
			else if (m == 2) {
				if (d > 0 && d <= 28) {
					day = d;
					month = m;
					year = y;
				}
			}
		}
	}
	else {
		cout << "Invalid Date\n";
	}
}

	Book::Book(){
		strcpy_s(bookName, " ");
		strcpy_s(author, " ");
		strcpy_s(type, " ");
		price = 0;
		pd = Date(0, 0, 0);
		total_books += 1;
		id += 100 + total_books;
    }

	Book::Book(const char* n, const char* a, const char* t, float p, int d, int m, int y) {
		strcpy_s(bookName, n);
		strcpy_s(author, a);
		strcpy_s(type, t);
		price = p;
		//pd.setDate(d,m,y);
		pd = Date(d, m, y);
		total_books += 1;
		id += 100 + total_books;
	}

	Book::Book(Book& b)
	{
		strcpy_s(bookName, b.bookName);
		strcpy_s(author, b.author);
		strcpy_s(type, b.type);
		price = b.price;
		pd = b.pd;
		id = b.id;
	}

	Book::~Book()
	{
		cout << "Destructor called\n";
	}

	char* Book::get_name() {
		return bookName;
	}
	char * Book::get_author(){
		return author;
	}

	char* Book::get_type() {
		return type;
	}
	float Book::get_price() {
		return price;
	}
	Date Book::get_Date() {
		return pd;
	}

	void Book::set_authors(const char* a) {
		strcpy_s(author, a);
	}

	void Book::set_name(const char* n) {
		strcpy_s(bookName, n);
	}

	void Book::set_type(const char* t) {
		strcpy_s(type, t);
	}

	void Book::set_date(int d, int m, int y) {
		pd.setDate(d, m, y);
	}
	void Book::set_price(float p) {
		price = p;
	}

	void Book::display() {
		cout << "The book ID is: " << id << endl;
		cout << "The total Book Count is : " << total_books;
		cout << "Book Details: \n Name: " << bookName << endl;
		int i = 0;
		char* a = author;
		while (*(a + i) != '\0')
		{
			if (*(a + i) == ',')
				cout << endl;
			else
				cout << *(a + i);
			i++;
		}
		cout<< "\n Type: " << type << endl;
		pd.display();
		cout << endl;
	}

	void Book::accept() {
		cout << "Enter the book details: \n" << "Name: ";
		cin >> bookName;
		cout << "\n Authors: ";
		cin >> author;
		cout << "\n Type: ";
		cin >> type;
		cout << "\n Price: ";
		cin >> price;
		int d, m, yr;
		cout << "Enter the publication date: \n";
		cout << "Enter Date: ";
		cin >> d;
		cout << "Enter Month: ";
		cin >> m;
		cout << "Enter Year: ";
		cin >> yr;
		pd = Date(d, m, yr);
		cout << endl << endl;
	}

	float Book::discount() {
		float dis;
		if (strcmp(type, "scientific") == 0) {
			dis = 0.2 * price;
		}
		else if (price > 1000) {
			dis = 0.1 * price;
		}
		else {
			dis = 0;
		}

		return dis;
	}

	int Book::get_total_books() {
		return total_books;
	}
	int Book::get_id() {
		return id;
	}


#endif