#include "Array.h"
#include <iostream>
#include <stdarg.h>
using namespace std;
template<typename T>
Array <T> Array<T>::findNewElements( int k)
{
	Array<int> a{2};
	int j = noOfElement - 1; int i = 0;
	while (i < j)
	{
		int num1 = data[i], num2 = data[j];
		if (num1 + num2 < k)
		{
			i = i + 1;
			//j = j - 1;
		}
		else if (num1 + num2 > k)
		{
			j--;
		}
		else
		{
			a.insert(0,num1);
			a.insert(1,num2);
			break;
		/*	a[0] = num1;
			a[1] = num2;
			noOfElement = noOfElement + 2;*/
		}
	}
	return a;
}
template<typename T>
int Array<T>::getNoOfTerm()
{
	return noOfElement;
}
template<typename T>
void Array<T>::sort()
{
	for (int i = 0; i < noOfElement - 1; i++)
	{
		for (int j = 0; j < noOfElement - i - 1; j++)
		{
			if (data[j] > data[j + 1])
			{
				T temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}
template <typename T>
int Array<T>::findElement(int element)
{
	for (int i = 0; i < noOfElement; i++)
	{
		if (data[i] == element)
			return i;
	}
	return -1;
}
template <typename T>
void Array<T>::remove(int value)
{
	int index = findElement(value);
	if (index != -1)
	{
		for (int i = index; i < noOfElement; i++)
		{
			data[i] = data[i + 1];
		}
		noOfElement--;
	}
}
template <typename T>
void Array<T>::insert(int index,const T & value)
{
	if (!isValidIndex(index))
	{
		return;
	}

	if (noOfElement == size)
	{
		reSize(size * 2); // Dynamic resizing with efficient doubling strategy
	}

	// Shift elements starting from the insertion point one position right:
	for (int i = noOfElement - 1; i >= index; --i)
	{
		data[i + 1] = data[i];
	}

	// Insert the new value at the specified index:
	data[index] = value;
	++noOfElement;
}
template <typename T>
void Array<T>::add(int value) 
{
	if (noOfElement == size) 
	{
		reSize(size * 2+1);
	}

	// Insert the new element at the end of the array
	data[noOfElement] = value;
	noOfElement++;
}
template <typename T>
bool Array<T>::isValidIndex(int index) const
{
	if (index >= 0 && index <= noOfElement)
		return true;
	else
		return false;
}template <typename T>
void Array<T>::initailize()
{
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
}
template <typename T>
Array<T>::Array():data(0),noOfElement(0),size(0)
{

}

template <typename T>
Array<T>::Array(int cap)
{
	cap < 0 ? size = 0 : size = cap;
	if (cap <= 0)
	{
		data = nullptr;
	}
	else
	{
		data = new T [size];
		initailize();
	}
}
template <typename T>
Array<T>::~Array()
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}
template <typename T>
T& Array<T>::operator[](int index)
{
	return data[index];
	exit(0);
}
template <typename T>
int Array<T>::getSize() const
{
	return size;
}
template <typename T>
void Array<T>::reSize(int newCapacity)
{
	if (newCapacity < 0)
	{
		this->~Array();
		size = 0;
		return;
	}
	T * temp = new  T [newCapacity];
	int i = 0;
	while (i < size && i < newCapacity)
	{
		temp[i] = data[i];
		i++;
	}
	size = newCapacity;
	this->~Array();
	data = temp;
}
template <typename T>
void Array<T>::display() const
{
	if (data != nullptr)
	{
		for (int i = 0; i < noOfElement; i++)
		{
			cout << data[i] << " ";
		}
	}
}
//
//const int Array::num=13;
//Array::Array(int cnt, ...)
//{
//	va_list list;
//	va_start(list, cnt);
//	size = cnt;
//	data = new int[size];// Allocate memory for the data array
//	for (int i = 0; i < cnt; i++)
//	{
//		int val = va_arg(list, int);
//		data[i] = val;
//	}
//	va_end(list);
//}
//int& Array::getSet(int i)
//{
//	if (isValidIndex(i))
//	{
//		return data[i];
//	}
//}
template <typename T>
Array<T>::Array(const Array<T> & rfs)
{
	if (rfs.data != nullptr)
	{
		size = rfs.size;
		data = new T [size];
		for (int i = 0; i < size; i++)
		{
			data[i] = rfs.data[i];
		}
	}
}
template <typename T>
Array<T>& Array<T>::operator =(const Array<T>& rfs)
{
	if (rfs.data == nullptr)
	{
		data = nullptr;
		size = 0;
		return *this;
	}
	if (&rfs == this)
	{
		return *this;
	}
	this->~Array();
	size = rfs.size;
	data = new T [size];
	for (int i = 0; i < size; i++)
	{
		data[i] = rfs.data[i];
	}
	return *this;
}
template <typename T>
const T & Array<T>::operator[] (int index) const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
}
//inline int& Array::getSet(int index) const
//{
//	cout << "Const vala " << endl;
//	if (isValidIndex(index))
//	{
//		return data[index];
//	}
//	//at(2) = 5;//In the statement this->data[4] = 7;, this is a pointer to a 
//	//const Array object. This means that the object itself is const, but it doesn't necessarily mean
//	//that its members are also const.
//
//	//In C++, when you have a const object, you're saying that you won't modify the
//	//object itself through that pointer, but you can still modify its non - const members.
//	//this->data[4] = 7;
//	exit(0);
//}

//Array::Array (const Array& ref):Array()
//{
//	if (ref.data != nullptr)
//	{
//		capacity = ref.capacity;
//		data = new int[capacity];
//		for (int i = 0; i < ref.capacity; i++)
//		{
//			data[i] = ref.data[i];
//		}
//	}
//}