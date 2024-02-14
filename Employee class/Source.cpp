#ifndef EMPLOYEE_CPP
#define EMPLOYEE_CPP
#include "Header.h"
#include<iostream>
#include<cstring>
using namespace std;
int Employee::total_employees = 0;

Date::Date() {
	date = month = year = 0;
}

Date::Date(int d, int m, int y) {

	date = d;
	month = m;
	year = y;
}

void Date::display() {
	cout << date << " " << month << " " << year << endl;
}
Employee::Employee()
{
	strcpy_s(name, " ");
	salary = 0.0f;
	total_employees++;
	emp_id = 100 + total_employees;
	cout << "i am a constructor" << endl;
}

Employee::Employee(const char* namecp, float sal, Date d)
{
	strcpy_s(name, namecp);
	salary = sal;
	total_employees++;
	emp_id = 100 + total_employees;
	Joining_Date = d;
}

void Employee::display()
{
	cout << "Employee details:\nName: " << name << "\nSalary:  " << salary << "\n";
	cout << "ID: " << emp_id << "\n";
	Joining_Date.display();
}

char* Employee::get_name()
{
	return name;
}
void Employee::set_name(const char* namecp)
{
	strcpy_s(name, namecp);
}

float Employee::get_salary()
{
	return salary;
}
void Employee::set_salary(float sal)
{
	salary = sal;
}

int Employee::get_total_employees()
{
	return total_employees;
}

int Employee::get_id()
{
	return emp_id;
}

Employee::~Employee() {
	cout << "Destructor invoked" << endl;
}

#endif 

