#include <iostream>
#include "complexNumber.h"
#include <cmath>
using namespace std;

template <typename T>
Complex<T>::Complex() :real(0), imag(0)
{}

template <typename T>
Complex<T>::Complex(T a, T b) : real(a), imag(b)
{}


template <typename T>
Complex<T> Complex<T>::add (const Complex<T>& ref)
{
	return Complex<T>{ real + ref.real, imag + ref.imag };
}
template <typename T>
Complex<T> Complex<T>::subtract(const Complex<T>& ref)
{
	return Complex<T>{ real - ref.real, imag - ref.imag };
}
template <typename T>
Complex<T> Complex<T>::multiply (const Complex<T>& ref)
{
	return Complex<T> { ((real* ref.real) - (imag * ref.imag)), ((real* ref.imag) + (imag * ref.real)) };
}
template <typename T>
Complex<T> Complex<T>::divide (const Complex<T>& ref)
{
	T denom = ref.real * ref.real + ref.imag * ref.imag;
	return Complex<T>{ (real* ref.real+ imag * ref.imag) / denom, (imag* ref.real - real * ref.imag) / denom };
}
template <typename T>
Complex <T> Complex<T>::conjugate()
{
	return Complex<T> {real, imag* -1};
}
template <typename T>
double Complex<T>::magnitude()
{
	return sqrt(pow(real, 2) + pow(imag, 2));
}


template <typename T>
void Complex<T>::display()
{
	cout << real;
	imag > -1 ? cout << " + " : cout << ' ';
	cout << imag << "i" << endl;
}



template <typename T >
ostream& operator<< (ostream& out, Complex <T>& ref)
{
	cout << ref.real;
	ref.y > -1 ? cout << " + " : cout << ' ';
	cout << ref.imag << "i" << endl;
	return out;

}