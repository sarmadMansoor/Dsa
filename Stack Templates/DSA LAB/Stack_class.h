#ifndef STACK_H
#define STACK_H
#include<iostream>
using namespace std;
template <typename T>
class Stack
{
	T* stack;
	int capacity;
	int topIndex;
public:
	Stack(int);
	~Stack();
	bool isEmpty();
	bool isFull();
	T top();
	T pop();
	void push(T);
};
#endif




































//#ifndef STACK_H
//#define STACK_H
//template <typename T>
//class Stack
//{
//	T* data;
//	int top;
//	int size;
//	void reSize(int cap);
//public:
//	Stack();
//	~Stack();
//	Stack(const Stack<T>& rfs);
//	Stack<T> & operator = (const Stack<T>& rfs);
//	bool isFull();
//	bool isEmpty();
//	void push(T rfs);
//	T pop();
//	T stackTop();
//};
//#endif // !STACK_H
