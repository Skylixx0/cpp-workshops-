#ifndef SENECA_CHEQUINGACCOUNT_H
#define SENECA_CHEQUINGACCOUNT_H
#include "Account.h"

namespace seneca{
    class ChequingAccount : public Account{
        double transactionFee;
        double monthlyFee;
        public:
        ChequingAccount(double balance, double transFee, double monthEndFee);
        bool credit(double amount);
        bool debit(double amount);
        void monthEnd();
        void display(std::ostream& out) const;
    };
}

#endif