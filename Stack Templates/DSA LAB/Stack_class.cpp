#include "Stack_class.h"
template <typename T>
Stack<T>::Stack(int cap)
{
	if (cap < 0)
	{
		cout << "Capacity should be greater than 0";
		return;
	}
	stack = new T[cap];
	capacity = cap;
	topIndex = -1;
}
template<typename T>
Stack<T>::~Stack()
{
	if (stack != nullptr)
	{
		delete[] stack;
		stack = nullptr;
		capacity = 0;
		topIndex = 0;
	}
}
template<typename T>
bool Stack<T>::isEmpty()
{
	return (topIndex == -1);
}
template<typename T>
bool Stack<T>::isFull()
{
	return (topIndex == capacity - 1);
}
template<typename T>
T Stack<T>::top()
{
	if (isEmpty())
		return -1;
	else
		return stack[topIndex];
}
template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
		return -1;
	else
		topIndex--;
	return stack[topIndex + 1];
}
template<typename T>
void Stack<T>::push(T x)
{
	if (isFull())
	{
		cout << "Stack is Full!";
		return;
	}
	else
	{
		topIndex++;
		stack[topIndex] = x;
	}
}
































//#include "Stack_class.h"
//#include <iostream>
//using namespace std;
//template <typename T>
//void Stack<T>::reSize(int cap)
//{
//	T* newData = new T[cap];
//	for (int i = 0; i < top; i++)
//		newData[i] = data[i];
//	delete[] data;
//	size = cap;
//	data = newData;
//}
//template <typename T>
//
//Stack<T>::Stack() :data(nullptr), top(0), size(0) {}
//template <typename T>
//
//Stack<T>::~Stack()
//{
//	if (!data)
//		return;
//	delete[] data;
//	size = 0;
//	top = 0;
//}
//template <typename T>
//
//Stack<T>::Stack(const Stack<T>& rfs)
//{
//	*this = rfs;
//}
//template <typename T>
//Stack<T> & Stack<T>::operator = (const Stack<T>& rfs)
//{
//	if (this == &rfs)
//		return *this;
//	this->~Stack();
//	if (!rfs.data)
//		return *this;
//	top = rfs.top;
//	size = rfs.size;
//	data = new T[size];
//	for (int i = 0; i < top; i++)
//	{
//		data[i] = rfs.data[i];
//	}
//	return *this;
//}
//template <typename T>
//bool Stack<T>::isFull()
//{
//	if (top == size)
//		return true;
//	else
//		return false;
//}
//template <typename T>
//bool Stack<T>::isEmpty()
//{
//	if (top == 0)
//		return true;
//	else
//		return false;
//}
//template <typename T>
//void Stack<T>::push(T rfs)
//{
//	if (top == size)
//		reSize(size == 0 ? 1 : size * 2);
//	data[top] = rfs;
//	top++;
//}
//template <typename T>
//T Stack<T>::pop()
//{
//	if (isEmpty())
//		exit(0);
//	T val = data[top - 1];
//	top--;
//	if (top > 0 && top == size / 4)
//		reSize(size / 2);
//	return val;
//}
//template <typename T>
//T Stack<T>::stackTop()
//{
//	if (isEmpty())
//		exit(0);
//	return data[top - 1];
//}
