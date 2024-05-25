#ifndef MATRIX_H
#define MATRIX_H

#include "Array.h"
#include <iostream>
using namespace std;
template<typename T>
class Matrix
{
    int rows, cols;
    Array<Array<T>> data;
    void createMatrix(int r, int c);

public:

    Matrix();
    Matrix(int r, int c);
    Array<T>& operator[](int index);
    const Array<T>& operator[](int index) const;
    int getRows() const;
    int getColumns() const;
   Matrix(const Matrix& rfs);
   Matrix <T>& operator  = (const Matrix <T>& rhs);
   ~Matrix();
    bool operator==(const Matrix<T>& rhs) const;
    Matrix<T> transpose() const;
    bool isSymmetric() const;
    Matrix<T> add(const Matrix<T>& other) const;
    Matrix<T> multiply(const Matrix<T>& other) const;
    void display() const;
    void reSize(int r, int c);

};

#endif // !MATRIX_H