#include"LinkedList.h"
#include<iostream>
using namespace std;
template<typename T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
}
template<typename T>
void LinkedList<T>::insertAtHead(T val)
{
	Node<T>* p = new Node<T>(val);
	p->next = head;
	head = p;
}
template<typename T>
void LinkedList<T>::insertAtTail(T val)
{
	if (!head)
	{
		head = new Node<T>(val);
		return;
	}
	Node<T>* p = head;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	p->next = new Node<T>(val);
}
template<typename T>
void LinkedList<T>::insertBefore(T val, T key)
{
	if (!head)
		return;
	if (head->info == key)
	{
		Node<T>* p = new Node<T>(val);
		p->next = head;
		head = p;
		return;
	}
	Node<T>* p = head;
	while (p->next != nullptr && p->next->info != key)
	{
		p = p->next;
	}
	if (p->next != nullptr)
	{
		Node<T>* x = new Node<T>(val);
		x->next = p->next;
		p->next = x;
	}
}
template<typename T>
void LinkedList<T>::insertAfter(T val, T key)
{
	if (!head)
		return;
	Node<T>* p = head;
	if (p->info == key)
	{
		Node<T>* x = new Node<T>(val);
		x->next = head->next;
		head->next = x;
		return;
	}
	bool status = false;
	while (p->next != nullptr && p->info != key)
	{
		p = p->next;
		if (p->info == key)
			status = true;
	}
	if (status)
	{
		Node<T>* x = new Node<T>(val);
		x->next = p->next;
		p->next = x;
	}

}
template<typename T>
void LinkedList<T>::printList()
{
	if (!head)
		return;
	Node<T>* p = head;
	while (p!= nullptr)
	{
		cout << p->info << ", ";
		p = p->next;
	}
}
template<typename T>
void LinkedList<T>::remove(T key)
{
	if (!head)
		return;
	Node<T>* p = head;
	if (p->info == key)
	{
		p = p->next;
		delete head;
		head = p;
		return;
	}
	while (p->next != nullptr && p->next->info != key)
		p = p->next;
	if (p->next == nullptr)
		return;
	if (p->next->next)
	{
		Node<T>* del = p->next;
		p->next = p->next->next;
		delete del;
	}
	else if (p->next->next == nullptr)
	{
		delete p->next;
		p->next = nullptr;
	}
}
template<typename T>
void LinkedList<T>::removeAtHead()
{
	if (!head)return;
	Node<T>* temp = head;
	head = head->next;
	delete temp;
}
template<typename T>
void LinkedList<T>::removeAtTail()
{
	if (!head)
		return;
	Node<T>* p = head;
	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}
	while (p->next->next != nullptr)
		p = p->next;
	delete p->next;
	p->next = nullptr;
}
template<typename T>
void LinkedList<T>::removeAfter(T key)
{
	if (!head || !head->next)
		return;
	Node<T>* p = head;
	while (p->next && p->info != key)
	{
		p = p->next;
	}
	if (!p->next)
		return;
	if (p->next->next)
	{
		Node<T>* del = p->next;
		p->next = p->next->next;
		delete del;
	}
	else if (!p->next->next)
	{
		delete p->next;
		p->next = nullptr;
	}
}
template<typename T>
void LinkedList<T>::removeBefore(T key)
{
	if (!head || head->info == key)
		return;
	Node<T>* p = head;
	if (p->next->info == key)
	{
		Node<T>* del = p;
		p = p->next;
		delete del;
		head = p;
		return;
	}
	bool status = false;
	Node<T>* prev = head;
	Node<T>* curr = head->next->next;
	if (curr->info == key)
		status = true;
	while (curr->next && curr->info != key)
	{
		curr = curr->next;
		prev = prev->next;
		if (curr->info == key)
			status = true;
	}
	if (status)
	{
		Node<T>* del = prev->next;
		prev->next = curr;
		delete del;
	}
}
template<typename T>
bool LinkedList<T>::search(T key)
{
	Node<T>* p = head;
	while (!p)
	{
		if (p->info == key)
			return true;
		p = p->next;
	}
	return false;
}
template<typename T>
void LinkedList<T>::deleteAlternate()
{
	if (head == nullptr || head->next == nullptr) 
	{
		return;
	}
	Node<T>* p = head;
	while (p != nullptr && p->next != nullptr)
	{
		Node<T>* temp = p->next;           
		p->next = p->next->next;    
		delete temp;                       
		p = p->next;                 
	}
}
template<typename T>
void LinkedList<T>::removeDuplicates()
{
	if (!head || !head->next)
		return;
	Node<T>* current = head;
	while (current)
	{
		Node<T>* prev = current;
		Node<T>* checker = prev->next;
		while (checker)
		{
			if (checker->info == current->info)
			{
				prev->next = checker->next;
				delete checker;
				checker = prev->next;
			}
			else
			{

				prev = prev->next;
				checker = checker->next;
			}
		}
		current = current->next;
	}
}
template<typename T>
void LinkedList<T>::reverseList()
{
	Node<T>* prev = nullptr;    
	Node<T>* curr = head;       
	Node<T>* next = nullptr;   

	while (curr != nullptr) 
	{
		next = curr->next;      
		curr->next = prev;     
		prev = curr;          
		curr = next;
	}
	head = prev;            
}




//template<typename T>
//Node<T>* swapPairs(Node<T>* head) {
//	if (head == nullptr || head->next == nullptr)
//		return head;
//
//	// Dummy node to simplify edge cases
//	Node<T>* dummy = new Node<T>();
//	dummy->next = head;
//
//	Node<T>* prev = dummy;
//	Node<T>* first = head;
//	Node<T>* second = head->next;
//
//	while (second != nullptr) {
//		// Swapping
//		prev->next = second;
//		first->next = second->next;
//		second->next = first;
//
//		// Move to the next pair
//		prev = first;
//		first = first->next;
//
//		if (first != nullptr)
//			second = first->next;
//		else
//			second = nullptr;
//	}
//
//	head = dummy->next;
//	delete dummy;
//	return head;
//}





//template<typename T>
//void LinkedList<T>::reorderList() {
//    if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
//        return;
//
//    // Step 1: Find the middle of the linked list
//    Node<T>* slow = head;
//    Node<T>* fast = head->next;
//
//    while (fast != nullptr && fast->next != nullptr) {
//        slow = slow->next;
//        fast = fast->next->next;
//    }
//
//    // Step 2: Reverse the second half of the linked list
//    Node<T>* prev = nullptr;
//    Node<T>* curr = slow->next;
//    Node<T>* temp;
//
//    while (curr != nullptr) {
//        temp = curr->next;
//        curr->next = prev;
//        prev = curr;
//        curr = temp;
//    }
//    slow->next = nullptr; // Break the link between the first and second half
//
//    // Step 3: Merge the first half and the reversed second half alternately
//    Node<T>* firstHalf = head;
//    Node<T>* secondHalf = prev;
//    Node<T>* next1;
//    Node<T>* next2;
//
//    while (firstHalf != nullptr && secondHalf != nullptr) {
//        next1 = firstHalf->next;
//        next2 = secondHalf->next;
//
//        firstHalf->next = secondHalf;
//        secondHalf->next = next1;
//
//        firstHalf = next1;
//        secondHalf = next2;
//    }
//}




//template<typename T>
//Node<T>* reverseKGroup(Node<T>* head, int k) {
//	if (head == nullptr || k == 1)
//		return head;
//
//	int count = 0;
//	Node<T>* dummy = new Node<T>();
//	dummy->next = head;
//	Node<T>* prev = dummy;
//	Node<T>* curr = head;
//
//	// Count the total number of nodes in the list
//	while (curr != nullptr) {
//		count++;
//		curr = curr->next;
//	}
//
//	// Reverse nodes in groups of k
//	while (count >= k) {
//		curr = prev->next;
//		for (int i = 1; i < k; i++) {
//			Node<T>* nextNode = curr->next;
//			curr->next = nextNode->next;
//			nextNode->next = prev->next;
//			prev->next = nextNode;
//		}
//		prev = curr;
//		count -= k;
//	}
//
//	head = dummy->next;
//	delete dummy;
//	return head;
//}
