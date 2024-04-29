#include <iomanip>

#include <iostream>

#include "savings.h"

using namespace std;

//Parameterized constructor

//Sets values for member variables

savings::savings(double investment, double monthDeposit,

                 double rate, int years) {

    this->initialDeposit = investment;

    this->monthlyDeposit = monthDeposit;

    this->interestRate = rate;

    this->numYears = years;

}

//Destructor

savings::~savings() = default;

//Prints report not considering monthly deposit

void savings::reportNoMonthlyDeposits() const {

//Print heading

    cout << " Balance and Interest without additional Monthly Deposits" << endl;

    cout << "==========================================================================" << endl;

//Print table heading

    cout << setw(10) << "Year"

         << setw(20) << "Year End Balance"

         << setw(35) << "Year End Earned Interest Rate" << endl;

    cout << "--------------------------------------------------------------------------" << endl;

//Iterate for given years and calculate interest earned

    int currentYear = 1;

    double yearEndBalance = this->initialDeposit;

    while (currentYear <= this->numYears) {

//Calculate interest

        double interestEarned = yearEndBalance * this->interestRate / 100;

//Add it to year end Balance

        yearEndBalance += interestEarned;

//Print the results for each year

        cout << right << setw(10) << currentYear << fixed << setprecision(2)

             << setw(20) << "$" << yearEndBalance

             << setw(35) << "$" << interestEarned << endl;

//Increase the year by one

        currentYear++;

    }

}

//Prints report considering monthly deposit

void savings::reportWithMonthlyDeposits() const {

//Print heading

    cout << " Balance and Interest without additional Monthly Deposits" << endl;

    cout << "==========================================================================" << endl;

//Print table heading

    cout << setw(10) << "Year"

         << setw(20) << "Year End Balance"

         << setw(35) << "Year End Earned Interest Rate" << endl;

    cout << "--------------------------------------------------------------------------" << endl;

//Iterate for given years and calculate interest earned

    int currentYear = 1;

    double yearEndBalance = this->initialDeposit;

    while (currentYear <= this->numYears) {

// Calculate interest monthly and find compound interest

        int month = 1;

        double interestEarned = 0.0;

        double monthEndBalance = yearEndBalance;

        while (month <= 12) {

//Add monthly deposit

            monthEndBalance += this->monthlyDeposit;

//Calculate monthly interest, interest rate is for annual. so divide the rate by 12

            double monthlyInterest = monthEndBalance * this->interestRate / (100 * 12);

//Add the monthly interest to yearly interest earned

            interestEarned += monthlyInterest;

// add the interest to month end balance

            monthEndBalance += monthlyInterest;

//Increase the month by 1

            month++;

        }

//After 12 months

        yearEndBalance = monthEndBalance;

//Print the results

        cout << right << setw(10) << currentYear << fixed << setprecision(2)

             << setw(20) << "$" << yearEndBalance

             << setw(35) << "$" << interestEarned << endl;

//Increase the year count by one

        currentYear++;

    }
}