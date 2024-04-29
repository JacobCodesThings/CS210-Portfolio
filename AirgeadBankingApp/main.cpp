#include <iostream>

#include "savings.h"

using namespace std;

int main()

{

    while (true)

    {

//Print heading

        cout << "*************************************" << endl;

        cout << "*************Data Input**************" << endl;

        cout << "Initial Investment Amount: " << endl;

        cout << "Monthly Deposit: " << endl;

        cout << "Annual Interest: " << endl;

        cout << "Number of years: " << endl;

//system("PAUSE");



        cout << endl;

//Get the inputs from user

        cout << "*************************************" << endl;

        cout << "*************Data Input**************" << endl;

        cout << "Initial Investment Amount: $";

        double investment, monthDeposit, interestRate;

        int years;

        cin >> investment;

        cout << "Monthly Deposit: $";

        cin >> monthDeposit;

        cout << "Annual Interest: %";

        cin >> interestRate;

        cout << "Number of years: ";

        cin >> years;

//system("PAUSE");


//Create savings object using the given inputs

        savings mySavings = savings(investment, monthDeposit, interestRate, years);

        cout << endl;

//Invoke the report methods

        mySavings.reportNoMonthlyDeposits();

        cout << endl;

// call monthly deposit report, if it has monthly deposit of at least $1

        if (monthDeposit > 0) {

            mySavings.reportWithMonthlyDeposits();

        }

//Get the user choice if they want to try another

        cout << endl << "Do you want to try another? (y/n): ";

        string choice;

        cin >> choice;

//If user does not want to try another, break the loop

        if (choice != "y") {

            break;

        }

        cout << endl;

    }

    return 0;

}