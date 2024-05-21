#include <iostream>
#include "SavingsAccount.h"

using namespace std;
namespace seneca{
    SavingsAccount::SavingsAccount(double balance, double interestRate) : Account(balance){
        if(!interestRate || interestRate < 0) m_interestRate = 0.0;
        else {
            m_interestRate = interestRate;
        } 
    };

    void SavingsAccount::monthEnd(){
        double interestBalance = 0.0;
        interestBalance = this->Account::balance() * m_interestRate;
        Account::credit(interestBalance);
    };

    void SavingsAccount::display(std::ostream& out) const{
        out << "Account type: Savings" << '\n';
        out.setf(ios::fixed);
        out.precision(2);
        out << "Balance: $" << Account::balance() << '\n';
        out << "Interest Rate (%): " << m_interestRate * 100 << '\n'; 
        out.unsetf(ios::fixed);
        out.precision(6);
    };

}