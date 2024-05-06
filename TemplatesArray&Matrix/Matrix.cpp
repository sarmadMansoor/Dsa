#include"Matrix.h"

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
Matrix<T>::Matrix(const Matrix<T>& ref) : Matrix()
{
    if (!ref.data)
        return;
    rows = ref.getRows();
    cols = ref.getColumns();
    createMatrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = ref[i][j];
        }
    }
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