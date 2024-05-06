#include <iostream>
#include "Magazine.h"
using namespace std;
Magazine::Magazine() :Media() {};
Magazine::Magazine(String T, String M, int y) :Media(T), month(M), year(y) {};
void Magazine::display()
{
	cout << "The title of Media is : " << getTitle() << endl;
	cout << "The year of Publication is : " << year << endl;
	cout << "The publication Month is : " << month << endl;
}
int Magazine::getYear()
{
	return year;
}
Media* Magazine::clone() const
{
	return new Magazine{ *this };
}
Media* Magazine::fresh() const
{
	return new Magazine{};
}
