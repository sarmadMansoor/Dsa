#ifndef BOOK_H
#define  BOOK_H
#include "String.h"
#include "Media.h"
class Book:public Media
{
	String author;
	String ISBN;
public:
	Book();
	Book(String T, String A, String ISB);
	void display();
	 Media* clone() const;
	 Media* fresh() const;
};
#endif// 

