#include <iostream>
#include "String.h"
#include "DictionaryPair.h"
#include "GenericDictionary.h"
using namespace std;
int main()
{
	GenericDictionary< String, int>  a{};
	cout << "Grocery List";
	cout << "\n======================\n";
	//GenericDictionary <String, int> g{};
	a.addPair("Oranges", 12);
	a.addPair("Apple", 11);
	a.addPair("banana", 13);
	a.addPair("Apricot", 22);
	a.addPair("Apricot", 2);
	//String k = "O";
	//cout<<a.getValue("Oranges");
	a.print();
}