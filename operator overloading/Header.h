#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int** data;

public:
    Matrix(int r, int c); // Constructor
    Matrix(const Matrix& other); // Copy Constructor
    ~Matrix(); // Destructor

    // Overloaded Operators
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix& operator++(); // Prefix Increment
    Matrix operator++(int); // Postfix Increment
    Matrix& operator--(); // Prefix Decrement
    Matrix operator--(int); // Postfix Decrement
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    friend ostream& operator<<(std::ostream& os, const Matrix& matrix);
    friend istream& operator>>(std::istream& is, Matrix& matrix);
};

#endif
