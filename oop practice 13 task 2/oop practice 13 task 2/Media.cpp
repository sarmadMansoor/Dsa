#include <iostream>
#include "Media.h"
using namespace std;
Media::Media() :title("") {};
Media::Media(const String& a) :title(a)
{

}
void Media::setTitle(const String & a)
{
	title = a;
}
String Media::getTitle()
{
	return title;
}
