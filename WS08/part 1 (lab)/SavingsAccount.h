#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "Account.h"

namespace seneca{
    class SavingsAccount : public Account{
        double m_interestRate;
        public:
        SavingsAccount(double balance, double amount);
        void monthEnd();
        void display(std::ostream& out) const;
    };
}

#endif