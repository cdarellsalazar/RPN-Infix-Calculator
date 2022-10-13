//################################################## 
// File: Queue.h
// Author: Christian Salazar
// Description: This file contains the function prototypes and code for the Queue class
// Date: 10/8/2022
//##################################################

#ifndef QUEUE
#define QUEUE

#include "DoublyLinkedList.h"

template<class T>
class Queue : public DoublyLinkedList<T>
{
private:

public:
	Queue();

	void enqueue(T data);
	T dequeue();
	T peek() const;
};

//#################################################
// @par Name
// - Queue
// @purpose
// - Default constructor
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
Queue<T>::Queue()
{

}

//#################################################
// @par Name
// - enqueue
// @purpose
// - Adds a Node to the back of the Queue (or the rear of the Doubly Linked List)
// @param [in] : T data
// - Data that gets enqueued to the back of the queue
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
template<class T>
void Queue<T>::enqueue(T data)
{
	this->addToRear(data);
}

//#################################################
// @par Name
// - dequeue
// @purpose
// - Removes the Node at the front of the queue
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
T Queue<T>::dequeue()
{
	T val = this->peek();
	this->deleteNode(this->peek());
	return val;
}

//#################################################
// @par Name
// - peek
// @purpose
// - Returns the value at the front of the queue
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
T Queue<T>::peek() const
{
	return this->mpHead->Data;
}




#endif