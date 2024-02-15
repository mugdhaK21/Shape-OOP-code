#ifndef MATRIX_CPP
#define MATRIX_CPP
#include "Header.h"
using namespace std;

// Constructor
Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    data = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols](); // Initialize to zero
    }
}

// Copy Constructor
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j]; // Copy elements from other matrix
        }
    }
}

// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
    data = nullptr;
}

// Overloaded Operators

Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j]; // Perform matrix addition
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j]; // Perform matrix subtraction
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j]; // Perform matrix multiplication
            }
        }
    }
    return result;
}

Matrix& Matrix::operator++() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ++data[i][j]; // Prefix Increment
        }
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix temp(*this); // Create a copy
    ++(*this); // Call prefix increment
    return temp; // Return the original value
}

Matrix& Matrix::operator--() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            --data[i][j]; // Prefix Decrement
        }
    }
    return *this;
}

Matrix Matrix::operator--(int) {
    Matrix temp(*this); // Create a copy
    --(*this); // Call prefix decrement
    return temp; // Return the original value
}

Matrix& Matrix::operator+=(const Matrix& other) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] += other.data[i][j]; // Compound assignment addition
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] -= other.data[i][j]; // Compound assignment subtraction
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    // Check for incompatible dimensions before matrix multiplication
    if (cols != other.rows) {
        cout << "Error: Cannot multiply matrices with incompatible dimensions." << endl;
        return *this;
    }

    // Perform matrix multiplication
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j]; // Perform multiplication
            }
        }
    }

    // Update data matrix with the result
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            data[i][j] = result.data[i][j]; // Assign the multiplication result back to the current matrix
        }
    }

    return *this;
}


ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}


#endif
