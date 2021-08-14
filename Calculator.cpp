/*
 * Calculator.cpp
 * 
 * This program will accept a mathematical expression and print the result to the console.
 * Program will run as long as the user enters 'Y' to evaluate another expression.
 *
 *  Date: 07/07/2021
 *  Author: Sean Reid
 */

#include <iostream>

using namespace std;

int main()
{
	char statement[100];
	int op1, op2;
	char operation;
	char answer = 'Y';					   // Proper white spacing, semi-colon, double quotes to single
	while (answer == 'Y' || answer == 'y') // Capital Y or lower
	{
		cout << "Enter expression" << endl;
		cin >> op1 >> operation >> op2;								   // Correct order of collected expression
		if (operation == '+')										   // remove semi-colon, double quotes to single
			cout << op1 << " + " << op2 << " = " << op1 + op2 << endl; // point in proper direction
		if (operation == '-')										   // remove semi-colon
			cout << op1 << " - " << op2 << " = " << op1 - op2 << endl; // point in proper direction
		if (operation == '*')
			cout << op1 << " * " << op2 << " = " << op1 * op2 << endl; // Show proper operator
		if (operation == '/')
			cout << op1 << " / " << op2 << " = " << op1 / op2 << endl; // Show proper operator

		cout << "Do you wish to evaluate another expression? " << endl;
		cin >> answer;
	}

	return 0;
}
