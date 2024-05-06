#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "Media.h"
#include "String.h"
class Magazine:public Media
{
	String month;
	int year;
public:
	Magazine();
	Magazine(String T,String M,int y);
	int getYear();
	void display();
	 Media* clone() const;
	 Media* fresh() const;
};
#endif 

