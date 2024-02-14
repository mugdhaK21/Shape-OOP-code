#ifndef SHAPE_CPP
#define SHAPE_CPP
#include "shape.h"
#include <iostream>
#include <cmath>
#define M_PI 3.142
using namespace std;

int Shape::shape_count = 0;

// Shape class
Shape::Shape() : area(0), perimeter(0) {
    shape_count++;

}

Shape::Shape(float a, float p) : area(a), perimeter(p) {
    shape_count++;
}

int Shape::get_count(){
    return shape_count;
}

void Shape::display() {
    cout << "Area is : " << area << "\nPerimeter is : " << perimeter << endl;
}

// Circle class
Circle::Circle()  {
    radius = 0;
}

Circle::Circle(int r) : radius(r) {}

void Circle::accept() {
    int r;
    cout << "enter the radius: ";
    cin >> r;
    set_radius(r);
}

void Circle::set_radius(int r) {
    radius = r;
}

int Circle::get_radius() {
    return radius;
}

void Circle::calculate_area() {
    area = M_PI * radius * radius;
}

void Circle::calculate_perimeter() {
    perimeter = 2 * M_PI * radius;
}

void Circle::display() {
    cout << "The radius of circle is : " << get_radius();
    calculate_area();
    calculate_perimeter();
    Shape::display();
}
// Rectangle class
Rectangle::Rectangle() : length(0), breadth(0) {}

Rectangle::Rectangle(int l, int b) : length(l), breadth(b) {}

void Rectangle::accept() {
    int l, b;
    cout << "Enter Length: " << endl;
    cin >> l;
    cout << "Enter Breadth: " << endl;
    cin >> b;
    this->length = l;
    this->breadth = b;
}

int Rectangle::get_length() {
    return length;
}

int Rectangle::get_breadth() {
    return breadth;
}

void Rectangle::calculate_area() {
    area = length * breadth;
}

void Rectangle::calculate_perimeter() {
    perimeter = 2 * (length + breadth);
}

void Rectangle::display() {
    cout << "The Length of rectangle is : " << get_length();
    cout << "The breadth of rectangle is : " << get_breadth();
    calculate_area();
    calculate_perimeter();
    Shape::display();
}
// Triangle class
Triangle::Triangle() : base(0), height(0) {}

Triangle::Triangle(int b, int h) : base(b), height(h) {}

void Triangle::accept() {
    int b, h;
    cout << "Enter base: " << endl;
    cin >> b;
    cout << "Enter height: " << endl;
    cin >> h;
    this->base = b;
    this->height = h;
}
int Triangle::get_base() {
    return base;
}

int Triangle::get_height() {
    return height;
}

void Triangle::calculate_area() {
    area = 0.5 * base * height;
}

void Triangle::calculate_perimeter() {
    int s1, s2;
    cout << "Enter the sides of triangle apart from base: " << endl;
    cin >> s1 >> s2;
       
    perimeter = s1 + s2 + base;
}

void Triangle::display() {
    cout << "The Height of triangle is : " << get_height();
    cout << "The base of triangle is : " << get_base();
    calculate_area();
    calculate_perimeter();
    Shape::display();
}
// Sphere class
Sphere::Sphere() : volume(0) {}

//Sphere::Sphere(float v) : volume(v) {}

void Sphere::calculate_area() {
    area = 4 * M_PI * radius * radius;
}

void Sphere::calculate_perimeter() {
    // Perimeter is not applicable for a sphere
    cout << "Perimeter is not applicable for a sphere." << endl;
    
}

void Sphere::calculate_volume() {
    volume = (4.0 / 3.0) * M_PI * std::pow(radius, 3);
}

void Sphere::display() {
    cout << "The Radius of Sphere is : " << get_radius();
    calculate_area();
    calculate_perimeter();
    calculate_volume();
    Shape::display();
    cout << "Volume of sphere: " << volume << endl;
}

// Cylinder class
Cylinder::Cylinder() : height(0), volume(0) {}

Cylinder::Cylinder(int h) : height(h) {}

void Cylinder::accept() {
    cout << "Enter radius "<< endl;
    cin >> radius;
    cout << "Enter height " << endl;
    cin >> height;
}
int Cylinder::get_height() {
    return height;
}

void Cylinder::calculate_area() {
    area = 2 * M_PI * radius * (radius + height);
}

void Cylinder::calculate_perimeter() {

   perimeter = (4 * radius) + (2 * height);
}

void Cylinder::calculate_volume() {
    volume = M_PI * radius * radius * height;
}

void Cylinder::display() {
    cout << "The Radius of cylinder is : " << get_radius();
    //cout << "The length of cylinder is : " << get_length();
    cout << "The height of cylinder is : " << get_height();

    calculate_area();
    calculate_perimeter();
    calculate_volume();
    Shape::display();
    cout << "Volume of : " << volume << endl;
}

// Cuboid class
Cuboid::Cuboid() : height(0), volume(0) {}

Cuboid::Cuboid(int l, int b, int h) : Rectangle(l, b), height(h) {}

void Cuboid::accept() {
    cout << "Enter length " << endl;
    cin >> length;
    cout << "Enter breadth " << endl;
    cin >> breadth;
    cout << "Enter height " << endl;
    cin >> height;
}
void Cuboid::calculate_area() {
    area = 2 * (length * breadth + breadth * height + length * height);
}

void Cuboid::calculate_perimeter() {
    perimeter = 4 * (length + breadth + height);
}

void Cuboid::calculate_volume() {
    volume = length * breadth * height;
}
int Cuboid::get_height() {
    return height;
}

void Cuboid::display() {
    cout << "The length of cuboid is : " << get_length();
    cout << "The breadth of cuboid is : " << get_breadth();
    cout << "The height of cylinder is : " << get_height();
    calculate_area();
    calculate_perimeter();
    calculate_volume();
    Shape::display();
    cout << "Volume of sphere: " << volume << endl;
}
#endif