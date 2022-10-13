//################################################## 
// File: Stack.h
// Author: Christian Salazar
// Description: This contains the function prototypes and code for the Stack class
// Date: 10/8/2022
//##################################################

#ifndef STACK
#define STACK
#include "DoublyLinkedList.h"

template<class T>
class Stack : public DoublyLinkedList<T>
{
protected:
	int mCount = 0;

public:
	Stack();

	void push(T data);
	T pop();
	T peek() const;
};

//#################################################
// @par Name
// - Stack
// @purpose
// - Default constructor
// @param [in]
// - None
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
template<class T>
Stack<T>::Stack()
{

}

//#################################################
// @par Name
// - push
// @purpose
// - Adds T data to the top of the stack (the front of the Doubly Linked List)
// @param [in] : T data
// - Data that will be added to the stack
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
template<class T>
void Stack<T>::push(T data)
{
	this->addToFront(data);
	this->mCount++;
}

//#################################################
// @par Name
// - pop
// @purpose
// - Removes an item from the top of the stack
// @param [in] : 
// - None
// @return
// - T
// @par References
// - None
// @par Notes
// - None
//#################################################
template<class T>
T Stack<T>::pop()
{
	T val = this->peek();
	this->deleteNode(this->mpHead->Data);
	this->mCount--;
	return val;
}

//#################################################
// @par Name
// - peek
// @purpose
// - Returns the value at the top of the stack
// @param [in] :
// - None
// @return
// - T
// @par References
// - None
// @par Notes
// - None
//#################################################
template<class T>
T Stack<T>::peek() const
{
	return this->mpHead->Data;
}

#endif