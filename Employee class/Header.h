#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Date {
	int date;
	int month;
	int year;

public:
	Date();
	Date(int date, int month, int year);
	void display();
};

class Employee
{
	char name[20];
	float salary;
	static int total_employees;
	int emp_id;
	Date Joining_Date;
public:

	Employee();
	Employee(const char* namecp, float sal, Date d);
	char* get_name();
	void set_name(const char* namecp);

	float get_salary();
	void set_salary(float sal);
	void display();
	static int get_total_employees();
	int get_id();
	~Employee();
};
#endif 