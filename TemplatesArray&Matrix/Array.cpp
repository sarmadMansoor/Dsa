#include"Array.h"
#include <iostream>
using namespace std;
template<typename T>
Array<T>::Array(initializer_list<T> x)
{
	if (x.size() == 0)
	{
			data = nullptr;
			size = 0;
			return;
	}
	size = x.size();
	data = new T[size];
	int i = 0;
	for (auto a : x)
	{
		data[i] = a;
		i++;
	}
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
	if (!ref.data)
		return *this;
	delete[] data;
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
Array<T>& Array<T>::operator = (Array<T>&& ref)
{
	if (this == &ref)
		return *this;
	if (!ref.data)
		return *this;
	data = ref.data;
	size = ref.size;
	ref.data = nullptr;
	ref.size = 0;
	return *this;
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
void Array<T>::display() const
{
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
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
template<typename T>
int Array<T>::getSize() const
{
	return size;
}
template<typename T>
bool Array<T>::operator! () const
{
	if (!data)
		return true;
	return false;
}
template<typename T>
const T* Array<T>::begin() const
{
	return data;
}
template<typename T>
const T* Array<T>::end() const
{
	return data+size;
}
//template<typename T>
//ostream& operator << (ostream& r, const Array<T>& x)
//{
//	x.display();
//}
//template<typename T>
//istream& operator >> (istream& r, Array<T>& x)
//{
//	T* input;
//	while (cin >> input != '\n')
//	{
//		int i = 0;
//		x.reSize(size + 1);
//		x[i] = input;
//		i++;
//	}
//}

