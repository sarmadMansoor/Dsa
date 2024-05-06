#ifndef MEDIA_H
#define MEDIA_H
#include  "String.h"
class Media
{
	String title;
public:
	Media();
	Media(const String&);
	void setTitle(const String &);
	String getTitle();
	virtual void display() =0;
	virtual Media* clone() const = 0;
	virtual Media* fresh() const = 0;
};
#endif// 

