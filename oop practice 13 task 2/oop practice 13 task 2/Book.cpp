#include <iostream>
#include "Book.h"
using namespace std;
Book::Book():Media()
{

}
Book::Book(String T, String A, String ISB):Media(T),author(A),ISBN(ISB)
{

}
void Book::display()
{
	cout << "The title of Media is : " << getTitle() << endl;
	cout << "The name of author is : " << author << endl;
	cout << "The ISBN Number is : " << ISBN << endl;
}
Media* Book::clone() const
{
	return new Book(*this);
}
Media* Book::fresh() const
{
	return  new Book{};
}
