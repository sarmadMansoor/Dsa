#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
template<typename T>
class Array
{
	T* data;
	int size;
	bool isValidIndex(int index) const;

public:
	Array(int = 0);
	~Array();
	Array(const Array<T>&);
	Array<T>& operator = (const Array<T>&);
	T& operator [] (int index);
	const T& operator [] (int) const;
	int getCapacity() const;
	void reSize(int newCap);
};

#endif // !ARRAY_H