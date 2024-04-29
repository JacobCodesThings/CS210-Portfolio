#ifndef SAVINGS_H_

#define SAVINGS_H_

class savings {

public:

    savings(double investment, double monthDeposit, double rate, int years);

    virtual ~savings();

    void reportNoMonthlyDeposits() const;

    void reportWithMonthlyDeposits() const;

private:

    double initialDeposit;

    double monthlyDeposit;

    double interestRate;

    int numYears;

};

#endif