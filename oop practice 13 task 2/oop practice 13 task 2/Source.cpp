#include <iostream>
#include "Magazine.h"
#include "Book.h"
#include "Media.h"
#include "Shelf.h"
#include "CD.h"
using namespace std;
void searchByYear(Media** m, int size)
{
	int y;
	cout << "\n\n";
	cout << "\tEnter the year to see all the magazine of that year: ";
	cin >> y;
	bool status = false;
	for (int i = 0; i < size; i++)
	{
		Magazine* p = dynamic_cast<Magazine*>(m[i]);
		if (p)
		{
			if (p->getYear() == y)
			{
				p->display();
				cout << endl;
				status = true;
			}
		}
	}
	if (!status)
	{
		cout << "\n\tThere is no magazine on this year of publication\n";
	}
}
int main()
{
	/*CD a{ "S" };
	a.display();*/

	int n;
	cout << "\tHow many Media Items you wants to create : ";
	cin >> n;
	Shelf p{ n };
	int count = 0;
	
	while (count < n)
	{
		int num;
		cout << "\n\t\tPress 1 to create a Book: \n";
		cout << "\t\tPress 2 to create a Magazine: \n";
		cout << "\t\tPress 3 to create a CD: \n";
		cin >> num;
		if (num == 1)
		{
			cout << "\n";
			String T, A, I;
			cin.ignore();
			cout << "\t\t\tEnter the title of Media: ";
			cin >> T;
			cout << "\t\t\tEnter the name of Author : ";
			cin >> A;
			cout << "\t\t\tEnter the ISBN Number: ";
			cin >> I;
			Media* f = new Book{ T,A,I };
			p.insert(f);

		}
		else if (num == 2)
		{
			cout << "\n";
			cin.ignore();
			String T, M;
			int y;
			cout << "\t\t\tEnter the title of Media: ";
			cin >> T;
			cout << "\t\t\tEnter the Month of publication: ";
			cin >> M;
			cout << "\t\t\tEnter the year of publication: ";
			cin >> y;
			Media* g = new Magazine{ T,M,y };
			p.insert(g);
		}
		else if (num == 3)
		{
			cout << "\n";
			cin.ignore();
			String T;
			int cap;
			cout << "\t\t\tEnter the title of Media: ";
			cin >> T;
			cout << "\t\t\tEnter the capacity of Media: ";
			cin >> cap;

			Media* m = new CD{ T,cap };
			p.insert(m);
		}
		count++;

	}
	cout << "\n\n";
	p.displayContents();
	//searchByYear(p,n);
	//Shelf m{};
	//m = p;
	//cout << "\n\n";
	//m.displayContents();
	
	//searchByYear(p, n);
}