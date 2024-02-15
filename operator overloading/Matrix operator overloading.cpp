#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for matrices: ";
    cin >> rows >> cols;

    // Create matrices A and B
    Matrix A(rows, cols);
    cout << "Enter elements for matrix A:" << endl;
    cin >> A;

    Matrix B(rows, cols);
    cout << "Enter elements for matrix B:" << endl;
    cin >> B;

    // Addition
    Matrix C = A + B;
    cout << "Matrix C (A + B):" << endl;
    cout << C;

    // Subtraction
    Matrix D = A - B;
    cout << "Matrix D (A - B):" << endl;
    cout << D;

    // Multiplication
    cout << "Matrix A:" << endl << A;
    cout << "Matrix B:" << endl << B;
    Matrix E = A * B;
    cout << "Matrix E (A * B):" << endl;
    cout << E;

    // Increment and Decrement
    cout << "Matrix A:" << endl << A;
    ++A;
    cout << "Matrix A after prefix increment:" << endl << A;
    A++;
    cout << "Matrix A after postfix increment:" << endl << A;
    --A;
    cout << "Matrix A after prefix decrement:" << endl << A;
    A--;
    cout << "Matrix A after postfix decrement:" << endl << A;

    // Compound Assignment
    Matrix F(rows, cols);
    cout << "Matrix F before compound assignment addition with A:" << endl << F;
    F += A;
    cout << "Matrix F after compound assignment addition with A:" << endl << F;

    Matrix G(rows, cols);
    cout << "Matrix G before compound assignment substraction with A:" << endl << G;
    G -= A;
    cout << "Matrix G after compound assignment substraction with A:" << endl << G;

    Matrix H(rows, cols);
    cout << "Enter the elements of H: " << endl;
    cin >> H;
    cout << "Matrix H before compound assignment multiplication with A:" << endl << H;
    H *= A;
    cout << "Matrix H after compound assignment multiplication with A:" << endl << H;

    return 0;
}

