#include"Array.h"
#include <iostream>
using namespace std;
template<typename T>
Array<T>::Array(int cap)
{
	
	size = cap;
	data = new T[size];

}
template<typename T>
bool Array<T>::isValidIndex(int index) const
{
	if (index < size)
		return true;
	return false;
}
template<typename T>
Array<T>& Array<T>::operator = (const Array <T>& ref)
{
	if (this == &ref)
		return *this;
	this->~Array();
	if (!ref.data)
		return *this;
	data = new T[ref.size];
	for (int i = 0; i < ref.size; i++)
		data[i] = ref.data[i];
	size = ref.size;
	return *this;
}
template<typename T>
Array<T>::Array(const Array<T>& ref)
{
	if (this == &ref)
		return;
	if (!ref.data)
		return;
	data = new T[ref.size];
	for (int i = 0; i < ref.size; i++)
		data[i] = ref.data[i];
	size = ref.size;
}
template<typename T>
int Array<T>::getCapacity() const
{
	return size;
}
template<typename T>
Array<T>::~Array()
{

	if (data)
	{
		delete[] data;
		data = nullptr;
	}
	size = 0;
}
template<typename T>
const T& Array<T>::operator [](int index) const
{
	if (isValidIndex(index))
		return data[index];
	exit(0);
}
template<typename T>
T& Array<T>::operator[](int index)
{
	if (isValidIndex(index))
		return data[index];
	exit(0);
}

template<typename T>
void Array<T>::reSize(int s)
{
	if (s <= 0)
	{
		this->~Array();
		size = 0;
		return;
	}
	T* temp = new T[s];
	int i = 0;
	while (i < size && i < s)
	{
		temp[i] = data[i];
		i = i + 1;
	}
	this->~Array();
	size = s;
	data = temp;
}

