//################################################## 
// File: RPNCalculator.h
// Author: Christian Salazar
// Description: This file contains the function prototypes for the RPNCalculator class
// Date: 10/8/2022
//##################################################

#ifndef RPNCALCULATOR
#define RPNCALCULATOR

#include <string>
#include <vector>
#include "Stack.h"

using std::string;
using std::vector;


class RPNCalculator : public Stack<string>
{
private:

public:
	RPNCalculator();

	double calculatePostfix(const string s);

	string compute(const double num1, const string op, const double num2);
	bool isOperand(const string op);
	bool isOperator(const string op);

	vector<string> *split(const string s);

	bool isTrigFunction(const string op);
	string computeTrig(const string trig, const string degree);
};




#endif