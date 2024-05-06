#include <iostream>
#include "Shelf.h"
using namespace std;
Shelf::Shelf(int a)
{
	maxSize = a;
	currSize = 0;
	items = new Media * [maxSize];
}
void Shelf::insert(Media*p )
{
	if (currSize < maxSize)
	{
		items[currSize] = p;
		currSize++;
	}
}
void Shelf::displayContents()
{
	for (int i = 0; i < currSize; i++)
	{
		items[i]->display();
		cout << endl;
	}
}
Shelf::~Shelf()
{
	if (items != nullptr)
	{
		for (int i = 0; i < maxSize; i++)
		{
			delete items[i];
		}
		delete[] items;
		items = nullptr;
		maxSize = 0;
		currSize = 0;
	}
}
Shelf::Shelf()
{
	maxSize = 0;
	currSize = 0;
	items = nullptr;
}
Shelf::Shelf(const Shelf& r):Shelf()
{
	if (r.items == nullptr)
	{
		return;
	}
	items = new Media * [r.maxSize];
	for (int i = 0; i < r.currSize; i++)
	{
		items[i] = r.items[i]->clone();
	}
	maxSize = r.maxSize;
	currSize = r.currSize;
}
Shelf& Shelf::operator = (const Shelf& r)
{
	if (&r == this)
		return *this;
	if (r.items == nullptr)
	{
		Shelf a{};
		return a;
	}
	this->~Shelf();
	maxSize = r.maxSize;
	currSize = r.currSize;
	items = new Media * [maxSize];
	for (int i = 0; i < currSize; i++)
	{
		items[i] = r.items[i]->clone();
	}
}
