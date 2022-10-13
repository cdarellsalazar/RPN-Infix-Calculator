//################################################## 
// File: main.cpp
// Author: Christian Salazar
// Description: This is where all of the classes for this project are tested.
// Date: 10/8/2022
//##################################################

#include <iostream>

#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "RPNCalculator.h"
#include "InfixNotationCalculator.h"

using namespace std;

int main()
{
	// This tests the Doubly Linked List class: 
	DoublyLinkedList<string> ll;

	ll.addToFront("pain");
	ll.addToFront("sadness");

	ll.printList();

	ll.insertAfter("pain", "joy");

	cout << endl;

	ll.printList();

	ll.insertBefore("sadness", "happiness");

	cout << endl;
	ll.printList();

	cout << "happiness is located at index 0: " << ll.find("happiness") << endl;
	cout << "sadness is located at index 1: " << ll.find("sadness") << endl;
	cout << "pain is located at index 2: " << ll.find("pain") << endl;
	cout << "joy is located at index 3: " << ll.find("joy") << endl;
	cout << endl;
	cout << "This should print -1: " << ll.find("UCLA") << endl;


	ll.deleteNode("happiness");
	cout << endl;

	ll.printList();
	
	ll.deleteNode("pain");
	cout << endl;
	ll.printList();

	ll.deleteNode("joy");

	cout << endl;
	ll.printList();
	cout << endl;

	// This tests the Stack class
	Stack<string> st;

	st.push("1");
	st.push("2");
	st.push("3");
	st.push("4");

	st.printList();
	cout << endl;

	st.pop();
	st.printList();

	cout << "this should print 3: " << st.peek() << endl;

	// This tests the Queue class
	Queue<string> q;

	q.enqueue("1");
	q.enqueue("2");
	q.enqueue("3");
	q.enqueue("4");

	q.printList();

	q.dequeue();

	cout << endl;
	q.printList();

	// This tests the RPN Calculator class
	RPNCalculator r;

	string test = "20 10 / 6.3 2 * +";


	cout << "This should print out 8: " << r.calculatePostfix("2 3 ^") << endl;
	cout << "This should print 14.6: " << r.calculatePostfix(test) << endl;
	cout << "This should print 90.91: " << r.calculatePostfix("200 2.2 /") << endl;
	cout << "This should print 14: " << r.calculatePostfix("2 3 4 * +") << endl;
	cout << "This should print 13: " << r.calculatePostfix("3            2     5             *     +") << endl;
	cout << "This should print 2: " << r.calculatePostfix("2 5 * 4 + 3 2 * 1 + / ") << endl;
	cout << "This should print -5: " << r.calculatePostfix("3 2 * 11 -") << endl;
	cout << "This should print -117: " << r.calculatePostfix("3 -2 * 111 -") << endl;

	// This tests the InfixNotationCalculator class
	InfixNotationCalculator t;

	cout << endl;
	cout << "should print: A B * C +: " << t.infixToPostfix("A * B + C") << endl;
	cout << "should print: A B C * +: " << t.infixToPostfix("A + B * C") << endl;
	cout << "should print: A B C + *: " << t.infixToPostfix("A * (B + C)") << endl;
	cout << "should print: A B - C +: " << t.infixToPostfix("A - B + C") << endl;
	cout << "should print: A B C ^ * D +: " << t.infixToPostfix("A * B ^ C + D") << endl;
	cout << "should print: A B C D * + * E +: " << t.infixToPostfix("A * (B + C * D) + E") << endl;

	cout << endl;

	cout << "Complicated RPN Expression: K + L - M * N + (O ^ P) * W / U / V * T + Q" << endl;
	cout << "Should print: " << "K L + M N * - O P ^ W * U / V / T * + Q + " << endl;
	cout << "	      " << t.infixToPostfix("K + L - M * N + (O ^ P) * W / U / V * T + Q") << endl;

	cout << endl;
	cout << "This should print 13: " << t.calculateInfix("3 + 2 * 5") << endl;
	cout << "This should print 14: " << t.calculateInfix("(3 - 1) + (3 * 4)") << endl;

	cout << "EXTRA CREDIT: Now calculating 3 * 2 + sin(45)" << endl;
	cout << "This should print: 6.707: " << t.calculateInfix("3 * 2 + sin(45)") << endl;
	cout << "EXTRA CREDIT: Now calculating cos(0) * 3 + 2 / 5" << endl;
	cout << "This should print: 3.4: " << t.calculateInfix("cos(0) * 3 + 2 / 5") << endl;
	cout << "EXTRA CREDIT: Now calculating tan(271) + 32 * (8 + 2)" << endl;
	//cout << "This should print: 262.71: " << t.calculateInfix("tan(271) + 32 * (8 + 2)") << endl;


	return 0;
 }