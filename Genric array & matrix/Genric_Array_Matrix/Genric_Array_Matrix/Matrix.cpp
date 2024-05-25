
#include"Matrix.h"
#include <iostream>
template<typename T>
void Matrix<T>::createMatrix(int r, int c)
{
    data.reSize(r);
    for (int i = 0; i < r; i++)
    {
        data[i].reSize(c);
    }
}
template<typename T>
Matrix<T>::Matrix() : data()
{
    rows = 0;
    cols = 0;
}
template<typename T>
Matrix<T>::Matrix(int r, int c) : Matrix()
{
    rows = r;
    cols = c;
    createMatrix(r, c);
}
template<typename T>
bool Matrix<T>::operator==(const Matrix<T>& rhs) const
{
    if (rows != rhs.rows || cols != rhs.cols) 
    {
        return false;
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j) 
        {
            if (data[i][j] != rhs.data[i][j]) 
            {
                return false;
            }
        }
    }
    return true;
}
template<typename T>
Matrix<T> Matrix<T>::transpose() const {
    Matrix<T> result(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[j][i] = data[i][j];
        }
    }
    return result;
}
template<typename T>
Matrix<T> Matrix<T>::add(const Matrix<T>& other) const 
{
    if (rows != other.rows || cols != other.cols) 
    {
        exit(0);
    }

    Matrix<T> result(rows, cols);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j) 
        {
            result[i][j] = data[i][j] + other[i][j];
        }
    }

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::multiply(const Matrix<T>& other) const 
{
    // Check if the matrices can be multiplied
    if (cols != other.rows)
    {
        exit(0);
    }

    Matrix<T> result(rows, other.cols);

    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < other.cols; ++j) 
        {
            T sum = 0;
            for (int k = 0; k < cols; ++k) 
            {
                sum += data[i][k] * other[k][j];
            }
            result[i][j] = sum;
        }
    }

    return result;
}

template<typename T>
bool Matrix<T>::isSymmetric() const
{
    if (rows != cols) {
        return false;
    }
    Matrix<T> transposed = this->transpose();
    return (*this == transposed);
}
template<typename T>
int Matrix<T>::getRows() const
{
    return rows;
}
template<typename T>
int Matrix<T>::getColumns() const
{
    return cols;
}
template<typename T>
Matrix<T>::Matrix(const Matrix& rfs):Matrix()
{
    rows = rfs.rows;
    cols = rfs.cols;
    data = rfs.data;
}
template<typename T>
Matrix <T>& Matrix<T>:: operator = (const Matrix <T>& rfs)
{
    if (this == &rfs)
        return *this;
    this->~Matrix();
    rows = rfs.rows;
    cols = rfs.cols;
    data = rfs.data;
    return *this;
}
template<typename T>
Matrix<T>::~Matrix()
{
    
}
template<typename T>
void Matrix<T>::display() const
{
    if (rows > 0 && cols > 0)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";

            }
            // data[i].display();
            cout << endl;
        }
    }
}
template<typename T>
void Matrix<T>::reSize(int r, int c)
{
    data.reSize(r);
    for (int i = 0; i < r; i++)
        data[i].reSize(c);
    rows = r;
    cols = c;
}
template<typename T>
Array<T>& Matrix<T>::operator[](int index)
{
    return data[index];
}
template<typename T>
const Array<T>& Matrix<T>::operator[](int index) const
{
    return data[index];
}