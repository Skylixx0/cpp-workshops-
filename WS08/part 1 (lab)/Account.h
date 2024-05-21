#ifndef SENECA_ACCOUNT_H
#define SENECA_ACCOUNT_H
#include "iAccount.h"

namespace seneca{
    class Account : public iAccount{
        double m_balance;
        protected:
        double balance() const;
        public:
        Account(double amount);
        bool credit(double amount);
        bool debit(double amount);
    };
}


#endif