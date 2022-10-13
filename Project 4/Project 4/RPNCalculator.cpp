//################################################## 
// File: RPNCalculator.cpp
// Author: Christian Salazar
// Description: Contains the code for the functions in the RPNCalculator class
// Date: 10/8/2022
//##################################################

#include "RPNCalculator.h"
#include <string>
#include <math.h>
#include <ctime>
#include <sstream>
#include <iterator>

using namespace std;

//#################################################
// @par Name
// - RPNCalculator()
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
RPNCalculator::RPNCalculator()
{

}

//#################################################
// @par Name
// - calculatePostfix
// @purpose
// - Calculates and returns the solution to the RPN Expression
// @param [in] :
// - const string s
// @return
// - double
// @par References
// - None
// @par Notes
// - This is the algorithm to calculate the solution; the actual compututations are in the compute function
//#################################################
double RPNCalculator::calculatePostfix(const string s)
{
	// 3 2 * 11 -
	vector<string>* exp;
	exp = this->split(s);
	
	for (int i = 0; i < exp->size(); i++)
	{
		string tmp = exp->at(i);

		if (this->isTrigFunction(tmp))
		{
			this->push(this->computeTrig(tmp, exp->at(i + 2)));
			i++;
		}

		else if (this->isOperand(tmp))
		{
			this->push(tmp);
		}
		else if (this->isOperator(tmp))
		{
			string sNum1 = this->pop();
			string sNum2 = this->pop();

			double num1 = stod(sNum1);
			double num2 = stod(sNum2);

			this->push(this->compute(num1, tmp, num2));
		}
	}

	if (this->mCount == 1)
	{
		return stod(this->pop());
	}
	else
	{
		return 0;
	}
}

//#################################################
// @par Name
// - isOperator
// @purpose
// - Determines whether or not the argument is an operator
// @param [in] : const string op
// - This is what the function evaluates
// @return
// - bool
// @par References
// - None
// @par Notes
// - None
//#################################################
bool RPNCalculator::isOperator(const string op)
{
	return (op == "+" || op == "-" || op == "/" || op == "*" || op == "^" || op == "(" || op == ")");
}

//#################################################
// @par Name
// - isOperand
// @purpose
// - Determines whether the argument is an operand
// @param [in] : const string op
// - This is what the function evaluates
// @return
// - bool
// @par References
// - None
// @par Notes
// - None
//#################################################
bool RPNCalculator::isOperand(const string op)
{
	return (!this->isOperator(op) && op != " " && !op[0] == '\0');
}

//#################################################
// @par Name
// - compute
// @purpose
// - Computes the solution of the two operands with the operator
// @param [in] : const double num1
// - First number that is used in the computation
// @param [in] : const string op
// - Operator that is used in the computation
// @param [in] : const double num2
// - Second number that is used in the computation
// @return
// - string
// @par References
// - None
// @par Notes
// - None
//#################################################
string RPNCalculator::compute(const double num1, const string op, const double num2)
{
	char oper = op[0];
	double solution = 0;
	switch (oper)
	{
	case '+':
	{
		solution = num1 + num2;
		break;
	}
	case '-':
	{
		solution = num2 - num1;
		break;
	}
	case '*':
	{
		solution = num1 * num2;
		break;
	}
	case '/':
	{
		solution = num2 / num1;
		break;
	}
	case '^':
	{
		solution = pow(num2, num1);
		break;
	}
	}
	string s = to_string(solution);
	return s;
}

//#################################################
// @par Name
// - split
// @purpose
// - Splits the string at the spaces
// @param [in] : const string s
// - String that gets split
// @return
// - vector<string>*
// @par References
// - None
// @par Notes
// - None
//#################################################
vector<string>* RPNCalculator::split(const string s)
{
	string tmp = s;

	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == '(')
		{
			tmp.insert(i + 1, " "); // these two lines are to separate trig functions
			tmp.insert(i, " ");
			i++;
			
		}
		else if (tmp[i] == ')')
		{
			tmp.insert(i, " ");
			i++;
		} 
	}

	istringstream istr(tmp);
	vector<string>* tokens = new vector<string>(istream_iterator<string>{istr}, istream_iterator<string>());

	return tokens;
}

//#################################################
// @par Name
// - isTrigFunction
// @purpose
// - Determines whether the argument is a trig function
// @param [in] :
// - const string op
// @return
// - bool
// @par References
// - None
// @par Notes
// - None
//#################################################
bool RPNCalculator::isTrigFunction(const string op)
{
	return (op == "sin" || op == "cos" || op == "tan");
}

//#################################################
// @par Name
// - computeTrig
// @purpose
// - Computes the numerical value of trig functions
// @param [in] : const string trig
// - Trig function that gets evaluated
// @param [in] : const string degree
// - Degree value that each trig function is evaluated at
// @return
// - string
// @par References
// - None
// @par Notes
// - None
//#################################################
string RPNCalculator::computeTrig(const string trig, const string degree)
{
	double solu = 0;
	double radian = stoi(degree) * atan(1)*4 / 180; // atan(1) is pi

	if (trig == "sin")
	{
		solu = sin(radian);
	}
	else if (trig == "cos")
	{
		solu = cos(radian);
	}
	else if (trig == "tan")
	{
		solu = tan(radian);
	}

	string s = to_string(solu);

	return s;
}