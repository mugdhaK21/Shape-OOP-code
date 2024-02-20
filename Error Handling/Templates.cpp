#include <iostream>
using namespace std;

// Created a template 
template <class T>
//function to calculate largest of 3 integers using templates
void largest_three(T x, T y, T z)
{
    T largest = x > y ? (x > z ? x : z) : (y > z ? y : z);
    cout << largest << endl;
}
//function to display msg
template <class T>
void display(const char* msg, T num)
{
    cout << msg << " " << num << endl;
}

template <class T1, class T2>
void display(T1 num1, T2 num2)
{
    cout << num1 << " " << num2 << endl;
}

//Function to swap 2 objects
template<class T>
void swap(T* a, T* b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

/*template<class T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}*/

template<class T>
void display_sum(T num1, T num2)
{
    cout << "Sum of " << num1 << " and " << num2 << " is: " << num1 + num2 << endl;
}
template<class T1, class T2>
void display_sum(T1 num1, T2 num2)
{
    cout << "Sum of " << num1 << " and " << num2 << " is: " << num1 + num2 << endl;
}
template<class T>
void display_sum(T num1, T num2, T num3)
{
    cout << "Sum of " << num1 << "," << num2 << " and " << num3 << " is: " << num1 + num2 + num3 << endl;
}

void bubblesort(int a[5], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

template<class T>
void bubblesort(T a[5], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                /*  T tmp = a[j+1];
                  a[j+1] = a[j];
                  a[j] = tmp;*/
                swap(a[j + 1], a[j]);
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    cout << "Hello World!\n";

    largest_three(2, 3, 1);
    largest_three(2.5, 3.6, 1.6);
    display("The value of num is:", 10);
    display(5, 10);
    display(5.1, 10.1);
    display(5.1, 10);
    display(5, 10.1);
    int x = 10, y = 20;
    swap(&x, &y);
    cout << "x:" << x << " y:" << y << endl;
    float x1 = 10.1, y1 = 20.2;
    swap(&x1, &y1);
    cout << "x:" << x1 << " y:" << y1 << endl;

    int x2 = 10, y2 = 20;
    int& xref = x2;
    int& yref = y2;
    swap(xref, yref);
    cout << "Reference: x:" << x2 << " y:" << y2 << endl;
    display_sum(3, 4);
    display_sum(3.5, 4.6);
    display_sum(3, 5, 4);
    int arr[5] = { 3,1,7,2,6 };
    bubblesort(arr, 5);
    double arr1[5] = { 3.1,1.2,7.5,2.4,6.5 };
    bubblesort(arr1, 5);
    return 0;
}

