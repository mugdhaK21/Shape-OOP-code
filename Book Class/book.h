#ifndef BOOK_H
#define BOOK_H

class Date {
	int day, month, year;
public:
	Date();
	Date(int, int, int); 
	void display();
	void setDate(int, int, int);
	//Date get_Date();
};

class Book {
	char bookName[20];
	char author[100];
	char type[20];
	float price;
	Date pd;
	static int total_books;
	int id=0;


public:
	Book();
	Book(const char* n, const char* author, const char* t, float p, int, int, int);
	Book(Book& b);
	~Book();
	char* get_name();
	char* get_author();
	char* get_type();
	float get_price();
	Date get_Date();
	void set_date(int, int, int);
	void set_name(const char* n);
	void set_authors(const char* a);
	void set_type(const char* t);
	void set_price(float p);
	void accept();
	void display();
	float discount();
	static int get_total_books();
	int get_id();
};
#endif