#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;
#include<initializer_list>

template<typename T>
class Array
{
	friend ostream& operator << (ostream&, const Array<T>&);
	friend istream& operator >> (istream&, Array<T>&);


	T* data;
	int size;
	bool isValidIndex(int index) const;

public:
	Array(initializer_list<T> x = {});
	Array<T>& operator = (const Array <T>& ref);
	Array(const Array<T>& ref);
	//Array(Array<T>&& ref);
	Array<T>& operator = (Array<T>&& ref);
	~Array();
	const T& operator [](int index) const;
	T& operator[](int index);
	void display() const;
	void reSize(int s);
	int getSize() const;
	bool operator! () const;
	const T* begin() const;
	const T* end() const;


};

#endif // !ARRAY_H
