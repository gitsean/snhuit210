#include "SavingsAnnually.h"
#include <iomanip> // std::setprecision
using namespace std;

SavingsAnnually::SavingsAnnually() {}

SavingsAnnually::SavingsAnnually(double t_openingAount, double t_depositedAmount, double t_interestRate, int t_year)
{
    m_openingAount = t_openingAount;
    m_depositedAmount = t_depositedAmount;
    m_interestRate = t_interestRate;
    m_year = t_year;
    calculateSavings();
}

void SavingsAnnually::insertAfter(SavingsAnnually *nodeLoc)
{
    SavingsAnnually *tmpNext = nullptr;

    tmpNext = this->nextNodePtr;    // Remember next
    this->nextNodePtr = nodeLoc;    // this -- node -- ?
    nodeLoc->nextNodePtr = tmpNext; // this -- node -- next
}

SavingsAnnually *SavingsAnnually::getNext()
{
    return this->nextNodePtr;
};

double SavingsAnnually::getClosingAmount()
{
    return m_closingAount;
}
double SavingsAnnually::getInterest()
{
    return m_interest;
}

void SavingsAnnually::calculateSavings()
{
    // ending balance after 1 year
    double rollingAmount = m_openingAount;
    for (int j = 0; j < 12; ++j)
    {
        rollingAmount = rollingAmount + m_depositedAmount;
        m_interest = m_interestRate / 100 / 12 * rollingAmount;
        rollingAmount = rollingAmount + m_interest;
    }
    m_closingAount = rollingAmount;
}

void SavingsAnnually::print()
{
    cout << fixed;
    cout << setprecision(2);
    cout << setw(8) << right << m_year
         << setw(22) << right << m_closingAount
         << setw(27) << right << m_interest << endl;
}