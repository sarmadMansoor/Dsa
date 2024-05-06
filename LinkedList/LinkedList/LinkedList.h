#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include"Node.h"
template<typename T>
class LinkedList
{
	Node<T>* head;

public:
	LinkedList();
	void insertAtHead(T val);
	void insertAtTail(T val);
	void insertBefore(T val, T key);
	void insertAfter(T val, T key);

	void printList();

	void remove(T key);
	void removeAtTail();
	void removeAtHead();
	void removeAfter(T key);
	void removeBefore(T key);
	bool search(T key);
	void reverseList();
	//~LinkedList();


	void deleteAlternate();
	void removeDuplicates();



	


};
#endif // !LINKEDLIST

