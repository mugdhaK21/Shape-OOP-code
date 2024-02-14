
#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
protected:
    float area;
    float perimeter;
    static int shape_count;
public:
    Shape();
    Shape(float r, float perimeter);
    virtual void calculate_area() = 0;
    virtual void calculate_perimeter() = 0;
    virtual void accept()=0;
    virtual void display()=0;
    static int get_count();
    //float get_area();
};

class Circle :public Shape
{
protected:
    int radius;
public:
    Circle();
    Circle(int r);
    void accept();
    void set_radius(int r);
    int get_radius();
    void calculate_area();
    void calculate_perimeter();
    void display();
};

class Rectangle :public Shape
{
protected:
    int length;
    int breadth;
public:
    Rectangle();
    Rectangle(int l, int b);
    void accept();
    int get_length();
    int get_breadth();
    void calculate_area();
    void calculate_perimeter();
    void display();

};

class Triangle :public Shape
{
protected:
    int base;
    int height;
public:
    Triangle();
    Triangle(int b, int h);
    void accept();
    int get_base();
    int get_height();
    void calculate_area();
    void calculate_perimeter();
    void display();

};

class Sphere :public Circle
{
protected:
    float volume=0;
public:
    Sphere();
    //Sphere(float v);

    void calculate_area();
    void calculate_perimeter();
    void calculate_volume();
    void display();

};

class Cylinder :public Circle
{
protected:
    int height;
    float volume;
public:
    Cylinder();
    Cylinder(int h);
    void accept();
    int get_height();
    void calculate_area();
    void calculate_perimeter();
    void calculate_volume();
    void display();

};

class Cuboid :public Rectangle
{
protected:
    int height;
    float volume;
public:
    Cuboid();
    Cuboid(int l, int b, int h);
    void accept();
    int get_height();
    void calculate_area();
    void calculate_perimeter();
    void calculate_volume();
    void display();

};
#endif

