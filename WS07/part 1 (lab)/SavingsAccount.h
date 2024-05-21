// Alikhan Ongdassyn
// aongdassyn@myseneca.ca
// 158486225
// 03.13.2024

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_SAVINGSACCOUNT_H
#define SENECA_SAVINGSACCOUNT_H
#include "BankAccount.h" 
#include "DepositUtility.h"

namespace seneca{
    class SavingsAccount : protected BankAccount{
        double m_interest;
        Date m_interestDate;
        std::ostream& writeinterest(std::ostream& out) const;
    public:
        SavingsAccount(const char* name, Date& openDate, DepositInfo& depInfo, double balance, double insterest, Date& interestDate);
        void applyInterest(const Date& today);
        std::ostream& write(std::ostream& out) const;
        std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& out, const SavingsAccount& account);
    std::istream& operator>>(std::istream& in, SavingsAccount& account);
}

#endif