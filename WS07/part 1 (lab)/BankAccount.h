// Alikhan Ongdassyn
// aongdassyn@myseneca.ca
// 158486225
// 03.13.2024

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_BANKACCOUNT_H
#define SENECA_BANKACCOUNT_H
#include "DepositUtility.h"

namespace seneca{
    class BankAccount{
        char m_name[100];
        Date m_openDate;
        DepositInfo m_depInfo;
        double m_balance;
    protected:
        double getBalance() const;
        void setBalance(double newBalance);
        std::ostream& writeCurrency(std::ostream& out, double amount) const;
    public:
        BankAccount(const char* name, const Date& openDate, const DepositInfo& depInfo, double balance);
        std::ostream& write(std::ostream& out) const;
        std::istream& read(std::istream& in); 
    };
    std::istream& operator>>(std::istream& in, BankAccount& account);
    std::ostream& operator<<(std::ostream& out, const BankAccount& account);
}


#endif