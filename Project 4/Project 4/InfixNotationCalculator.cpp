//################################################## 
// File: InfixNotationCalculator.cpp
// Author: Christian Salazar
// Description: This contains the code for the functions in the InfixNotationCalculator class
// Date: 10/8/2022
//##################################################

#include "InfixNotationCalculator.h"

//#################################################
// @par Name
// - InfixNotationCalculator
// @purpose
// - Default Constructor
// @param [in] :
// - None
// @return
// - None
// @par References
// - None
// @par Notes
// - None
//#################################################
InfixNotationCalculator::InfixNotationCalculator()
{

}

//#################################################
// @par Name
// - checkPrecedence
// @purpose
// - Determines the 
// @param [in] : const string op
// - String that determines the operator precedence
// @return
// - int
// @par References
// - None
// @par Notes
// - None
//#################################################
int InfixNotationCalculator::checkPrecedence(const string op)
{
	if (op == "+" || op == "-")
	{
		return 1;
	}
	if (op == "*" || op == "/" || op == "%")
	{
		return 2;
	}
	if (op == "^")
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

//#################################################
// @par Name
// - infixToPostfix
// @purpose
// - Converts the Infix expression to postfix expression
// @param [in] : const string exp
// - Infix expression that will be converted to postfix 
// @return
// - string
// @par References
// - None
// @par Notes
// - None
//#################################################
string InfixNotationCalculator::infixToPostfix(const string exp)
{
	string rpn;
	vector<string>* tokens = this->split(exp);

	for (int i = 0; i < tokens->size(); i++)
	{
		string token = tokens->at(i);

		if (this->isTrigFunction(token))
		{
			string rad = tokens->at(i + 2);
			rpn += this->computeTrig(token, rad) + " ";
			i += 3;
		}
		else if (this->isOperand(token))
		{
			rpn += token + " ";
		}
		else if (token == "(")
		{
			this->push(token);
		}
		else if (token == ")")
		{
			string topToken = this->pop();

			while (topToken != "(")
			{
				rpn += topToken + " ";
				topToken = this->pop();
			}
		}
		else
		{
			while (this->mCount > 0 && this->checkPrecedence(this->peek()) >= this->checkPrecedence(token))
			{
				rpn += this->pop() + " ";
			}
			this->push(token);
		}
	}
	while (this->mCount > 0)
	{
		rpn += this->pop() + " ";
	}
	
	return rpn;
}

//#################################################
// @par Name
// - calculateInfix
// @purpose
// - Calculates the numerical value of the Infix expression
// @param [in] :
// - const string s
// @return
// - double
// @par References
// - None
// @par Notes
// - Please note: to calculate RPN Expression, use the calculatePostfix function.
//#################################################
double InfixNotationCalculator::calculateInfix(const string s)
{
	string rpn = this->infixToPostfix(s);
	return this->calculatePostfix(rpn);
}
