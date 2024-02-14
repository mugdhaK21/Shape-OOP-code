#include <iostream>
#include <cstring>
#include "shape.h"
using namespace std;

int main()
{
    Shape* s[100];
    int i = 0;
    char ch;

    do {
        cout << "Enter the shape: " << endl;
        cin >> ch;
        switch (ch) {
        case 'c': 
            s[i]=new Circle();
            s[i]->accept();
            s[i]->display();
            i++;
            break;
        
        case 'r': 
            s[i] = new Rectangle();
            s[i]->accept();
            s[i]->display();
            i++;
            break;
        
        case 's': 
            s[i] = new Sphere();
            s[i]->accept();
            s[i]->display();
            i++;
            break;
        
        case 't': 
            s[i] = new Triangle();
            s[i]->accept();
            s[i]->display();
            i++;
            break;
        
        case 'y': 
            s[i] = new Cylinder();
            s[i]->accept();
            s[i]->display();
            i++;
            break;
        
        case 'b': 
            s[i] = new Cuboid();
            s[i]->accept();
            s[i]->display();
            i++;
            break;
        
        }
    } while (ch!='q');

   
    int count = Shape::get_count();
    cout << "The total number of shapes are: " << count<<endl;
}
