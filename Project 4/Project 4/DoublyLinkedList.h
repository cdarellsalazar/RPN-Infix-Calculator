//################################################## 
// File: DoublyLinkedList.h
// Author: Christian Salazar
// Description: This contains the function prototypes and code for the DoublyLinkedList class
// Date: 10/8/2022
//##################################################

#include <iostream>
#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST

using std::endl;
using std::cout;

template<class T>
struct Node
{
	T Data;
	Node* Next = NULL;
	Node* Prev = NULL;
};

template <class T>
class DoublyLinkedList
{
protected:
	Node<T>* mpHead;
	Node<T>* mpTail;
public:
	DoublyLinkedList();

	void addToFront(T data);
	void addToRear(T data);
	void insertBefore(T target, T data);
	void insertAfter(T target, T data);
	void deleteNode(T target);

	void printList();

	int find(T target) const;

};

//#################################################
// @par Name
// - DoublyLinkedList()
// @purpose
// - Default constructor that sets mpHead and mpTail equal to NULL
// @param [in] :
// - None
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	this->mpHead = NULL;
	this->mpTail = NULL;
}

//#################################################
// @par Name
// - addToFront
// @purpose
// - Adds a Node of type T to the end of the Doubly Linked List
// @param [in] : T data
// - Templated data type that will be added to the front of the list
// @return
// - None
// @par References
// - None
// @par Notes
// - Traverses backwards
//#################################################
template<class T>
void DoublyLinkedList<T>::addToFront(T data)
{

	if (this->mpTail == NULL)
	{
		mpTail = new Node<T>;
		mpTail->Data = data;
		mpTail->Next = NULL;
		mpTail->Prev = NULL;
		mpHead = mpTail;
	}
	else
	{
		Node<T>* p = this->mpTail;

		while (p->Prev != NULL)
		{
			p = p->Prev;
		}
		Node<T>* n = new Node<T>;
		n->Data = data;
		n->Next = NULL;
		n->Prev = NULL;

		p->Prev = n;
		n->Next = p;
		this->mpHead = n;
	}
}

//#################################################
// @par Name
// - addToRear
// @purpose
// - Adds a Node of type T to the end of the Doubly Linked List
// @param [in] : T data
// - Templated data type that will be added to the end of the list
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
template<class T>
void DoublyLinkedList<T>::addToRear(T data)
{
	if (this->mpHead == NULL)
	{
		mpHead = new Node<T>;
		mpHead->Data = data;
		mpHead->Next = NULL;
		mpHead->Prev = NULL;
		mpTail = mpHead;
	}
	else
	{
		Node<T>* p = this->mpHead;

		while (p->Next != NULL)
		{
			p = p->Next;
		}

		Node<T>* n = new Node<T>;
		n->Data = data;
		n->Next = NULL;
		n->Prev = NULL;

		p->Next = n;
		n->Prev = p;

		this->mpTail = n;

	}
}

//#################################################
// @par Name
// - insertAfter
// @purpose
// - Inserts a Node after the target Node in the Doubly Linked List
// @param [in] : T target
// - Templated data type that will be searched for within the Linked List, after which the new Node will be inserted
// @param [in] : T data
// - Templated data type that will be added after T target is found
// @return
// - 
// @par References
// - None
// @par Notes
// - None
//#################################################
template<class T>
void DoublyLinkedList<T>::insertAfter(T target, T data)
{
	// originally: p <-> q
	// after: p <-> n <-> q
	if (this->find(target) != -1) // returns -1 if not found;
	{
		Node<T>* p = this->mpHead;

		while (p->Data != target)
		{
			p = p->Next;
		}
		// IF INSERTING BEFORE THE TAIL, ADD CODE TO ASSIGN TAIL POINTER TO NEW INSERTED NODE
		Node<T>* n = new Node<T>;
		n->Data = data; // sets new Node's data (n) to argument

		if (p->Next == NULL)
		{
			p->Next = n;
			n->Prev = p;
			n->Next = NULL;
			this->mpTail = n;
		}
		else
		{
			n->Next = p->Next; // now n and p are both pointing to q
			p->Next->Prev = n; // makes the node after our next node we are inserting (q) point backwards to the new node

			p->Next = n; // makes p point forwards to n
			n->Prev = p; // makes n point backwards to p;
		}
	}
}

//#################################################
// @par Name
// - insertBefore
// @purpose
// - Inserts a Node before the Target Node in the Doubly Linked List
// @param [in] : T target
// - Templated data type that will be searched for within the Linked List, before which the new Node will be inserted
// @param [in] : T data
// - Templated data type that will be added before T target is found
// @return
// - None
// @par References
// - None
// @par Notes
// - Traverses backwards
//#################################################
template<class T>
void DoublyLinkedList<T>::insertBefore(T target, T data)
{
	if (this->find(target) != -1)
	{
		Node<T>* p = this->mpTail;

		while (p->Data != target)
		{
			p = p->Prev; // we're traversing backwards
		}

		Node<T>* n = new Node<T>;
		n->Data = data;

		if (p->Prev == NULL)
		{
			p->Prev = n;
			n->Next = p;
			n->Prev = NULL;
			this->mpHead = n;
		}
		else
		{
			n->Prev = p->Prev;
			p->Prev->Next = n;

			p->Prev = n;
			n->Next = p;
		}
	}
}

//#################################################
// @par Name
// - deleteNode
// @purpose
// - Function that will delete the specified Node from the Doubly Linked List
// @param [in] : T target
// - Data that will be searched for and deleted within the Doubly Linked List
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
template<class T>
void DoublyLinkedList<T>::deleteNode(T target)
{
	Node<T>* p;
	if (this->mpHead != NULL)
	{
		p = this->mpHead;
	}
	else
	{
		return;
	}


	if (this->find(target) != -1)// && p != NULL)
	{
		if (p->Next == NULL && p->Prev == NULL) // if list has one element
		{
			delete p;
			this->mpHead = NULL;
			this->mpTail = NULL;
		}
 		else if (p->Data == target && p->Next != NULL) // if the Node to delete is at the beginning of the list
		{ 
			Node<T>* delPtr = p;
			this->mpHead = p->Next;
			this->mpHead->Prev = NULL;

			delete delPtr;
		}
		else if (this->mpTail->Data == target) // if the Node to delete is at the end of the list
		{
			p = this->mpTail;
			Node<T>* delPtr = p;
			this->mpTail = p->Prev;
			p->Prev->Next = NULL;

			delete delPtr;
		}
		else
		{
			if (p->Next != NULL)
			{
				while (p->Next->Data != target) // iterate through the list
				{
					p = p->Next;
				}

				Node<T>* delPtr = p->Next;
				delPtr->Next->Prev = p; // equivalent to p->Next->Next->Prev = p;
				p->Next = p->Next->Next;

				delete delPtr;
			}
		}
	}
}

//#################################################
// @par Name
// - find
// @purpose
// - Checks the Linked List to see if the argument is contained and returns the index of the element; returns -1 if not found
// @param [in] : T target
// - Value that will be searched for within the Linked List
// @return
// - int
// @par References
// - None
// @par Notes
// - None
//#################################################
template<class T>
int DoublyLinkedList<T>::find(T target) const
{
	Node<T>* p = this->mpHead;
	int count = 0;

	while (p != NULL)
	{
		if (p->Data == target)
		{
			return count;
		}
		else
		{
			p = p->Next;
			count++;
		}
	}
	return -1;
}

//#################################################
// @par Name
// - printList
// @purpose
// - Iterates through the Doubly Linked LIst and prints out all of the values
// @param [in] :
// - None
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
template<class T>
void DoublyLinkedList<T>::printList()
{
	Node<T>* p = this->mpHead;

	cout << "Now printing list: " << endl;
	cout << "--------------------------" << endl;

	while (p != NULL)
	{
		cout << p->Data.c_str() << endl;
		cout << "--------------------------" << endl;
		p = p->Next;
	}
}

#endif