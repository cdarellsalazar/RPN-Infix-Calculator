//################################################## 
// File: InfixNotationCalculator.h
// Author: Christian Salazar
// Description: This class contains the function prototypes for the InfixNotationCalculator class
// Date: 10/8/2022
//##################################################

#ifndef INFIXNOTATIONCALCULATOR
#define INFIXNOTATIONCALCULATOR

#include "RPNCalculator.h"

class InfixNotationCalculator : public RPNCalculator
{
public:
	InfixNotationCalculator();

	int checkPrecedence(const string op);
	string infixToPostfix(const string exp);
	double calculateInfix(const string s);
};


#endif