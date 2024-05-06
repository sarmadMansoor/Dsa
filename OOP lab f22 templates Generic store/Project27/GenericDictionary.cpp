#include "GenericDictionary.h"
#include "DictionaryPair.h"
#include <iostream>
#include "String.h"
using namespace std;
template <typename T, typename R>
GenericDictionary<T, R>::GenericDictionary()
{
	data = nullptr;
	noOfItems = 0;
	capacity = 0;
}
template <typename T, typename R>
void GenericDictionary<T, R>::addPair(T k, R v)
{
	if (noOfItems == capacity)
	{
		reSize();
	}
	data[noOfItems].setKey(k);
	data[noOfItems].setValue(v);
	noOfItems++;
}
template <typename T, typename R>
R GenericDictionary<T, R>::getValue(T k)
{
	if (data != nullptr)
	{
		for (int i = 0; i < noOfItems; i++)
		{
			if (!(data[i].getKey()==k))
			{
				return data[i].getValue();
			}
		}
	}
	exit(0);
}
template <typename T, typename R>
void GenericDictionary<T, R>::print()
{
	if (data != nullptr)
	{
		for (int i = 0; i < noOfItems; i++)
		{
			cout << data[i].getKey();
			cout << "\t";
			cout<< data[i].getValue();
			cout << "\n";
		}
	}
}

template <typename T, typename R>
GenericDictionary< T,R >::~GenericDictionary()
{
	if (data != nullptr)
	{
		delete[] data;
		capacity = 0;
		noOfItems = 0;
	}
}
template <typename T, typename R>
bool GenericDictionary<T, R>::isFull()
{
	if (noOfItems == capacity)
	{
		return true;
	}
	return false;
}
template <typename T, typename R>
bool GenericDictionary<T, R>::isEmpty()
{
	if (data == nullptr)
		return true;
	return false;
}


template <typename T, typename R>
void  GenericDictionary<T, R>::reSize()
{
	if (data == nullptr)
	{
		data = new DictionaryPair <T, R > [1];
		capacity = 1;
		return;
	}
	int tempCapacity = capacity*2;
	int tempNOE = noOfItems;
	DictionaryPair<T, R > * tempData = new  DictionaryPair <T, R >[tempCapacity];
	for (int i = 0; i < noOfItems; i++)
	{
		tempData[i] = data[i];
	/*	tempData[i].setKey(data[i].getKey()) ;
		tempData[i].setValue(data[i].getValue()) ;*/
	}
	this->~GenericDictionary();
	data = tempData;
	capacity = tempCapacity;
	noOfItems = tempNOE;

}