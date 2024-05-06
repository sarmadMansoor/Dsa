#ifndef DICTIONARY_PAIR_H
#define DICTIONARY_PAIR_H
#include "String.h"
template <typename T,typename R>
class DictionaryPair
{
	T key;
	R value;
public:
	DictionaryPair();
	DictionaryPair(T k, R v);
	void setKey(T k);
	void setValue(R v);
	T getKey();
	R getValue();

};
#endif DICTIONARY_PAIR_H


