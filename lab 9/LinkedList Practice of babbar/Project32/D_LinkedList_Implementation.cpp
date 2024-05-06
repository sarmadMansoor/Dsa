#include "D_LinkedList.cpp"
#include "string.h"
class Song
{
public:
	int songID;
	string title;
	string artist;
	string album;
	int durationInSecond;
	Song(int id, string t, string a, string al, int dur);
};
//template class D_LinkedList<int>;
//template class D_LinkedList<double>;
//template class D_LinkedList<string>;
template class D_LinkedList<Song>;