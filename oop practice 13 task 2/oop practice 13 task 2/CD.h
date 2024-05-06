#ifndef CD_H
#define CD_H
#include "Media.h"
#include "String.h"
class CD:public Media
{
	int capacity;
public:
	//using Media::Media;
	CD();
	CD(String T, int cap);
	void display();
	Media* clone() const;
	Media* fresh() const;
};
#endif CD_H


