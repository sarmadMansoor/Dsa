#ifndef POLYNOMIAL_CLASS_H
#define POLYNOMIAL_CLASS_H 
#include "Term_Class.h"
class Polynomial
{
	Term* data;
	int noOfTerms;
	int capacity;
	bool findElement(int degree);
	void reSize();
	void bubbleSort();
public:
	Polynomial();
	Polynomial(int num);
	void print();
	Polynomial& operator =(const Polynomial& rfs);
	Polynomial(const Polynomial& rfs);
	~Polynomial();
	Polynomial add(const Polynomial& other);
	float evaluateHorner(float x);
	void addTerm(int coeff, int exp);
	Polynomial subtract(const Polynomial& other);
	Polynomial multiply(const Polynomial& other);

};
#endif POLYNOMIAL_CLASS_H 
