#ifndef MATRIX_H
#define MATRIX_H

#include "Array.h"
#include <iostream>
#include<initializer_list>
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
    Matrix(const Matrix<T>& ref);
    int getRows() const;
    int getColumns() const;
    void display() const;
    void reSize(int r, int c);
    Array<T>& operator[](int index);
    const Array<T>& operator[](int index) const;
};

#endif // !MATRIX_H
