/***
 * Shows the user a comparison of how much they will save year over year,
 * provided an initial investment amount, number of years, monthly deposit amount, 
 * and interest rate.
 * 
 * Author: Sean Reid
 * Date: 7/1/2021
 * 
*/

#include "SavingsHelpers.cpp"
#include <iostream>
#include <string>
using namespace std;
int main()
{
    double initialInvestment, monthlyDeposit, annualInterest;
    int numYears;

    getInput(initialInvestment, monthlyDeposit, annualInterest, numYears);

    cout << "Balance and Interest without  Additional Monthly Deposits" << endl;
    produceOutput(initialInvestment, 0, annualInterest, numYears);

    cout << endl;

    cout << "Balance and Interest with  Additional Monthly Deposits" << endl;
    produceOutput(initialInvestment, monthlyDeposit, annualInterest, numYears);

    return 0;
}