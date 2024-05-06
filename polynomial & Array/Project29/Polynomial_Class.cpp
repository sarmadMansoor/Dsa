#include <iostream>
#include "Polynomial_Class.h"
using namespace std;

bool Polynomial::findElement(int degree)
{
	int left = 0;
	int right = noOfTerms - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (data[mid].getExponent() == degree)
		{
			return true; // target found
		}
		else if (data[mid].getExponent() < degree)
		{
			left = mid + 1; // search in the right half
		}
		else
		{
			right = mid - 1; // search in the left half
		}
	}

	return false; // target not found
}
void Polynomial::reSize()
{

	capacity = capacity * 2 + 1;
	Term* newData = new Term[capacity];
	for (int i = 0; i < noOfTerms; i++)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}
void Polynomial::bubbleSort()
{
	for (int i = 0; i < noOfTerms - 1; i++)
	{
		for (int j = 0; j < noOfTerms - i - 1; j++)
		{
			if (data[j].getExponent() < data[j + 1].getExponent())
			{
				Term temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

Polynomial::Polynomial() :data(nullptr), noOfTerms(0), capacity(0) {}
Polynomial::Polynomial(int num) :Polynomial()
{
	if (num <= 0)
		return;
	data = new Term[num];
	noOfTerms = 0;
	capacity = num;
}
void Polynomial::addTerm(int coeff, int exp)
{
	/*if (!findElement(exp))
	{
		if (noOfTerms == capacity)
			reSize();
		Term temp{ float(coeff),exp };
		data[noOfTerms] = temp;
		noOfTerms++;
		
	}*/
	if (noOfTerms == capacity)
		reSize();
	Term temp{ float(coeff),exp };
	data[noOfTerms] = temp;
	noOfTerms++;
}
void Polynomial::print()
{
	bubbleSort();
	for (int i = 0; i < noOfTerms; i++)
	{
		if (data[i].getExponent() == 0)
		{
			cout << data[i].getCoefficient() << " ";
		}
		else
		{
			cout << data[i].getCoefficient() << "x^";
			cout << data[i].getExponent() ;
			if (i + 1 != noOfTerms)
			{
				cout << " + ";
			}
		}
	}
}
Polynomial Polynomial::multiply(const Polynomial& other)
{
	Polynomial result{};
	for (int i = 0; i < noOfTerms; i++)
	{
		for (int j = 0; j < other.noOfTerms; j++)
		{
			double coefficient = data[i].getCoefficient() * other.data[j].getCoefficient();
			int exponent = data[i].getExponent() + other.data[j].getExponent();
			
			result.addTerm(coefficient, exponent);
		}
	}
	//result.bubbleSort();
	Polynomial res2{};
	int i = 0;
	while (i < result.noOfTerms)
	{
		float coeff2 = result.data[i].getCoefficient();
		int deg2 = result.data[i].getExponent();
		int add = 0;
		for (int j = i+1; j < result.noOfTerms; j++)
		{
			if (deg2 == result.data[j].getExponent())
			{
				add++;
				coeff2=coeff2+ result.data[j].getCoefficient();
			}
		}
		res2.addTerm(coeff2, deg2);
		if (add > 0)
		{
			i =i+ add - 1;
			add = 0;
		}
		i++;
	}
	return res2;
}
Polynomial  Polynomial::subtract(const Polynomial& other)
{
	Polynomial c;
	for (int i = 0; i < other.noOfTerms; i++)
	{
		c.addTerm(other.data[i].getCoefficient() * -1, other.data[i].getExponent());
	}
	return c.add(*this);
}
Polynomial& Polynomial::operator =(const Polynomial& rfs)
{
	if (this == &rfs)
		return *this;
	this->~Polynomial();
	if (rfs.noOfTerms == 0)
		return *this;
	capacity = rfs.capacity;
	noOfTerms = rfs.noOfTerms;
	data = new Term[capacity];
	for (int i = 0; i < rfs.noOfTerms; i++)
	{
		data[i] = rfs.data[i];
	}
	return *this;
}
Polynomial::Polynomial(const Polynomial& rfs) :Polynomial()
{
	/*if (rfs.noOfTerms == 0)
		return;
	capacity = rfs.capacity;
	noOfTerms = rfs.noOfTerms;
	data = new Term[capacity];
	for (int i = 0; i < rfs.noOfTerms; i++)
	{
		data[i] = rfs.data[i];
	}*/

	* this = rfs;
}
Polynomial::~Polynomial()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
		noOfTerms = 0;
		capacity = 0;
	}
}
Polynomial Polynomial::add(const Polynomial& other)
{
	Polynomial result;
	//result.data[0].exp = 1;
	int i = 0, j = 0;

	// Iterate through both polynomials simultaneously
	while (i < noOfTerms && j < other.noOfTerms)
	{
		int exp1 = data[i].getExponent();
		int exp2 = other.data[j].getExponent();

		// If exponents are equal, add coefficients
		if (exp1 == exp2)
		{
			float coef = data[i].getCoefficient() + other.data[j].getCoefficient();
			if (coef != 0)
			{ // Avoid adding terms with zero coefficients
				result.addTerm(coef, exp1);
			}
			i++;
			j++;
		}
		else if (exp1 > exp2)
		{
			result.addTerm(data[i].getCoefficient(), exp1);
			i++;
		}
		else
		{ // exp1 < exp2
			result.addTerm(other.data[j].getCoefficient(), exp2);
			j++;
		}
	}

	// Add remaining terms from either polynomial
	while (i < noOfTerms)
	{
		result.addTerm(data[i].getCoefficient(), data[i].getExponent());
		i++;
	}
	while (j < other.noOfTerms)
	{
		result.addTerm(other.data[j].getCoefficient(), other.data[j].getExponent());
		j++;
	}

	return result;
}
float Polynomial::evaluateHorner(float x)
{
	float result = 0.0;
	for (int i = 0; i < noOfTerms; i++)
	{
		result = result * x + data[i].getCoefficient();
	}
	return result;
}
