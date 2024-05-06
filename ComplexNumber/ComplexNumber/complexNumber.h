#ifndef COMPLEX_NUMBER_H
#define  COMPLEX_NUMBER_H
#include <iostream>
using namespace std;
template <typename T>
class Complex
{
	template <typename T >
	friend ostream& operator<< (ostream& out, Complex <T>& ref);
	T real, imag;
public:
	Complex();
	Complex(T a, T b);
	Complex<T> add(const  Complex<T>& ref);
	Complex<T> subtract (const Complex<T>& ref);;
	Complex<T> multiply (const Complex<T>& ref);
	Complex<T> divide(const Complex<T>& ref);
	Complex <T> conjugate();
	double magnitude();
	void display();
};
#endif  COMPLEX_NUMBER_H

