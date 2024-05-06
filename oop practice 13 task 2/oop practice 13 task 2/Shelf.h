#ifndef SHELF_H
#define SHELF_H
#include "Media.h"
class Shelf
{
	Media** items;
	int maxSize;
	int currSize;
public:
	Shelf(int a);
	Shelf();
	void insert(Media*);
	void displayContents();
	~Shelf();
	Shelf(const Shelf&);
	Shelf& operator = (const Shelf& r);
};
#endif 

