#include<iostream>
#include"LinkedList.h"
using namespace std;

int main()
{
	LinkedList<int> l;
	l.insertAtHead(1);
	l.insertAtHead(2);
	l.insertAtHead(3);
	l.insertAtHead(4);
	l.reverseList();
	/*l.insertAtHead(4);
	l.insertAtHead(1);
	l.insertAtHead(4);
	l.insertAtHead(1);
	l.insertAtHead(1);
	l.insertAtHead(2);*/

	
	//l.insertAtHead(5);
//	l.insertAtHead(6);
	//l.insertAtHead(7);
	//l.insertAfter(6, 4);
	//l.insertBefore(9,4);
	//l.remove(5);
	//l.removeAtTail();
	//l.removeAfter(5);
	//l.removeBefore(5);
	//l.deleteAlternate();
	//l.removeDuplicates();
	l.printList();


	return 0;
}