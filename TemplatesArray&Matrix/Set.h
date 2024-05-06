#ifndef MY_SET
#define MY_SET
#include "Array.h"
#include<initializer_list>
template<typename T>
class Set
{
	Array<T> data;
	int noOfElement;

	int findIndex(int) const;
	int getCommonElements(const Set<T>& s2) const;
	bool isImproperSubSet(Set<T> s2) const;
	bool isCallingSubSet(Set<T> s2) const;
	bool isS2SubSet(Set<T> s2) const;

public:

	Set(initializer_list<T> x = {});
	void insert(int element);
	void remove(int element);
	void print() const;
	int getCardinality() const;
	bool isMember(int) const;
	int isSubSet(Set<T> s2) const;
	void reSize(int newCapacity);
	Set<T> calcUnion(const Set<T>& s2) const;
	Set<T> calcIntersection(const Set<T>& s2) const;
	Set<T> calcDifference(const Set<T>& s2) const;
	Set<T> calcSymmetricDifference(const Set<T>& s2) const;
	void displayPowerSet() const;
};

#endif // !MY_SET
