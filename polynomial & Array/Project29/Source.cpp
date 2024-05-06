#include<iostream>
#include "Polynomial_Class.h"
#include "Array.h"
using namespace std;

//template<typename T>
//Array <T> findElements(Array<T> nums, int k)
//{
//	Array<int> a{2};
//	int j = nums.getNoOfTerm() - 1; int i = 0;
//	while (i < j)
//	{
//		int num1 = nums[i], num2 = nums[j];
//		if (num1 + num2 < k)
//		{
//			i = i + 1;
//			//j = j - 1;
//		}
//		else if (num1 + num2 > k)
//		{
//			j--;
//		}
//		else
//		{
//			a.insert(0,num1);
//			a.insert(1,num2);
//			break;
//		}
//	}
//	return a;
//}
int main()
{
		/*Array<int> a{};
		a.add(2);
		a.add(4);
		a.add(6);
		a.add(12);
		a.findNewElements(10).display();*/
	//findElements(a, 10).display();
	//a.add(15);
	////a.display();
	//a.insert(9999999, 5);
	//a.remove(12);
	//a.sort();
	//a.display();
	Polynomial p1{ };
	p1.addTerm(7, 2);
	p1.addTerm(8, 1);
	p1.addTerm(2, 0);
//	p1.print();
	Polynomial p2{};
	p2.addTerm(8, 2);
	p2.addTerm(6, 1);
	p2.addTerm(5, 0);

	p1.multiply(p2).print();
	//p1.addTerm(-5, 1);

	//p1.addTerm(2, 7);
	//p1.addTerm(2, 0);*/


	//Polynomial p2 = p1;
	//p2.addTerm(7, 3);
	//p2.add(p1).print();
	//p2 = p1;

//	p2.print();
	// Polynomial p2(5);
	// p2.addterm(2, 5);
	// p2.addterm(6, 1);
	// p2.addterm(3, 7);
	// p2.addterm(3, 2);
	// p2.addterm(5, 0);
	/*Polynomial p3 = p1 + p2;
	cout << endl;
	p2.print();
	cout << endl;
	p3.print();*/
	//cout << p1.getDegree();
	// Polynomial p3 = p2.antiDerivative();
	// p2.print();
	// cout << endl;
	// p3.print();
	/*p2.addToCoefficient(2,5);
	cout << p2.getCoefficient(7);
	cout << endl;*/
	//cout << p1(2);
	//p3.print();
}


//class Polynomial
//{
//	Term* data;
//	int noOfTerms;
//	int capacity;
//	void resize(int cap);
//	int search(int);
//public:
//	Polynomial();
//	Polynomial(int);
//	void addterm(float, int);
//	void print();
//	Polynomial(const Polynomial& obj);
//	int getDegree();
//	void clear();
//	double operator()(int value);
//	Polynomial operator+(const Polynomial& rhs);
//	Polynomial derivative();
//	void setCoefficient(float, int);
//	void addToCoefficient(float, int);
//	Polynomial antiDerivative();
//	float getCoefficient(int);
//	~Polynomial();
//};
//Polynomial::Polynomial()
//{
//	capacity = 0;
//	noOfTerms = 0;
//	data = nullptr;
//}
//Polynomial::Polynomial(int n)
//{
//	noOfTerms = 0;
//	capacity = n;
//	data = new Term[capacity];
//}
//void Polynomial::resize(int newcap)
//{
//	Term* temp = new Term[newcap];
//	int size = newcap < capacity ? newcap : capacity;
//	for (int i = 0; i < size; i++)
//	{
//		temp[i] = data[i];
//	}
//	int n = noOfTerms;
//	this->~Polynomial();
//	data = temp;
//	capacity = newcap;
//	noOfTerms = n;
//}
//Polynomial::Polynomial(const Polynomial& obj)
//{
//	capacity = obj.capacity;
//	noOfTerms = obj.noOfTerms;
//	data = new Term[capacity];
//	for (int i = 0; i < obj.noOfTerms; i++)
//		data[i] = obj.data[i];
//}
//void Polynomial::addterm(float c, int e)
//{
//	if (c == 0)
//		return;
//	if (noOfTerms == capacity)
//		resize(capacity * 2);
//	if (noOfTerms == 0)
//	{
//		data[0].setCoefficient(c);
//		data[0].setExponent(e);
//		noOfTerms++;
//	}
//	else
//	{
//		for (int i = noOfTerms; i >= 0; i--)
//		{
//			if (data[i - 1].getExponent() < e)
//			{
//				data[i].setExponent(e);
//				data[i].setCoefficient(c);
//				noOfTerms++;
//				return;
//			}
//			else if (data[i - 1].getExponent() == e)
//			{
//				data[i - 1].setCoefficient(data[i - 1].getCoefficient() + c);
//				return;
//			}
//			else if (data[i - 1].getExponent() > e)
//			{
//				data[i] = data[i - 1];
//			}
//		}
//	}
//}
//int Polynomial::search(int p)
//{
//	int l = 0, h = noOfTerms - 1;
//	int m;
//	while (l <= h)
//	{
//		m = l + (h - l) / 2;
//		if (data[m].getExponent() == p)
//		{
//			return m;
//		}
//		else if (data[m].getExponent() < p)
//		{
//			l = m + 1;
//		}
//		else
//		{
//			h = m - 1;
//		}
//	}
//	return -1;
//}
//int Polynomial::getDegree()
//{
//	return data[noOfTerms - 1].getExponent();
//}
//void Polynomial::clear()
//{
//	noOfTerms = 0;
//}
//double Polynomial:: operator()(int value)
//{
//	float result = 0;
//	int temp = 1;
//	int size = this->getDegree();
//	for (int i = 0; i < size; i++)
//		temp *= value;
//	for (int i = noOfTerms - 1; i >= 0; i--)
//	{
//		result += temp * data[i].getCoefficient();
//		for (int j = 0; j < data[i].getExponent() - data[i - 1].getExponent(); j++)
//		{
//			temp = temp / value;
//		}
//	}
//	return result;
//}
//Polynomial Polynomial::operator+(const Polynomial& obj)
//{
//	int count = this->noOfTerms + obj.noOfTerms;
//	Polynomial temp(count);
//	int i = 0, j = 0;
//	int e1 = 0, e2 = 0;
//	while (i < this->noOfTerms && j < obj.noOfTerms)
//	{
//		e1 = this->data[i].getExponent();
//		e2 = obj.data[j].getExponent();
//		if (e1 == e2)
//		{
//			temp.data[temp.noOfTerms].setCoefficient(this->data[i].getCoefficient() + obj.data[j].getCoefficient());
//			temp.data[temp.noOfTerms].setExponent(e1);
//			i++;
//			j++;
//			temp.noOfTerms++;
//		}
//		else if (e1 < e2)
//		{
//			temp.data[temp.noOfTerms].setCoefficient(this->data[i].getCoefficient());
//			temp.data[temp.noOfTerms].setExponent(e1);
//			i++;
//			temp.noOfTerms++;
//		}
//		else
//		{
//
//			temp.data[temp.noOfTerms].setCoefficient(obj.data[j].getCoefficient());
//			temp.data[temp.noOfTerms].setExponent(e2);
//			j++;
//			temp.noOfTerms++;
//		}
//	}
//	if (i < this->noOfTerms)
//	{
//		while (i < this->noOfTerms)
//		{
//			temp.data[temp.noOfTerms].setCoefficient(this->data[i].getCoefficient());
//			temp.data[temp.noOfTerms].setExponent(this->data[i].getExponent());
//			i++;
//			temp.noOfTerms++;
//		}
//	}
//	else if (j < obj.noOfTerms)
//	{
//		while (j < obj.noOfTerms)
//		{
//			temp.data[temp.noOfTerms].setCoefficient(obj.data[j].getCoefficient());
//			temp.data[temp.noOfTerms].setExponent(obj.data[j].getExponent());
//			j++;
//			temp.noOfTerms++;
//		}
//	}
//	return temp;
//	/*Polynomial temp = *this;
//	for (int i = 0; i < obj.noOfTerms; i++)
//		temp.addterm(obj.data[i].getCoefficient(), obj.data[i].getExponent());
//	return temp;*/
//}
//Polynomial Polynomial::derivative()
//{
//	Polynomial temp(noOfTerms);
//	for (int i = 0; i < noOfTerms; i++)
//	{
//		if (this->data[i].getExponent() > 0)
//		{
//			temp.data[temp.noOfTerms].setCoefficient(this->data[i].getCoefficient() * this->data[i].getExponent());
//			temp.data[temp.noOfTerms].setExponent(this->data[i].getExponent() - 1);
//			temp.noOfTerms++;
//		}
//	}
//	return temp;
//}
//void Polynomial::setCoefficient(float c, int e)
//{
//	int temp = search(e);
//	if (temp == -1)
//		addterm(c, e);
//	else
//		data[temp].setCoefficient(c);
//}
//void Polynomial::addToCoefficient(float c, int e)
//{
//	int temp = search(e);
//	if (temp != -1)
//		data[temp].setCoefficient(data[temp].getCoefficient() + c);
//}
//Polynomial Polynomial::antiDerivative()
//{
//	Polynomial temp(noOfTerms);
//	for (int i = 0; i < noOfTerms; i++)
//	{
//		temp.data[temp.noOfTerms].setCoefficient(this->data[i].getCoefficient() / (this->data[i].getExponent() + 1));
//		temp.data[temp.noOfTerms].setExponent(this->data[i].getExponent() + 1);
//		temp.noOfTerms++;
//	}
//	return temp;
//}
//float Polynomial::getCoefficient(int e)
//{
//	int temp = search(e);
//	if (temp != -1)
//		return data[temp].getCoefficient();
//	exit(0);
//}
//void Polynomial::print()
//{
//	for (int i = noOfTerms - 1; i >= 0; i--)
//	{
//		if (data[i].getExponent() == 0)
//			cout << data[i].getCoefficient() << " ";
//		else
//		{
//			cout << data[i].getCoefficient() << "x^";
//			cout << data[i].getExponent() << " ";
//		}
//	}
//}
//Polynomial::~Polynomial()
//{
//	capacity = 0;
//	noOfTerms = 0;
//	delete[] data;
//	data = nullptr;
//}