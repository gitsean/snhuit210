/***
 * Helper functions used by savings.cpp
*/

#include <iostream>
#include <string>
#include "SavingsAnnually.cpp"
#include "SavingsAnnually.h"
using namespace std;

void getInput(double &initialInvestment, double &monthlyDeposit, double &annualInterest, int &numYears)
{
    cout << "Initial Investment Amount:" << endl;
    cin >> initialInvestment;

    cout << "Monthly Deposit:" << endl;
    cin >> monthlyDeposit;

    cout << "Annual Interest:" << endl;
    cin >> annualInterest;

    cout << "Number of years:" << endl;
    cin >> numYears;

    cout << endl;
}

void produceOutput(double initialInvestment, double monthlyDeposit, double annualInterest, int numYears)
{
    SavingsAnnually *headObj = nullptr; // Create intNode objects
    SavingsAnnually *currObj = nullptr;
    SavingsAnnually *lastObj = nullptr;

    headObj = new SavingsAnnually(); // Front of nodes list
    lastObj = headObj;
    double rollingAmount = initialInvestment;

    for (int i = 0; i < numYears; ++i)
    {
        currObj = new SavingsAnnually(rollingAmount, monthlyDeposit, annualInterest, i + 1);
        rollingAmount = currObj->getClosingAmount();
        lastObj->insertAfter(currObj); // Append curr
        lastObj = currObj;             // Curr is the new last item
    }

    currObj = headObj; // Print the list
    currObj = currObj->getNext();

    // Header for displayed content
    cout << "---------------------------------------------------------" << endl;
    cout << setw(8) << right << "Year"
         << setw(22) << right << "Year End Balance"
         << setw(27) << right << "Year End Earned Interest" << endl;
    cout << "=========================================================" << endl;

    while (currObj != nullptr) // Displaying each year
    {
        currObj->print();
        currObj = currObj->getNext();
        cout << endl;
    }
}
