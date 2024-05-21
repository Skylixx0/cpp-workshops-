// Alikhan Ongdassyn
// aongdassyn@myseneca.ca
// 158486225
// 03.13.2024

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cstring>
#include "SavingsAccount.h"
using namespace std;

namespace seneca{
    std::ostream& SavingsAccount::writeinterest(std::ostream& out) const{
        out.precision(3);
        out.setf(ios::fixed);
        out << this->m_interest << '%';
        out.unsetf(ios::fixed);
        out.precision(6);
        return out;
    };

    SavingsAccount::SavingsAccount(const char* name, Date& openDate, DepositInfo& depInfo, double balance, double interest, Date& interestDate) : BankAccount(name, openDate, depInfo, balance){
        m_interest = interest;
        m_interestDate = interestDate;
    };

    void SavingsAccount::applyInterest(const Date& today){
        double oldBalance = getBalance();
        double interestAmount = m_interest * oldBalance;
        double newBalance = oldBalance + interestAmount;

        setBalance(newBalance);
        cout << "   ";
        writeCurrency(cout, oldBalance);
        cout << " + ";
        writeCurrency(cout, interestAmount);
        cout <<  " (";
        writeinterest(cout); 
        cout << ')' << " = ";
        writeCurrency(cout, newBalance);
        cout << " | ";
        m_interestDate.write(cout);
        cout << " => ";
        m_interestDate = today; // ???????
        today.write(cout);
        cout << endl;
    };    

    std::ostream& SavingsAccount::write(std::ostream& out) const{
        BankAccount::write(out);
        cout << " | ";
        writeinterest(out);
        cout << " | ";
        m_interestDate.write(out);
        return out;
    };

    std::istream& SavingsAccount::read(std::istream& in){
        BankAccount::read(in);
        cout << "Interest Date ";
        in >> m_interestDate;
        cout << "Interest Rate: ";
        in >> m_interest;
        return in;
    };

    std::ostream& operator<<(std::ostream& out, const SavingsAccount& account){
        account.write(out);
        return out;
    };

    std::istream& operator>>(std::istream& in, SavingsAccount& account){
        account.read(in);
        return in; 
    };
}