#include<iostream>
#include "Header.h"
using namespace std;
void arrayDisplay(Employee arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Employee " << endl;
		arr[i].display();
	}
}

int main()
{
	Date d(21, 02, 2024);
	Employee e1("Mugdha", 1000, d );
	cout << "BREAK";
	Employee arr[4];
	arr[2] = e1;
    

	arrayDisplay(arr, 4);
	cout << "TOTAL COUNT" << endl;
	
	cout<<Employee::get_total_employees();
	
}