/***
 * The annual savings class is intended for use in a linked list of
 * savings amounts.
*/

#include <string>
#include <iostream>

#ifndef SAVINGSANNUALLY_H
#define SAVINGSANNUALLY_H

class SavingsAnnually
{
public:
    SavingsAnnually();
    SavingsAnnually(double t_openingAount, double t_depositedAmount, double t_interestRate, int t_year);
    void print();
    void insertAfter(SavingsAnnually *nodeLoc);
    double getClosingAmount();
    double getInterest();
    double getTotal();
    void calculateSavings();
    SavingsAnnually *getNext();

private:
    double m_openingAount;
    double m_depositedAmount;
    double m_interest;
    double m_interestRate;
    double m_closingAount;
    int m_year;
    SavingsAnnually *nextNodePtr;
};
#endif // SAVINGSANNUALLY_H