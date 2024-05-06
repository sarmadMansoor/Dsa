#include <iostream>
#include "Set.h"
using namespace std;
//template <typename T>
//Set<T>::Set():data()
//{
//
//}
template<typename T>
Set<T>::Set(initializer_list<T> x) :data(x)
{
	noOfElement = x.size();
}
template<typename T>
bool Set<T>::isMember(int val) const
{
	for (int i = 0; i < noOfElement; i++)
	{
		if (data[i] == val)
		{
			return true;
		}
	}
	return false;
}
template<typename T>
void Set<T>::insert(int element)
{
	//if (isMember(element))
		//return;
	if (noOfElement >= data.getSize())
	{
		if (data.getSize() == 0)
			reSize(2);
		else
			reSize(data.getSize() * 2);
	}
	data[noOfElement] = element;
	noOfElement = noOfElement + 1;
}
template<typename T>
int Set<T>::getCardinality() const
{
	return noOfElement;
}
template<typename T>
void Set<T>::reSize(int newCapacity)
{
	if (newCapacity == data.getSize())
		return;
	if (newCapacity < data.getSize() && newCapacity < noOfElement)
		noOfElement = newCapacity;
	data.reSize(newCapacity);
}
template<typename T>
void Set<T>::print() const
{
	if (noOfElement == 0)
	{
		cout << "{ }";
		return;
	}

	cout << "{";
	for (int i = 0; i < getCardinality(); i++)
	{ 
		cout << data[i];
		if (i < getCardinality() - 1)
			cout << ", ";
	}
	cout << "}" << endl;
}
template<typename T>
int Set<T>::findIndex(int val) const
{
	for (int i = 0; i < noOfElement; i++)
	{
		if (data[i] == val)
		{
			return i;
		}
	}
	return -1;
}
template<typename T>
int Set<T>::getCommonElements(const Set<T>& s2) const
{
	int cnt = 0;
	for (int i = 0; i < getCardinality(); i++)
	{
		for (int j = 0; j < s2.getCardinality(); j++)
		{
			if (data[i] == s2.data[j])
			{
				cnt = cnt + 1;
			}
		}
	}
	return cnt;
}
template<typename T>
void Set<T>::remove(int element)
{
	if (!isMember(element))
		return;
	int index = findIndex(element);
	for (int i = index; i < noOfElement - 1; i++)
	{
		data[i] = data[i + 1];
	}
	noOfElement = noOfElement - 1;
}
template<typename T>
bool Set<T>::isS2SubSet(Set s2) const
{
	if (s2.data.getSize() == 0)
		return true;
	int	elements = s2.getCardinality();
	int i = 0, cnt = 0;
	while (i < elements)
	{
		if (isMember(s2.data[i]))
			cnt = cnt + 1;
		i = i + 1;
	}
	if (cnt == elements)
		return true;
	return false;
}
template<typename T>
bool Set<T>::isCallingSubSet(Set<T> s2) const
{
	if (data.getSize() == 0)
		return true;
	int elements = getCardinality();
	int i = 0, cnt = 0;
	while (i < elements)
	{
		if (s2.isMember(data[i]))
			cnt = cnt + 1;
		i = i + 1;
	}
	if (cnt == elements)
		return true;
}
template<typename T>
bool Set<T>::isImproperSubSet(Set<T> s2) const
{
	if (data.getSize() == 0 && s2.data.getSize() == 0)
		return true;
	if (getCardinality() != s2.getCardinality())
		return false;
	else
	{

		bool status = isCallingSubSet(s2);
		return status;
	}
}
template<typename T>
int Set<T>::isSubSet(Set<T> s2) const
{
	if (isImproperSubSet(s2))
		return 2;
	if (isCallingSubSet(s2))
		return 1;
	if (isS2SubSet(s2))
		return -1;
	else
		return 0;
}
template<typename T>
Set<T> Set<T>::calcUnion(const Set<T>& s2) const
{
	int cap = getCardinality() + s2.getCardinality() - getCommonElements(s2);
	Set s{ cap };
	int i;
	for (i = 0; i < getCardinality(); i++)
	{
		s.data[i] = data[i];
		s.noOfElement = s.noOfElement + 1;
	}
	for (int j = 0; j < s2.getCardinality(); j++)
	{
		if (!isMember(s2.data[j]))
		{
			s.data[i] = s2.data[j];
			s.noOfElement = s.noOfElement + 1;
			i = i + 1;
		}
	}
	return s;
}
template<typename T>
Set<T> Set<T>::calcIntersection(const Set<T>& s2) const
{
	int cap = getCommonElements(s2);
	Set s{ cap };
	int k = 0;
	for (int i = 0; i < getCardinality(); i++)
	{
		for (int j = 0; j < s2.getCardinality(); j++)
		{
			if (data[i] == s2.data[j])
			{
				s.data[k] = data[i];
				s.noOfElement = s.noOfElement + 1;
				k = k + 1;
			}
		}
	}
	return s;
}
template<typename T>
Set<T> Set<T>::calcDifference(const Set<T>& s2) const
{
	int cap = getCardinality() - getCommonElements(s2);
	Set s{ cap };
	int k = 0;
	for (int i = 0; i < getCardinality(); i++)
	{
		if (!s2.isMember(data[i]))
		{
			s.data[k] = data[i];
			k = k + 1;
			s.noOfElement = s.noOfElement + 1;
		}
	}
	return s;
}
template<typename T>
Set<T> Set<T>::calcSymmetricDifference(const Set<T>& s2) const
{
	Set Union = calcUnion(s2);
	Set interSection = calcIntersection(s2);
	Set symmDiff = Union.calcDifference(interSection);
	return symmDiff;
}

